#pragma once

#include <ctime>
#include <cstdlib>
#include <chrono>

class TicToc
{
  public:
    TicToc()
    {
        tic();
    }
    
    /// <summary>
    /// ��ʱ��ʼ
    /// </summary>
    void tic()
    {
        start = std::chrono::system_clock::now();
    }

    /// <summary>
    /// ��ʱͳ��
    /// </summary>
    /// <returns>��ʱ����λΪ����</returns>
    double toc()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        return elapsed_seconds.count() * 1000;
    }

  private:
    std::chrono::time_point<std::chrono::system_clock> start, end;
};
