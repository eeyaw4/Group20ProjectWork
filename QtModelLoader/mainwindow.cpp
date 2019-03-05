#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
        ui->setupUi( this );

        renderer = vtkSmartPointer<vtkRenderer>::New();
        colors = vtkSmartPointer<vtkNamedColors>::New();

        // Now need to create a VTK render window and link it to the QtVTK widget
        ui->qvtkWidget->SetRenderWindow( renderWindow );

        ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );

        renderer->SetBackground( colors->GetColor3d("Silver").GetData() );

        // Setup the renderers's camera
        renderer->ResetCamera();
        renderer->GetActiveCamera()->Azimuth(-10);
        renderer->GetActiveCamera()->Elevation(-20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
            PyramidRender(points);
        }
        else if(shape == "t")
        {
            TetRender(points);
        }
        else if(shape == "h")
        {
            HexRender(points);
        }
    }

    int count = 0;

       for(vtkSmartPointer<vtkActor> l : actors)
    {
        renderer->AddActor(l);
        count++;
    }

    ui->lblObjCount->setText(QString::number(count));
    ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::stlRender(QString fileName)
{
      vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
      reader->SetFileName(fileName.toLatin1().data());
      reader->Update();

      // Visualize
      vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
      mapper->SetInputConnection(reader->GetOutputPort());

      vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
      actor->SetMapper(mapper);

      actor->GetProperty()->SetColor( colourR,colourG,colourB );

      // Add the actor to the scene
      actors.push_back(actor);

      int count = 0;

      for(vtkSmartPointer<vtkActor> l : actors)
      {
          renderer->AddActor(l);
          count++;
      }

      ui->lblObjCount->setText(QString::number(count));
      ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::PyramidRender(vector<vector<float>> pos)
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

    vtkSmartPointer<vtkUnstructuredGrid> ug = vtkSmartPointer<vtkUnstructuredGrid>::New();
    ug->SetPoints(points);
    ug->InsertNextCell(pyramid->GetCellType(),pyramid->GetPointIds());

    // Create a mapper that will hold the geometry in a format suitable for rendering
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
     mapper->SetInputData(ug);

    // Create an actor that is used to set the properties for rendering and place it in the window
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();

    actor->GetProperty()->SetColor( colourR,colourG,colourB );

    // Add the actor to the scene
    actors.push_back(actor);
}

void MainWindow::TetRender(vector<vector<float>> pos)
{
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();

    for(vector<float> i : pos)
    {
        points->InsertNextPoint(i[0],i[1],i[2]);
    }

    // Method 1
    vtkSmartPointer<vtkUnstructuredGrid> unstructuredGrid1 = vtkSmartPointer<vtkUnstructuredGrid>::New();
    unstructuredGrid1->SetPoints(points);

    vtkIdType ptIds[] = {0, 1, 2, 3};
    unstructuredGrid1->InsertNextCell( VTK_TETRA, 4, ptIds );

    // Create a mapper1 that will hold the geometry in a format suitable for rendering
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputData(unstructuredGrid1);

    // Create an actor that is used to set the properties for rendering and place it in the window
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->EdgeVisibilityOn();

    actor->GetProperty()->SetColor( colourR,colourG,colourB );

    // Add the actor to the scene
    actors.push_back(actor);
}

void MainWindow::HexRender(vector<vector<float>> pos)
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

      vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
      actor->SetMapper(mapper);
      actor->GetProperty()->EdgeVisibilityOn();

      actor->GetProperty()->SetColor( colourR,colourG,colourB );

      // Add the actor to the scene
      actors.push_back(actor);
}

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

void MainWindow::resetColors(void)
{
    ui->slideR->setValue(0);
    ui->slideG->setValue(0);
    ui->slideB->setValue(0);

    colourR = 0;
    colourG = 0;
    colourB = 0;

    for(vtkSmartPointer<vtkActor> l : actors)
    {
        l->GetProperty()->SetColor( colourR,colourG,colourB );
    }
    ui->qvtkWidget->GetRenderWindow()->Render();
}

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

void MainWindow::on_loadSTLButton_clicked()
{
    for(vtkSmartPointer<vtkActor> l : actors)
    {
        renderer->RemoveActor(l);
    }

    actors.clear();

    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "./", tr("STL Files(*.stl)"));

    if(file == NULL)
    {
        return;
    }

    stlRender(file);

    resetColors();
}

void MainWindow::on_loadModelButton_clicked()
{
    for(vtkSmartPointer<vtkActor> l : actors)
    {
        renderer->RemoveActor(l);
    }

    actors.clear();

    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "./", tr("Model Files(*.mod)"));

    if(path == NULL)
    {
        return;
    }

    string file = path.toStdString();

    loadModel(file);

    resetColors();
}

void MainWindow::on_resetColorButton_clicked()
{
    resetColors();
}

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
