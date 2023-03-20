#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int leftSum = 0;
    int rightSum = 0; // better solution would have been to call sum once here and subtract from it later.
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            leftSum += nums[j];
        }
        for (int k = i + 1; k < nums.size(); k++)
        {
            rightSum += nums[k];
        }
        if (leftSum == rightSum)
        {
            return i;
        }
        else
        {
            leftSum = 0;
            rightSum = 0;
        }
    }
    return -1;
}

int main()
{
    vector<int> v1(4);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v1[3] = 3;
    int ans = pivotIndex(v1);
    cout << ans << endl;
    return 0;
}