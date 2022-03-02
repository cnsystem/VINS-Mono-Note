#pragma once

#include <cstdio>
#include <iostream>
#include <queue>
#include <execinfo.h>
#include <csignal>

#include <opencv2/opencv.hpp>
#include <eigen3/Eigen/Dense>

#include "camodocal/camera_models/CameraFactory.h"
#include "camodocal/camera_models/CataCamera.h"
#include "camodocal/camera_models/PinholeCamera.h"

#include "parameters.h"
#include "tic_toc.h"

using namespace std;
using namespace camodocal;
using namespace Eigen;

bool inBorder(const cv::Point2f &pt);

void reduceVector(vector<cv::Point2f> &v, vector<uchar> status);
void reduceVector(vector<int> &v, vector<uchar> status);

/**
* @class FeatureTracker
* @Description �Ӿ�ǰ��Ԥ������ÿ��������нǵ�LK��������
*/
class FeatureTracker
{
  public:
    FeatureTracker();

    void readImage(const cv::Mat &_img,double _cur_time);

    void setMask();

    void addPoints();

    bool updateID(unsigned int i);

    void readIntrinsicParameter(const string &calib_file);

    void showUndistortion(const string &name);

    void rejectWithF();

    void undistortedPoints();

    cv::Mat mask;//ͼ������
    cv::Mat fisheye_mask;//�������mask������ȥ����Ե���

    // prev_img����һ�η�����֡��ͼ������
    // cur_img�ǹ������ٵ�ǰһ֡��ͼ������
    // forw_img�ǹ������ٵĺ�һ֡��ͼ������
    cv::Mat prev_img, cur_img, forw_img;

    vector<cv::Point2f> n_pts;//ÿһ֡������ȡ��������

    vector<cv::Point2f> prev_pts, cur_pts, forw_pts;

    vector<cv::Point2f> prev_un_pts, cur_un_pts;//��һ���������ϵ�µ�����
    
    vector<cv::Point2f> pts_velocity;//��ǰ֡���ǰһ֡��������x,y����������ƶ��ٶ�

    vector<int> ids;//�ܹ������ٵ����������id

    vector<int> track_cnt;//��ǰ֡forw_img��ÿ�������㱻׷�ٵ�ʱ�����

    map<int, cv::Point2f> cur_un_pts_map;
    map<int, cv::Point2f> prev_un_pts_map;

    camodocal::CameraPtr m_camera;//���ģ��

    double cur_time;
    double prev_time;

    static int n_id;//������id��ÿ��⵽һ���µ������㣬�ͽ�n_id��Ϊ���������id��Ȼ��n_id��1
};
