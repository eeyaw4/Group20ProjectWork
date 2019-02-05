#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // standard call to setup Qt UI (same as previously)
    ui->setupUi( this );

        // Now need to create a VTK render window and link it to the QtVTK widget
        vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
        ui->qvtkWidget->SetRenderWindow( renderWindow );			// note that vtkWidget is the name I gave to my QtVTKOpenGLWidget in Qt creator

        // Now use the VTK libraries to render something. To start with you can copy-paste the cube example code, there are comments to show where the code must be modified.
        //--------------------------------------------- Code From Example 1 --------------------------------------------------------------------------
        // Create a cube using a vtkCubeSource
        vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();

        // Create a mapper that will hold the cube's geometry in a format suitable for rendering
        vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
        mapper->SetInputConnection( cubeSource->GetOutputPort() );

        // Create an actor that is used to set the cube's properties for rendering and place it in the window
        actor = vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
        actor->GetProperty()->EdgeVisibilityOn();

        colors = vtkSmartPointer<vtkNamedColors>::New();
        actor->GetProperty()->SetColor( colourR,colourG,colourB );

        // Create a renderer, and render window
        renderer = vtkSmartPointer<vtkRenderer>::New();
        //vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();		// ###### We've already created the renderWindow this time ######
        ui->qvtkWidget->GetRenderWindow()->AddRenderer( renderer );									// ###### ask the QtVTKOpenGLWidget for its renderWindow ######

        // Link a renderWindowInteractor to the renderer (this allows you to capture mouse movements etc)  ###### Not needed with Qt ######
        //vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
        //renderWindowInteractor->SetRenderWindow( ui->vtkWidget->GetRenderWindow() );

        // Add the actor to the scene
        renderer->AddActor(actor);
        renderer->SetBackground( colors->GetColor3d("Silver").GetData() );

        // Setup the renderers's camera
        renderer->ResetCamera();
        renderer->GetActiveCamera()->Azimuth(30);
        renderer->GetActiveCamera()->Elevation(30);
        renderer->ResetCameraClippingRange();

        ui->lineEditR->setText("0");
        ui->lineEditG->setText("0");
        ui->lineEditB->setText("0");

        // Render and interact
        //renderWindow->Render();					// ###### Not needed with Qt ######
        //renderWindowInteractor->Start();			// ###### Not needed with Qt ######
        //--------------------------------------------- /Code From Example 1 -------------------------------------------------------------------------*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sliderR_sliderMoved(int position)
{
    float num = position;
    colourR = ((num / 100) * 2.576);
    int display = qRound(colourR * 100);
    ui->lineEditR->setText(QString::number(display));

    actor->GetProperty()->SetColor( colourR,colourG,colourB );
    ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_sliderG_sliderMoved(int position)
{
    float num = position;
    colourG = ((num / 100) * 2.576);
    int display = qRound(colourG * 100);
    ui->lineEditG->setText(QString::number(display));

    actor->GetProperty()->SetColor( colourR,colourG,colourB );
    ui->qvtkWidget->GetRenderWindow()->Render();
}

void MainWindow::on_sliderB_sliderMoved(int position)
{
    float num = position;
    colourB = ((num / 100) * 2.576);
    int display = qRound(colourB * 100);
    ui->lineEditB->setText(QString::number(display));

    actor->GetProperty()->SetColor( colourR,colourG,colourB );
    ui->qvtkWidget->GetRenderWindow()->Render();
}
