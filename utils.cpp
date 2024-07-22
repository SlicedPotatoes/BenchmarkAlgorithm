#include "utils.h"
#include "Algorithm/Algorithm.h"
#include "TestCase.h"

void printPerformanceStats(const std::vector<double> &times, const std::string &algoName)
{
    if (times.empty())
    {
        std::cout << algoName << " - No data\n";
        return;
    }

    double sum = std::accumulate(times.begin(), times.end(), 0.0);
    double mean = sum / times.size();

    auto minmax = std::minmax_element(times.begin(), times.end());
    double min = *minmax.first;
    double max = *minmax.second;

    std::vector<double> sortedTimes(times);
    std::sort(sortedTimes.begin(), sortedTimes.end());
    double median = sortedTimes.size() % 2 == 0
                        ? (sortedTimes[sortedTimes.size() / 2 - 1] + sortedTimes[sortedTimes.size() / 2]) / 2.0
                        : sortedTimes[sortedTimes.size() / 2];

    std::cout << algoName << " - Mean: " << formatDuration(mean) << ", Min: " << formatDuration(min)
              << ", Max: " << formatDuration(max) << ", Median: " << formatDuration(median)
              << ", Total: " << formatDuration(sum) << '\n';
}

std::string formatDuration(double seconds)
{
    std::ostringstream oss;
    if (seconds < 1e-6)
    {
        oss << std::fixed << std::setprecision(3) << seconds * 1e9 << " ns";
    }
    else if (seconds < 1e-3)
    {
        oss << std::fixed << std::setprecision(3) << seconds * 1e6 << " µs";
    }
    else if (seconds < 1)
    {
        oss << std::fixed << std::setprecision(3) << seconds * 1e3 << " ms";
    }
    else
    {
        oss << std::fixed << std::setprecision(3) << seconds << " s";
    }
    return oss.str();
}