#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{

    if(k <= 1) {
        return 0;
    }

    int left = 0;
    int cnt = 0;
    int prod = 1;

    for(int right = 0;right < nums.size();right++) {
        prod *= nums[right];

        while(prod >= k) {
            prod /= nums[left];
            left++;
        }
        cnt += right - left + 1;
    }

    return cnt;
}

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout<<numSubarrayProductLessThanK(nums,k)<<endl;
}