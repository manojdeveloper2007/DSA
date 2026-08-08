#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size()-1;
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++) {

        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        int j = i+1;
        int k = n;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0) {
                res.push_back({nums[i],nums[j],nums[k]});
                while(j < k && nums[j] == nums[j+1]) {
                    j++;
                }
                while(j < k && nums[k] == nums[k-1]) {
                    k--;
                }
                j++;
                k--;
            }
            else if(sum > 0) {
                k--;
            } else{
                j++;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);

    for(vector<int> i : res) {
        for(int j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}