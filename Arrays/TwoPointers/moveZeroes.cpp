#include <iostream>
#include <vector>
using namespace std;

// move zeroes to end
void moveZeroesToEnd(vector<int> &nums) {

    int zero = -1;

    // find first zero
    for(int i = 0;i < nums.size();i++) {
        if(nums[i] == 0) {
            zero = i;
            break;
        }
    }

    if(zero == -1) {
        cout<<"There is no zero in array"<<endl;
        return;
    }

    if(zero == nums.size() - 1) {
        return;
    }

    for(int i = zero+1;i < nums.size();i++) {
        if(nums[i] != 0) {
            swap(nums[zero],nums[i]);
            zero++;
        }
    }
}

int main() {
    vector<int> nums = {1,0,2,0,0,3,1,0,4};

    moveZeroesToEnd(nums);

    for(auto i : nums) {
        cout<<i<<" ";
    }
    cout<<endl;
}