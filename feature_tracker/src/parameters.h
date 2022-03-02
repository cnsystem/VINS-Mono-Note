#pragma once
#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>

extern int ROW;//ͼ����
extern int COL;//ͼ��߶�
extern int FOCAL_LENGTH;//����
const int NUM_OF_CAM = 1;//����ĸ���


extern std::string IMAGE_TOPIC;//ͼ���ROS TOPIC
extern std::string IMU_TOPIC;//IMU��ROS TOPIC
extern std::string FISHEYE_MASK;//�������maskͼ��λ��
extern std::vector<std::string> CAM_NAMES;//������������ļ���
extern int MAX_CNT;//������������
extern int MIN_DIST;//������֮�����С���
extern int WINDOW_SIZE;
extern int FREQ;//����ͼ��������ٵ�Ƶ��
extern double F_THRESHOLD;//ransac�㷨������
extern int SHOW_TRACK;//�Ƿ񷢲����ٵ��ͼ��
extern int STEREO_TRACK;//˫Ŀ������Ϊ1
extern int EQUALIZE;//�����̫����̫����Ϊ1������ֱ��ͼ���⻯
extern int FISHEYE;//��������������Ϊ1
extern bool PUB_THIS_FRAME;//�Ƿ���Ҫ����������

void readParameters(ros::NodeHandle &n);
