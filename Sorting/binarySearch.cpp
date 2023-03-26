#include <bits/stdc++.h>

class Solution
{
public:
    int binarySearch(vector<int> &nums, int target)
    {
        int l = 0;                 // left pointer
        int r = (nums.size()) - 1; // right pointer
        while (l <= r)
        {
            int m = (r + l) / 2; // middle index
            if (nums[m] < target)
            {
                l = m + 1;
            }

            else if (nums[m] == target)
            {
                return m;
            }

            else
            {
                r = m - 1;
            }
        }
        return -1; // if target doesn't exist in vector
    }
};

int main()
{
    vector<int> v;
    v.push_back(-1);
    v.push_back(8);
    v.push_back(16);
    Solution s = Solution();
    int ans = s.binarySearch(v, 8);
    cout << ans << endl;
    return -1;
}