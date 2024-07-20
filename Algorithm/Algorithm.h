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

template <typename InputType, typename OutputType> class AlgorithmA : public Algorithm<InputType, OutputType>
{
  public:
    AlgorithmA(std::string name);
    OutputType run(const InputType &data) override;
};

template <typename InputType, typename OutputType> class AlgorithmB : public Algorithm<InputType, OutputType>
{
  public:
    AlgorithmB(std::string name);
    OutputType run(const InputType &data) override;
};

#include "Algorithm.cpp"
#include "AlgorithmA.cpp"
#include "AlgorithmB.cpp"

#endif // ALGORITHM_H