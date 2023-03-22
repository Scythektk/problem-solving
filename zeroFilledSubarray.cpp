#include <bits/stdc++.h>
using namespace std;

long long zeroFilledSubarray(vector<int> &nums)
{
    long count = 0;
    int whereZeroSubIndexEndsOrSth = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            whereZeroSubIndexEndsOrSth++;
            count += whereZeroSubIndexEndsOrSth;
        }
        else
        {
            whereZeroSubIndexEndsOrSth = 0;
        }
    }
    return count;
}

int main()
{
    vector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 0;
    v1[3] = 3;
    v1[4] = 0;
    v1[5] = 0;
    long long ans = zeroFilledSubarray(v1);
    cout << ans << endl;
    return 0;
}