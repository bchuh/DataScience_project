#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QStackedLayout>
#include <vector>
#include <string>
#include <opencv2\opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "../DL_module/detector.h"
#include "../subwidget/subwidget.h"
#include "../Camera_module/camera_module.h"
#include "../DL_module/DL_module.h"

//连接cam模块步骤：1.项目右键, add existing directory, 选摄像头模块的文件夹
//2. 把上面的include路径改为你电脑上的camera_module.h的绝对路径

//#include <imgproc\types_c.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    subwidget* getmsubwindow();
    ~MainWindow();
    void run();
    void continue_run();
    QImage cropped_frame;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void select();

signals:
    void subwindowshow();
private:
    Ui::MainWindow* ui;
    QGraphicsPixmapItem* m_imageItem;
    Camera* cam;
    DLmodule* model;
    subwidget*subWindow;
    QList<QPushButton*> ButtonList;
    std::vector<Detection> result;
    int stop;
    bool isRunning=true;
    cv::Mat frame;
};


#endif // MAINWINDOW_H
