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
    /// 计时开始
    /// </summary>
    void tic()
    {
        start = std::chrono::system_clock::now();
    }

    /// <summary>
    /// 耗时统计
    /// </summary>
    /// <returns>耗时，单位为毫秒</returns>
    double toc()
    {
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        return elapsed_seconds.count() * 1000;
    }

  private:
    std::chrono::time_point<std::chrono::system_clock> start, end;
};
