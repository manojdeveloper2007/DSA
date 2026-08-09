#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0;
    int right = 0;
    int minn = INT_MAX;
    int sum = 0;

    while (right < nums.size())
    {
        sum = sum + nums[right];
        // shrink
        while(sum >= target)
        {
            minn = min(minn, (right - left) + 1);
            sum = sum - nums[left];
            left = left + 1;
        }
        // expand
        right++;
    }
    if (minn == INT_MAX)
    {
        return 0;
    }
    return minn;
}

int main()
{
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, arr) << endl;
}