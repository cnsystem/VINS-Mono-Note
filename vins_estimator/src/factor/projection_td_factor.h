#pragma once

#include <ros/assert.h>
#include <ceres/ceres.h>
#include <Eigen/Dense>
#include "../utility/utility.h"
#include "../utility/tic_toc.h"
#include "../parameters.h"

//��imu-camera ʱ�������ȫͬ���� Rolling shutter �����֧��
class ProjectionTdFactor : public ceres::SizedCostFunction<2, 7, 7, 7, 1, 1>
{
  public:
    ProjectionTdFactor(const Eigen::Vector3d &_pts_i, const Eigen::Vector3d &_pts_j,
    				   const Eigen::Vector2d &_velocity_i, const Eigen::Vector2d &_velocity_j,
    				   const double _td_i, const double _td_j, const double _row_i, const double _row_j);
    virtual bool Evaluate(double const *const *parameters, double *residuals, double **jacobians) const;
    void check(double **parameters);

    Eigen::Vector3d pts_i, pts_j;//�ǵ��ڹ�һ��ƽ�������
    Eigen::Vector3d velocity_i, velocity_j;//�ǵ��ڹ�һ��ƽ����ٶ�
    double td_i, td_j;//����IMU����ʱ�õ���ʱ��ͬ�����
    Eigen::Matrix<double, 2, 3> tangent_base;
    double row_i, row_j;//�ǵ�ͼ�������������
    static Eigen::Matrix2d sqrt_info;
    static double sum_t;
};
