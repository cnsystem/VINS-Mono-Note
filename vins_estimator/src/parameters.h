#pragma once

#include <ros/ros.h>
#include <vector>
#include <eigen3/Eigen/Dense>
#include "utility/utility.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/eigen.hpp>
#include <fstream>

const double FOCAL_LENGTH = 460.0;
const int WINDOW_SIZE = 10;
const int NUM_OF_CAM = 1;
const int NUM_OF_F = 1000;
//#define UNIT_SPHERE_ERROR

extern double INIT_DEPTH;//��ȳ�ʼֵ
extern double MIN_PARALLAX;//�ؼ�֡ѡ����ֵ�����ص�λ��
extern int ESTIMATE_EXTRINSIC;//IMU����������Rt:0׼ȷ��1��׼ȷ��2û��

//���ٶȼƺ����������������ƫ�ñ�׼��
extern double ACC_N, ACC_W;
extern double GYR_N, GYR_W;

extern std::vector<Eigen::Matrix3d> RIC;//�������IMU����ת����
extern std::vector<Eigen::Vector3d> TIC;//�������IMU��ƽ������
extern Eigen::Vector3d G;//����[0,0,g]

extern double BIAS_ACC_THRESHOLD;//Ba��ֵ
extern double BIAS_GYR_THRESHOLD;//Ba��ֵ
extern double SOLVER_TIME;//������ʱ�䣨�Ա�֤ʵʱ�ԣ�
extern int NUM_ITERATIONS;//�������������������Ա�֤ʵʱ�ԣ�
extern std::string EX_CALIB_RESULT_PATH;//�����IMU��ε����·��OUTPUT_PATH + "/extrinsic_parameter.csv"
extern std::string VINS_RESULT_PATH;//���·��OUTPUT_PATH + "/vins_result_no_loop.csv"
extern std::string IMU_TOPIC;//IMU topic��"/imu0"
extern double TD;//IMU��cam��ʱ���. unit: s. readed image clock + td = real image clock (IMU clock)
extern double TR;//��������ÿ֡ʱ��
extern int ESTIMATE_TD;//����У׼IMU��cameraʱ��
extern int ROLLING_SHUTTER;//1���������������0��ȫ�ֿ������
extern double ROW, COL;//ͼƬ�Ŀ�͸�


void readParameters(ros::NodeHandle &n);

enum SIZE_PARAMETERIZATION
{
    SIZE_POSE = 7,
    SIZE_SPEEDBIAS = 9,
    SIZE_FEATURE = 1
};

enum StateOrder
{
    O_P = 0,
    O_R = 3,
    O_V = 6,
    O_BA = 9,
    O_BG = 12
};

enum NoiseOrder
{
    O_AN = 0,
    O_GN = 3,
    O_AW = 6,
    O_GW = 9
};
