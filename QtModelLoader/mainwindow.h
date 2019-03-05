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

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <regex>

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

#include <Model.h>
#include <Cell.h>
#include <Material.h>
#include <Vertex.h>

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
    vtkSmartPointer<vtkNamedColors> colours;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;

    vector<vector<float>> shapeColours;

    float colourR = 0;
    float colourG = 0;
    float colourB = 0;


private slots:
    void on_slideR_valueChanged(int position);

    void on_slideG_valueChanged(int position);

    void on_slideB_valueChanged(int position);

    void on_loadSTLButton_clicked();

    void on_loadModelButton_clicked();

    void on_resetColourButton_clicked();

    void on_spinR_valueChanged(int arg1);

    void on_spinG_valueChanged(int arg1);

    void on_spinB_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    void PyramidRender(vector<vector<float>> position,vector<float> c);
    void TetRender(vector<vector<float>> pos,vector<float> c);
    void HexRender(vector<vector<float>> pos,vector<float> c);
    void stlRender(QString filename);
    void loadModel(string filename);
    void resetColours(void);
    vector<float> getRGB(string c);
};

#endif // MAINWINDOW_H
