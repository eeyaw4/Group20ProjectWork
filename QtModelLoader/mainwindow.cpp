/** @file
* This file contains the declarations of all functionsused in main.cpp.
*/
/** \brief Mainwindow
* This file handles all functions used by the UI interactions and the VTK display
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
  * Constructor
  * Initialises the VTK components and the UI
  */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
        ui->setupUi( this );

        renderer = vtkSmartPointer<vtkRenderer>::New();
        colours = vtkSmartPointer<vtkNamedColors>::New();

        // Now need to create a VTK render window and link it to the QtVTK widget
        ui->qvtkWidget->SetRenderWindow( renderWindow );

        ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );

        renderer->SetBackground( colours->GetColor3d("Silver").GetData() );

        planeLeft = vtkSmartPointer<vtkPlane>::New();
        planeLeft->SetOrigin(1000.0, 0.0, 0.0);
        planeLeft->SetNormal(-1.0, 0.0, 0.0);

        buttonsOff();

        // Setup the renderers's camera
        renderer->ResetCamera();
        renderer->GetActiveCamera()->Azimuth(-10);
        renderer->GetActiveCamera()->Elevation(-20);
}

/**
 * Deconstructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Load a model from the proprietry format
 */
void MainWindow::loadModel(string fileName)
{
    Model Data;

        try
        {
            Data.readFile(fileName);
        }
        catch(string& error)
        {
            QMessageBox::critical(this,tr("Error"),tr(error.c_str()));
            return;
    }


    for (int i = 0; i < Data.cVector.size(); i++)
    {
        Data.getCellData(i);
        string shape = Data.cellShape;
        vector<vector<float>> points = Data.cellVector;

        Data.getMaterialData(Data.cellMaterial);
        vector<float> c;
        ui->lblMat->setText(QString::fromStdString(Data.materialName));
        ui->lblDensValue->setText(QString::number(Data.materialDensity));
        ui->lblWeightValue->setText(QString::number(Data.getModelWeight()));

        try
        {
            c = getRGB(Data.materialColour);
        }
        catch(string& error)
        {

            QMessageBox::critical(this,tr("Error"),tr(error.c_str()));
            return;
        }

        if(shape == "p")
        {
            PyramidRender(points,c);
        }
        else if(shape == "t")
        {
            TetRender(points,c);
        }
        else if(shape == "h")
        {
            HexRender(points,c);
        }

        shapeColours.push_back(c);
    }

    int count = 0;

    for(vtkSmartPointer<vtkActor> l : actors)
    {
        renderer->AddActor(l);
        count++;
    }

    buttonsOn();
    ui->lblObjCount->setText(QString::number(count));

    renderer->ResetCamera();

    ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * load a model from an STL format
 */
void MainWindow::stlRender(QString fileName)
{
      reader->SetFileName(fileName.toLatin1().data());
      reader->Update();

      // Visualize
      vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
      mapper->SetInputConnection(reader->GetOutputPort());

      vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
      actor->SetMapper(mapper);

      vector<float> c = {0,0,0};
      shapeColours.push_back(c);

      actor->GetProperty()->SetColor( colourR,colourG,colourB );

      // Add the actor to the scene
      actors.push_back(actor);

      int count = 0;

      for(vtkSmartPointer<vtkActor> l : actors)
      {
          renderer->AddActor(l);
          count++;
      }

      buttonsOn();
      ui->lblObjCount->setText(QString::number(count));

      ui->lblMat->setText(" ");
      ui->lblDensValue->setText(" ");
      ui->lblWeightValue->setText(" ");
      ui->checkShrink->setEnabled(false);
      ui->checkShrink->setChecked(false);
      ui->checkBoxClip->setEnabled(false);
      ui->checkBoxClip->setChecked(false);

      renderer->ResetCamera();

      ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * Displays pyramid from vectors
 * @param pos - a 2d vector array storing the XYZ coordinates of each point in the shape
 * @param c - stores Cell data
 */
void MainWindow::PyramidRender(vector<vector<float>> pos,vector<float> c)
{
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

    for(vector<float> i : pos)
    {
        points->InsertNextPoint(i[0],i[1],i[2]);
    }

    vtkSmartPointer<vtkPyramid> pyramid = vtkSmartPointer<vtkPyramid>::New();
    pyramid->GetPointIds()->SetId(0,0);
    pyramid->GetPointIds()->SetId(1,1);
    pyramid->GetPointIds()->SetId(2,2);
    pyramid->GetPointIds()->SetId(3,3);
    pyramid->GetPointIds()->SetId(4,4);

    vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
    cells->InsertNextCell (pyramid);

    vtkSmartPointer<vtkUnstructuredGrid> uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    uGrid->SetPoints(points);
    uGrid->InsertNextCell(pyramid->GetCellType(),pyramid->GetPointIds());

    // Create a mapper that will hold the geometry in a format suitable for rendering
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputData(uGrid);

    vtkSmartPointer<vtkShrinkFilter> shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
    shrinkFilter->SetShrinkFactor(1);
    shrinkFilter->AddInputDataObject(0,uGrid);
    shrinks.push_back(shrinkFilter);

    vtkSmartPointer<vtkClipDataSet> clipFilter = vtkSmartPointer<vtkClipDataSet>::New();
    clipFilter->SetInputConnection( shrinkFilter->GetOutputPort() ) ;
    clipFilter->SetClipFunction( planeLeft.Get() );
    clipFilters.push_back(clipFilter);

    mapper->SetInputConnection( clipFilter->GetOutputPort());

    // Create an actor that is used to set the properties for rendering and place it in the window
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    actor->GetProperty()->SetColor( colourR,colourG,colourB );

    // Add the actor to the scene
    actors.push_back(actor);
}

/**
 * Displays Tetrahedron from vectors
 * @param pos - a 2d vector array storing the XYZ coordinates of each point in the shape
 * @param c - stores Cell data
 */
void MainWindow::TetRender(vector<vector<float>> pos,vector<float> c)
{
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

    for(vector<float> i : pos)
    {
        points->InsertNextPoint(i[0],i[1],i[2]);
    }

    // Method 1
    vtkSmartPointer<vtkUnstructuredGrid> uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
    uGrid->SetPoints(points);

    vtkIdType ptIds[] = {0, 1, 2, 3};
    uGrid->InsertNextCell( VTK_TETRA, 4, ptIds );

    // Create a mapper1 that will hold the geometry in a format suitable for rendering
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputData(uGrid);

    vtkSmartPointer<vtkShrinkFilter> shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
    shrinkFilter->SetShrinkFactor(1);
    shrinkFilter->AddInputDataObject(0,uGrid);
    shrinks.push_back(shrinkFilter);

    vtkSmartPointer<vtkClipDataSet> clipFilter = vtkSmartPointer<vtkClipDataSet>::New();
    clipFilter->SetInputConnection( shrinkFilter->GetOutputPort() ) ;
    clipFilter->SetClipFunction( planeLeft.Get() );
    clipFilters.push_back(clipFilter);

    mapper->SetInputConnection( clipFilter->GetOutputPort());

    // Create an actor that is used to set the properties for rendering and place it in the window
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    actor->GetProperty()->SetColor( colourR,colourG,colourB );

    // Add the actor to the scene
    actors.push_back(actor);
}

/**
 * Displays Hexahedron from vectors
 * @param pos - a 2d vector array storing the XYZ coordinates of each point in the shape
 * @param c - stores Cell data
 */
void MainWindow::HexRender(vector<vector<float>> pos,vector<float> c)
{
      // Create the points.
      vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

      // Create a hexahedron from the points.
      vtkSmartPointer<vtkHexahedron> hex = vtkSmartPointer<vtkHexahedron>::New();

      for(vector<float> i : pos)
      {
          points->InsertNextPoint(i[0],i[1],i[2]);
      }

      hex->GetPointIds()->SetId(0, 0);
      hex->GetPointIds()->SetId(1, 1);
      hex->GetPointIds()->SetId(2, 2);
      hex->GetPointIds()->SetId(3, 3);
      hex->GetPointIds()->SetId(4, 4);
      hex->GetPointIds()->SetId(5, 5);
      hex->GetPointIds()->SetId(6, 6);
      hex->GetPointIds()->SetId(7, 7);

      // Add the hexahedron to a cell array.
      vtkSmartPointer<vtkCellArray> hexs = vtkSmartPointer<vtkCellArray>::New();
      hexs->InsertNextCell(hex);

      // Add the points and hexahedron to an unstructured grid.
      vtkSmartPointer<vtkUnstructuredGrid> uGrid = vtkSmartPointer<vtkUnstructuredGrid>::New();
      uGrid->SetPoints(points);
      uGrid->InsertNextCell(hex->GetCellType(), hex->GetPointIds());

      // Visualize.
      vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
      mapper->SetInputData(uGrid);

      vtkSmartPointer<vtkShrinkFilter> shrinkFilter = vtkSmartPointer<vtkShrinkFilter>::New();
      shrinkFilter->SetShrinkFactor(1);
      shrinkFilter->AddInputDataObject(0,uGrid);
      shrinks.push_back(shrinkFilter);

      vtkSmartPointer<vtkClipDataSet> clipFilter = vtkSmartPointer<vtkClipDataSet>::New();
      clipFilter->SetInputConnection( shrinkFilter->GetOutputPort() ) ;
      clipFilter->SetClipFunction( planeLeft.Get() );
      clipFilters.push_back(clipFilter);

      mapper->SetInputConnection( clipFilter->GetOutputPort());

      vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
      actor->SetMapper(mapper);

      actor->GetProperty()->SetColor( colourR,colourG,colourB );

      // Add the actor to the scene
      actors.push_back(actor);
}

/**
 * Fetches the RGB values of a colour
 * @param c - Colour of the material of the model
 * @return - returns colour value
 */
vector<float> MainWindow::getRGB(string c)
{
    vector<float> RGB;

    regex pattern("#?([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})");
    smatch match;
    if(regex_match(c, match, pattern))
    {
        float r = stoul(match[1].str(), nullptr, 16);
        float g = stoul(match[2].str(), nullptr, 16);
        float b = stoul(match[3].str(), nullptr, 16);

        RGB.push_back(r/255.0);
        RGB.push_back(g/255.0);
        RGB.push_back(b/255.0);

        return RGB;
    }
    else
    {
        throw string("Error reading materials\nPlease check model file and reload");
    }

}

/**
 * Resets colours to default value
 * Either material colours or default value
 */
void MainWindow::resetColours(void)
{
    ui->spinR->setValue(0);
    ui->spinG->setValue(0);
    ui->spinB->setValue(0);

    ui->slideR->setValue(0);
    ui->slideG->setValue(0);
    ui->slideB->setValue(0);

    colourR = 0;
    colourG = 0;
    colourB = 0;

    for (int i = 0; i < actors.size(); i++)
    {
        vector<float> c = shapeColours[i];
        actors[i]->GetProperty()->SetColor( c[0],c[1],c[2] );
    }
    renderer->SetBackground( colours->GetColor3d("Silver").GetData() );
    ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * Applies shrink filter
 * @param value - %age based value of intensity of the filter
 */
void MainWindow::shrinkFilterUpdate(int value)
{
        for(int i = 0;i < shrinks.size();i++)
        {
            shrinks[i]->SetShrinkFactor((float) (100 - value)/100);
            ui->lblShrink->setNum((float) (100 - value)/100);
            shrinks[i]->Update();
        }
        ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * @brief Allows aspects of the UI to be interacted with
 */
void MainWindow::buttonsOn(void)
{
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(1, true);
    ui->tabWidget->setTabEnabled(2, true);
    ui->tabWidget->setTabEnabled(3, true);

    ui->slideShrink->setEnabled(false);
    ui->slideShrink->setValue(0);

    ui->checkShrink->setEnabled(true);
    ui->checkShrink->setChecked(false);

    ui->lblShrink->setNum(1);

    ui->sliderClipX->setEnabled(false);
    ui->sliderClipY->setEnabled(false);
    ui->sliderClipZ->setEnabled(false);
    ui->sliderClipX->setValue(0);
    ui->sliderClipY->setValue(0);
    ui->sliderClipZ->setValue(0);

    ui->spinBoxClipX->setEnabled(false);
    ui->spinBoxClipY->setEnabled(false);
    ui->spinBoxClipZ->setEnabled(false);
    ui->spinBoxClipX->setValue(0);
    ui->spinBoxClipY->setValue(0);
    ui->spinBoxClipZ->setValue(0);

    ui->checkBoxClip->setEnabled(true);
    ui->checkBoxClip->setChecked(false);

    ui->actionFileSave->setEnabled(true);
    ui->actionInformation->setEnabled(true);
    ui->actionCross->setEnabled(true);
    ui->menuColour->setEnabled(true);
    ui->menuFilters->setEnabled(true);
}

/**
 * @brief Prevents aspects of the UI to be interacted with
 */
void MainWindow::buttonsOff(void)
{
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabEnabled(1, false);
    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setTabEnabled(3, false);

    ui->slideShrink->setEnabled(false);
    ui->slideShrink->setValue(0);

    ui->checkShrink->setEnabled(false);
    ui->checkShrink->setChecked(false);

    ui->lblShrink->setNum(1);

    ui->sliderClipX->setEnabled(false);
    ui->sliderClipY->setEnabled(false);
    ui->sliderClipZ->setEnabled(false);
    ui->sliderClipX->setValue(0);
    ui->sliderClipY->setValue(0);
    ui->sliderClipZ->setValue(0);

    ui->spinBoxClipX->setEnabled(false);
    ui->spinBoxClipY->setEnabled(false);
    ui->spinBoxClipZ->setEnabled(false);
    ui->spinBoxClipX->setValue(0);
    ui->spinBoxClipY->setValue(0);
    ui->spinBoxClipZ->setValue(0);

    ui->checkBoxClip->setEnabled(false);
    ui->checkBoxClip->setChecked(false);

    ui->actionFileSave->setEnabled(false);
    ui->actionInformation->setEnabled(false);
    ui->actionCross->setEnabled(false);
    ui->menuColour->setEnabled(false);
    ui->menuFilters->setEnabled(false);
}

/**
 * @brief Changes colour of model when slider is changed
 * @param position - 0-255 value of red
 */
void MainWindow::on_slideR_valueChanged(int position)
{
    colourR = float(position)/100;
    ui->spinR->setValue(position);
    for(vtkSmartPointer<vtkActor> l : actors)
    {
        l->GetProperty()->SetColor( colourR,colourG,colourB );
    }

    ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * @brief Changes colour of model when slider is changed
 * @param position - 0-255 value of green
 */
void MainWindow::on_slideG_valueChanged(int position)
{
    colourG = float(position)/100;
    ui->spinG->setValue(position);
    for(vtkSmartPointer<vtkActor> l : actors)
    {
        l->GetProperty()->SetColor( colourR,colourG,colourB );
    }
    ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * @brief Changes colour of model when slider is changed
 * @param position - 0-255 value of blue
 */
void MainWindow::on_slideB_valueChanged(int position)
{
    colourB = float(position)/100;
    ui->spinB->setValue(position);

    for(vtkSmartPointer<vtkActor> l : actors)
    {
        l->GetProperty()->SetColor( colourR,colourG,colourB );
    }
    ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * @brief Opens dialog box to search for STL file and loads it
 */
void MainWindow::on_loadSTLButton_clicked()
{
    for(vtkSmartPointer<vtkActor> l : actors)
    {
        renderer->RemoveActor(l);
    }

    actors.clear();
    shapeColours.clear();
    shrinks.clear();

    modFileLoaded = false;

    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "./", tr("STL Files(*.stl)"));

    if(file == NULL)
    {
        return;
    }

    stlRender(file);

    resetColours();
}

/**
 * @brief Opens dialog box to search for proprietry model file and loads it
 */
void MainWindow::on_loadModelButton_clicked()
{
    for(vtkSmartPointer<vtkActor> l : actors)
    {
        renderer->RemoveActor(l);
    }

    actors.clear();
    shapeColours.clear();
    shrinks.clear();

    modFileLoaded = false;

    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "./", tr("Model Files(*.mod)"));

    if(path == NULL)
    {
        return;
    }

    modelFile = path.toStdString();

    loadModel(modelFile);

    resetColours();

    modFileLoaded = true;
}

/**
 * @brief Restores default colours when button is clicked
 */
void MainWindow::on_resetColourButton_clicked()
{
    resetColours();
}

/**
 * @brief Changes colour of model when text box is changed
 * @param value - 0-255 value of red
 */
void MainWindow::on_spinR_valueChanged(int value)
{
    ui->slideR->setValue(value);
    colourR = float(value)/100;

    for(vtkSmartPointer<vtkActor> l : actors)
    {
        l->GetProperty()->SetColor( colourR,colourG,colourB );
    }
    ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * @brief Changes colour of model when text box is changed
 * @param value - 0-255 value of green
 */
void MainWindow::on_spinG_valueChanged(int value)
{
    ui->slideG->setValue(value);
    colourG = float(value)/100;

    for(vtkSmartPointer<vtkActor> l : actors)
    {
        l->GetProperty()->SetColor( colourR,colourG,colourB );
    }
    ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * @brief Changes colour of model when text box is changed
 * @param value - 0-255 value of blue
 */
void MainWindow::on_spinB_valueChanged(int value)
{
    ui->slideB->setValue(value);
    colourB = float(value)/100;

    for(vtkSmartPointer<vtkActor> l : actors)
    {
        l->GetProperty()->SetColor( colourR,colourG,colourB );
    }
    ui->qvtkWidget->GetRenderWindow()->Render();
}

/**
 * @brief Changes colour of model based on a pop-out window selector
 */
void MainWindow::on_btnModelColour_clicked()
{
    QColor color = QColorDialog::getColor(Qt::green,this);

        if(color.isValid()) {
            int red, blue, green;
            color.getRgb(&red, &green, &blue);
            colourR = (float)(red / 100);
            colourG = (float)(green / 100);
            colourB = (float)(blue / 100);

            ui->slideR->setValue(red);
            ui->slideG->setValue(green);
            ui->slideB->setValue(blue);

            for(vtkSmartPointer<vtkActor> l : actors)
            {
                l->GetProperty()->SetColor( colourR,colourG,colourB );
            }
            ui->qvtkWidget->GetRenderWindow()->Render();
        }
}

/**
 * @brief Changes colour of Background based on pop-out window selector
 */
void MainWindow::on_btnBGColour_clicked()
{
    QColor color = QColorDialog::getColor(Qt::green,this);

        if(color.isValid())
        {
            int red, blue, green;
            color.getRgb(&red, &green, &blue);
            renderer->SetBackground((float)(red / 100),(float)(green / 100),(float)(blue / 100));
            ui->qvtkWidget->GetRenderWindow()->Render();
        }
}

/**
 * @brief Toggles use of shrink filter from a check box
 * @param arg1 - State of checkbox
 */
void MainWindow::on_checkShrink_stateChanged(int arg1)
{
    ui->slideShrink->setValue(0);
    ui->lblShrink->setNum(0);
    shrinkFilterUpdate(0);
    if(ui->checkShrink->isChecked() == false)
    {
        ui->slideShrink->setEnabled(false);
    }
    else if(ui->checkShrink->isChecked() == true)
    {
        ui->slideShrink->setEnabled(true);
    }
}

/**
 * @brief Applies %age of shrink filter based on slider value
 */
void MainWindow::on_slideShrink_sliderReleased()
{
    shrinkFilterUpdate(ui->slideShrink->value());
}

void MainWindow::on_checkBoxClip_stateChanged(int arg1)
{
    ui->spinBoxClipX->setValue(0);
    ui->spinBoxClipY->setValue(0);
    ui->spinBoxClipZ->setValue(0);
    ui->sliderClipX->setValue(0);
    ui->sliderClipY->setValue(0);
    ui->sliderClipZ->setValue(0);

    //ClippingFilterUpdate(0);
    if(ui->checkBoxClip->isChecked() == false)
    {
        ui->sliderClipX->setEnabled(false);
        ui->sliderClipY->setEnabled(false);
        ui->sliderClipZ->setEnabled(false);
        ui->spinBoxClipX->setEnabled(false);
        ui->spinBoxClipY->setEnabled(false);
        ui->spinBoxClipZ->setEnabled(false);
    }
    else if(ui->checkBoxClip->isChecked() == true)
    {
        ui->sliderClipX->setEnabled(true);
        ui->sliderClipY->setEnabled(true);
        ui->sliderClipZ->setEnabled(true);
        ui->spinBoxClipX->setEnabled(true);
        ui->spinBoxClipY->setEnabled(true);
        ui->spinBoxClipZ->setEnabled(true);
    }
}

void MainWindow::clipFilterUpdate(int x,int y,int z)
{
    ui->spinBoxClipX->setValue(x);
    ui->spinBoxClipY->setValue(y);
    ui->spinBoxClipZ->setValue(z);
    ui->sliderClipX->setValue(x);
    ui->sliderClipY->setValue(y);
    ui->sliderClipZ->setValue(z);

    if(x != 0)
    {
        planeLeft->SetNormal(-1.0, 0.0, 0.0);
    }
    else if(y != 0)
    {
        planeLeft->SetNormal(0.0, -1.0, 0.0);
    }
    else if(z != 0)
    {
        planeLeft->SetNormal(0.0, 0.0, -1.0);
    }

    float positionX = (100 - x - 50.0);
    float positionY = (100 - y - 50.0);
    float positionZ = (100 - z - 50.0);

    float planePositionX = (positionX/100.0) * 2;
    float planePositionY = (positionY/100.0) * 2;
    float planePositionZ = (positionZ/100.0) * 2;

    planeLeft->SetOrigin(planePositionX, planePositionY, planePositionZ);

    for(int i = 0;i < clipFilters.size();i++)
    {
        clipFilters[i]->Update();
    }
    ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_sliderClipX_sliderMoved(int position)
{
    clipFilterUpdate(position,(float)0,(float)0);
}

void MainWindow::on_sliderClipY_sliderMoved(int position)
{
    clipFilterUpdate((float)0,position,(float)0);
}

void MainWindow::on_sliderClipZ_sliderMoved(int position)
{
    clipFilterUpdate((float)0,(float)0,position);
}

void MainWindow::on_spinBoxClipX_valueChanged(int value)
{
    clipFilterUpdate(value,(float)0,(float)0);
}

void MainWindow::on_spinBoxClipY_valueChanged(int value)
{
    clipFilterUpdate((float)0,value,(float)0);
}

void MainWindow::on_spinBoxClipZ_valueChanged(int value)
{
    clipFilterUpdate((float)0,(float)0,value);
}

void MainWindow::on_actionLoad_STL_File_triggered()
{
    on_loadSTLButton_clicked();
}

void MainWindow::on_actionLoad_Model_File_triggered()
{
    on_loadModelButton_clicked();
}

void MainWindow::on_actionFileSave_triggered()
{
    if(modFileLoaded == false)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Model Not Found","Please load a MOD model");
        messageBox.setFixedSize(500,200);
        return;
    }

    QString file = QFileDialog::getSaveFileName(this, tr("Save As File"), "./", tr("MOD Files(*.mod)"));

    if(file == NULL)
    {
        return;
    }

    Model Data;

    try
    {
        Data.readFile(modelFile);
    }
    catch(string& error)
    {
        QMessageBox::critical(this,tr("Error"),tr(error.c_str()));
        return;
    }

    string fileName = file.toUtf8().constData();
    Data.writeToFile(fileName);
}

void MainWindow::on_actionInformation_triggered()
{
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_actionModel_Colour_triggered()
{
    ui->tabWidget->setCurrentIndex(1);
    on_btnModelColour_clicked();
}

void MainWindow::on_actionBackground_Colour_triggered()
{
    ui->tabWidget->setCurrentIndex(1);
    on_btnBGColour_clicked();
}

void MainWindow::on_actionCross_triggered()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_actionShrink_Filter_triggered()
{
    ui->tabWidget->setCurrentIndex(3);
}
