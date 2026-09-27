#include <iostream>
#include <vector>
using namespace std;

// if array is sorted
vector<int> twoSum( vector<int> &nums,int target ) {
    int i = 0;
    int j = nums.size() - 1;

    while(i < j) {
        int sum = nums[i] + nums[j];

        if(sum == target) {
            return {i,j};
        }

        else if(sum > target) {
            j--;
        }

        else{
            i++;
        }
    }

    return {-1,-1};
}

int main() {
    vector<int> nums = {1,3,6,11,14};
    int target = 9;
    vector<int> ans = twoSum(nums,target);

    for (auto i: ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}