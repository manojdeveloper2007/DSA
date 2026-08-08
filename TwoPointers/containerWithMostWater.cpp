#include <iostream>
#include <vector>
using namespace std;

int containerWater(vector<int> &nums) {
    int maxx = 0;
    int left = 0;
    int right = nums.size()-1;

    while (left < right) {
        int minn = min(nums[left],nums[right]);
        maxx = max(maxx,(minn * (right-left)));

        if(minn == nums[left]) {
            left++;
        } else{
            right--;
        }
    }
    return maxx;
}

int main() {
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    cout<<containerWater(nums)<<endl;
}