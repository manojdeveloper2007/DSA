#include <iostream>
#include <vector>
using namespace std;

int containerWater(vector<int> &height) {
    int i = 0;
    int j = height.size() - 1;
    int maxx = 0;

    while(i < j) {
        int minn = min(height[i],height[j]);
        maxx = max(maxx,(minn * (j - i)));

        if(minn == height[i]) {
            i++;
        }

        else{
            j--;
        }
    }

    return maxx;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<containerWater(height)<<endl;
}