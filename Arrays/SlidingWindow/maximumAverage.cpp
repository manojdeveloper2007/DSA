#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{

    if (nums.size() == 1)
    {
        return ((double)nums[0] / k);
    }

    int left = 0;
    double maxavg = -20000;
    double sum = 0.0;

    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        if (right - left + 1 == k)
        {
            maxavg = max(maxavg, sum / k);
            sum -= nums[left];
            left++;
        }
    }

    return maxavg;
}

int main()
{
    vector<int> nums = {0, 1, 1, 3, 3};
    int k = 4;

    cout << findMaxAverage(nums, k) << endl;
}