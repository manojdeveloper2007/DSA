#include <iostream>
using namespace std;

int nthRootofNumber(int m,int n){
    int low = 1;
    int high = m;

    while(low <= high) {
        int mid = (low + high) / 2;
        int mul = 1;
        for(int i=1;i<=n;i++) {
            mul *= mid;
            if (mul > m) {
                break;
            }
        }

        if (mul == m) {
            return mid;
        }

        else if(mul < m) {
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    cout<<nthRootofNumber(81,4)<<endl;
}