#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <array>
#include <vector>

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

    ui->lineEditR->setText("0");
    ui->lineEditG->setText("0");
    ui->lineEditB->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadModel(string fileName)
{
    Model Data;

    Data.readFile(fileName);



    for (int i = 0; i < Data.cVector.size(); i++)
    {
        Data.getCellData(i);
        string shape = Data.cellShape;
        vector<vector<float>> points = Data.cellVector;

        Data.getMaterialData(Data.cellMaterial);
        vector<float> c = Data.materialRGB;

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

        shapeColors.push_back(c);
    }

       for(vtkSmartPointer<vtkActor> l : actors)
    {
        renderer->AddActor(l);
    }

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

      for(vtkSmartPointer<vtkActor> l : actors)
      {
          renderer->AddActor(l);
      }

      ui->qvtkWidget->GetRenderWindow()->Render();
}

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

void MainWindow::TetRender(vector<vector<float>> pos,vector<float> c)
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

      vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
      actor->SetMapper(mapper);
      actor->GetProperty()->EdgeVisibilityOn();

      actor->GetProperty()->SetColor( colourR,colourG,colourB );

      // Add the actor to the scene
      actors.push_back(actor);
}

void MainWindow::resetColors(void)
{
    ui->lineEditR->setText("0");
    ui->lineEditG->setText("0");
    ui->lineEditB->setText("0");

    ui->sliderR->setValue(0);
    ui->sliderG->setValue(0);
    ui->sliderB->setValue(0);

    colourR = 0;
    colourG = 0;
    colourB = 0;

    for (int i = 0; i < actors.size(); i++)
    {
        vector<float> c = shapeColors[i];
        actors[i]->GetProperty()->SetColor( c[0],c[1],c[2] );
    }
    ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_sliderR_valueChanged(int position)
{
    float num = position;
    colourR = ((num / 100) * 2.55);
    int display = qRound(colourR * 100);
    ui->lineEditR->setText(QString::number(display));

    for(vtkSmartPointer<vtkActor> l : actors)
    {
        l->GetProperty()->SetColor( colourR,colourG,colourB );
    }

    ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_sliderG_valueChanged(int position)
{
    float num = position;
    colourG = ((num / 100) * 2.55);
    int display = qRound(colourG * 100);
    ui->lineEditG->setText(QString::number(display));

    for(vtkSmartPointer<vtkActor> l : actors)
    {
        l->GetProperty()->SetColor( colourR,colourG,colourB );
    }
    ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_sliderB_valueChanged(int position)
{
    float num = position;
    colourB = ((num / 100) * 2.55);
    int display = qRound(colourB * 100);
    ui->lineEditB->setText(QString::number(display));

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
    shapeColors.clear();

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
    shapeColors.clear();

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
