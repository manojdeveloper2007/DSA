#include <iostream>
#include <vector>
using namespace std;

// return triplets without repeating which is equal to 0

vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size() - 1;
    vector<vector<int>> result;

    for(int i = 0;i < n-2;i++) {
        if(i > 0 && nums[i-1] == nums[i]) {
            continue;
        }

        int l = i+1;
        int r = n - 1;

        while(l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum == 0) {
                result.push_back({nums[i],nums[l],nums[r]});

                while(l < r && nums[l] == nums[l+1]) {
                    l++;
                }

                while(l < r && nums[r-1] == nums[r]) {
                    r--;
                }

                l++;
                r--;
            }

            else if(sum > 0) {
                r--;
            }

            else {
                l++;
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = threeSum(nums);

    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<< " ";
        }
        cout<<endl;
    }
}