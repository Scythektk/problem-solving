#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t)
{
    int i = 0, j = 0;
    while (i < s.length() && j < t.length())
    {
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }
    if (i == s.length())
    {
        return true;
    }
    return false;
}

int main()
{
    bool ans = isSubsequence("ans", "answer");
    cout << ans << endl;
    return 0;
}