#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkPolyData.h>
#include <vtkDataSetMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkPyramid.h>
#include <vtkTetra.h>
#include <vtkHexahedron.h>
#include <vtkUnstructuredGrid.h>
#include <vtkSTLReader.h>
#include <vtkPolyDataMapper.h>

#include <vector>
#include <string>
#include <iostream>

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

#include <Model.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    vector<vtkSmartPointer<vtkActor>> actors;
    vtkSmartPointer<vtkNamedColors> colors;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;

    vector<vector<float>> shapeColors;

    float colourR = 0;
    float colourG = 0;
    float colourB = 0;


private slots:
    void on_sliderR_valueChanged(int position);

    void on_sliderG_valueChanged(int position);

    void on_sliderB_valueChanged(int position);

    void on_loadSTLButton_clicked();

    void on_loadModelButton_clicked();

    void on_resetColorButton_clicked();

private:
    Ui::MainWindow *ui;
    void PyramidRender(vector<vector<float>> position,vector<float> c);
    void TetRender(vector<vector<float>> pos,vector<float> c);
    void HexRender(vector<vector<float>> pos,vector<float> c);
    void stlRender(QString filename);
    void loadModel(string filename);
    void resetColors(void);
};

#endif // MAINWINDOW_H
