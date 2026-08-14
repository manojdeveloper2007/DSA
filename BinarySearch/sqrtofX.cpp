#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x)
{
    int ans = 0;

    if (x == 0)
    {
        return 0;
    }

    if (x == 1)
    {
        return 1;
    }

    long low = 1;
    long high = x;

    while (low <= high)
    {
        long mid = (low + high) / 2;

        if (mid * mid <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    cout<<mySqrt(36)<<endl;
}