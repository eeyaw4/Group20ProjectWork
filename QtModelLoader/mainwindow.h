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
#include <vtkPlane.h>
#include <vtkClipDataSet.h>
#include <vtkShrinkFilter.h>

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <regex>

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>
#include <QPalette>
#include <QMessageBox>

#include <Model.h>
#include <Cell.h>
#include <Material.h>
#include <Vertex.h>

using namespace std;

namespace Ui {
class MainWindow;
}


/** Class containing Mainwindow settings, with values for global variables required by different functions
 * and aspects of the UI
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    vector<vtkSmartPointer<vtkActor>> actors;
    vector<vtkSmartPointer<vtkShrinkFilter>> shrinks;
    vector<vtkSmartPointer<vtkClipDataSet>> clipFilters;
    vtkSmartPointer<vtkNamedColors> colours;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    vtkSmartPointer<vtkPlane> planeLeft;

    vector<vector<float>> shapeColours;

    float colourR = 0;						/**< This holds the RGB value of red */
    float colourG = 0;                                          /**< This holds the RGB value of green */
    float colourB = 0;                                          /**< This holds the RGB value of blue */

    bool modFileLoaded = false;
    string modelFile;

    vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();


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

    void on_btnModelColour_clicked();

    void on_btnBGColour_clicked();

    void on_slideShrink_sliderReleased();

    void on_checkShrink_stateChanged(int arg1);

    void on_actionLoad_STL_File_triggered();

    void on_actionLoad_Model_File_triggered();

    void on_actionFileSave_triggered();

    void on_actionInformation_triggered();

    void on_actionModel_Colour_triggered();

    void on_actionBackground_Colour_triggered();

    void on_actionCross_triggered();

    void on_actionShrink_Filter_triggered();

    void on_checkBoxClip_stateChanged(int arg1);

    void on_sliderClipX_sliderMoved(int position);

    void on_sliderClipY_sliderMoved(int position);

    void on_sliderClipZ_sliderMoved(int position);

    void on_spinBoxClipX_valueChanged(int value);

    void on_spinBoxClipY_valueChanged(int value);

    void on_spinBoxClipZ_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    void PyramidRender(vector<vector<float>> position,vector<float> c);
    void TetRender(vector<vector<float>> pos,vector<float> c);
    void HexRender(vector<vector<float>> pos,vector<float> c);
    void stlRender(QString filename);
    void loadModel(string filename);
    void resetColours(void);
    void shrinkFilterUpdate(int value);
    void clipFilterUpdate(int x,int y,int z);
    vector<float> getRGB(string c);
    void buttonsOn(void);
    void buttonsOff(void);

};

#endif // MAINWINDOW_H
