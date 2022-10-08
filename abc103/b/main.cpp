#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll i, string s, string t)
{
    for (ll j = i; j < i + s.length(); j++)
    {
        if (true)
        {
            printf("%lld ", i);
            printf("%lld ", j);
            printf("%lu ", s.length());
            printf("%lld ", i + s.length());
            printf("%lld ", s.length() - 1 - (j - i));
            printf("%lld\n", j % s.length());
        }

        if (s[j % s.length()] != t[s.length() - 1 - (j - i)])
            return false;
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s;
    cin >> t;

    //printf("%d", check(2, s, t));
    for (ll i = 0; i < s.length(); i++)
    {
        if (check(i, s, t))
        {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");
}
