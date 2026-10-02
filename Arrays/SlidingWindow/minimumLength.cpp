#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int minlen = 10000000;
    int left = 0;
    int sum = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while(sum >= target) {
            minlen = min(minlen,right - left + 1);
            sum -= nums[left];
            left++;
        }
        
    }

    if(minlen == 10000000) {
        return 0;
    }
    return minlen;
}

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    cout<<minSubArrayLen(target,nums)<<endl;

}