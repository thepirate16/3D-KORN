#ifndef TDK_SCANWINDOW_H
#define TDK_SCANWINDOW_H

// Include Qt headers
#include <QMainWindow>
#include <QGridLayout>
#include <QDockWidget>
#include <QScrollArea>

//Include PCL headers
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkRenderWindow.h>
#include <QVTKWidget.h>

#include "tdk_kinect2wrapper.h"

class TDK_ScanWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TDK_ScanWindow(QWidget *parent = 0);
    QWidget *centralWidget;
    QGridLayout *gridLayoutCentralWidget;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
//    pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloudSource1;
    TDK_Kinect2Wrapper *tdk_Kinect2Wrapper;
    QVTKWidget *qvtkWidget;

    void mf_SetupSensorOutputWidget();
    void mf_SetupSensorWidget();
    void mf_SetupVideoStreamWidget();
    void mf_SetupDepthMapWidget();
    void mf_SetupPointcloudListWidget();

signals:

public slots:
    void slotUpdateSensorOutputWidget(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& ptr);

};

#endif // TDK_SCANWINDOW_H
