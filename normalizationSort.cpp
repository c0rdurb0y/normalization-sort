#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <cmath>

using namespace std;
using namespace std::chrono;

std::vector<int> generateUniformData(int size, int minVal, int maxVal)
{
    std::vector<int> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(minVal, maxVal);

    for (int &val : data)
    {
        val = distr(gen);
    }

    return data;
}

std::vector<int> generateNormalData(int size, double mean, double stddev)
{
    std::vector<int> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> distr(mean, stddev);

    for (int &val : data)
    {
        val = static_cast<int>(distr(gen));
    }

    return data;
}

std::vector<int> generateParetoData(int size, double alpha)
{
    std::vector<int> data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(0.0, 1.0);

    for (int &val : data)
    {
        double u = distr(gen);
        val = static_cast<int>(std::pow(1 - u, -1.0 / alpha));
    }

    return data;
}

vector<int> normalizeSortRecursive(vector<int> &arr, int minVal, int maxVal)
{
    int n = arr.size();
    if (n <= 1 || minVal == maxVal)
        return arr;

    int rangeVal = maxVal - minVal;
    vector<vector<int>> buckets(n);

    for (int num : arr)
    {
        int normalizedPosition = ((long long)(num - minVal) * (n - 1)) / rangeVal;
        buckets[normalizedPosition].push_back(num);
    }

    vector<int> sortedArr;
    for (auto &bucket : buckets)
    {
        if (bucket.size() > 1)
        {
            auto bucketResult = normalizeSortRecursive(bucket, *min_element(bucket.begin(), bucket.end()), *max_element(bucket.begin(), bucket.end()));
            sortedArr.insert(sortedArr.end(), bucketResult.begin(), bucketResult.end());
        }
        else
        {
            sortedArr.insert(sortedArr.end(), bucket.begin(), bucket.end());
        }
    }
    return sortedArr;
}

vector<int> normalizeSortMain(vector<int> &arr)
{
    if (arr.size() <= 1)
        return arr;
    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());
    return normalizeSortRecursive(arr, minVal, maxVal);
}

int main()
{

    int dataSize = 160000000; // Size of the dataset
    std::vector<int> data4 = generateNormalData(dataSize, 50000, 20000);
    std::vector<int> data3 = generateNormalData(dataSize, 150000, 20000);
    std::vector<int> data2 = generateNormalData(dataSize, 30000, 10000);
    std::vector<int> data1 = generateNormalData(dataSize, 170000, 10000);

    // Timing the sort

    auto start1 = high_resolution_clock::now();
    vector<int> sortedData1 = normalizeSortMain(data1);
    auto stop1 = high_resolution_clock::now();
    // Calculate duration
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    cout << "Time taken by function: " << float(duration1.count() / float(1000000)) << " seconds" << endl;

    // Output sorted data

    //  for (int num : sortedData) {
    //         cout << num << " ";
    //     }

    //     cout << endl;

    return 0;
}
