#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <vector>

template <typename InputType, typename OutputType> class Algorithm
{
  protected:
    std::string name;
    std::vector<double> times;

  public:
    Algorithm(std::string name);
    virtual OutputType run(const InputType &data) = 0;
    virtual std::string getName();
    virtual std::vector<double> getTimes();
    virtual void insertTime(double t);
    virtual ~Algorithm() = default;
};

#include "Algorithm.cpp"

#include "AlgorithmA.cpp"
#include "AlgorithmB.cpp"
#include "AlgorithmC.cpp"
#include "AlgorithmD.cpp"
#include "AlgorithmE.cpp"

#endif // ALGORITHM_H