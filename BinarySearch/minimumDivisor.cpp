#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxElement(vector<int> &nums)
{
    int maxx = INT_MIN;
    for (int i : nums)
    {
        if (maxx < i)
        {
            maxx = i;
        }
    }
    return maxx;
}

bool totalSum(vector<int> &nums, int mid,int threshold)
{
    int total = 0;
    for (int i : nums)
    {
        total += ceil((double)i/ mid);
        if(total > threshold) {
            return false;
        }
    }
    return true;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int low = 1;
    int high = maxElement(nums);
    int minn = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool total = totalSum(nums, mid,threshold);

        if (total)
        {
            minn = min(minn, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return minn;
}

int main() {
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    cout<<smallestDivisor(nums,threshold)<<endl;
}