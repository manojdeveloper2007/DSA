#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{

    if (nums.size() == 1)
    {
        return {nums[0]};
    }

    vector<int> maxarr;

    int maxx = -100;
    int left = 0;

    for(int right = 0;right < k;right++) {
        maxx = max(maxx,nums[right]);
    }
    
    maxarr.push_back(maxx);

    for(int right = k;right < nums.size();right++) {
        if(nums[left] == maxx) {
            maxx = *max_element(nums.begin()+left+1,nums.begin()+right+1);
        }

        else{
            maxx = max(maxx,nums[right]);
        }
        maxarr.push_back(maxx);
        left++;
    }

    return maxarr;
}

int main() {
    vector<int> nums = {1,3,1,2,0,5};
    int k = 3;

    vector<int> res = maxSlidingWindow(nums,k);

    for(auto i : res) {
        cout<<i<<endl;
    }
}