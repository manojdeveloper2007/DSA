#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxElement(vector<int> &piles) {
    int maxx = 0;

    for(int i : piles) {
        if (maxx < i) {
            maxx = i;
        }
    }

    return maxx;
}

long totalAmount(vector<int> &piles,int bananas) {
    int total = 0;

    for(int i : piles) {
        total += ceil((double)i/bananas);
    }

    return total;
}

int kokos(vector<int> &piles,int h) {

    int low = 1;
    int high = maxElement(piles);
    int ans = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        long total = totalAmount(piles,mid);

        if(total <= h) {
            ans = mid;
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }

    return ans;

}

int main() {
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<kokos(piles,h)<<endl;
}