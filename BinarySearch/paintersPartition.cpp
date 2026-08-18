#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int pages(vector<int> &nums, int mid)
{
    int studentcnt = 1;
    int total = 0;

    for (int i : nums)
    {
        if (total + i <= mid)
        {
            total += i;
        }
        else
        {
            studentcnt += 1;
            total = i;
        }
    }
    return studentcnt;
}

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int cnt = pages(nums, mid);

        if (cnt > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    cout<<splitArray(nums,k)<<endl;
}