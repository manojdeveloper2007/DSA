#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canWePlace(vector<int> &arr,int dist,int cows) {
    int cowCount = 1;
    int last = arr[0];
    for(int i = 0;i < arr.size();i++) {
        if(arr[i]-last >= dist) {
            last = arr[i];
            cowCount+=1;

            if(cowCount >= cows) {
                return true;
            }
        }
    }
    return false;
}

int maxDistance(vector<int> &arr,int cows,int n) {

    sort(arr.begin(),arr.end());

    int maxx = *max_element(arr.begin(),arr.end());
    int minn = *min_element(arr.begin(),arr.end());
    int low = 1;
    int high = maxx-minn;
    int ans = 1;
    while(low <= high) {
        int dist = (low + high) / 2;

        if(canWePlace(arr,dist,cows)) {
            ans = dist;
            low = dist + 1;
        } else{
            high = dist - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,4,8,9};
    int n = 5;
    int cows = 3;
    cout<<maxDistance(arr,cows,n)<<endl;
}