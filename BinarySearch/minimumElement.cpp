#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    int minn = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[low] <= nums[high])
        {
            minn = min(minn, nums[low]);
            return minn;
        }

        if (nums[low] <= nums[mid])
        {
            minn = min(minn, nums[low]);
            low = mid + 1;
        }
        else
        {
            minn = min(minn, nums[mid]);
            high = mid - 1;
        }
    }

    return minn;
}

int main() {
    vector<int> nums = {5,6,7,8,9,1,2,3,4};
    cout<<findMin(nums)<<endl;
}