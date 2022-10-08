#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ll N;
    scanf("%lld", &N);

    string s;
    cin >> s;
    class range
    {
    private:
        struct I
        {
            int x;
            int operator*() { return x; }
            bool operator!=(I &lhs) { return x < lhs.x; }
            void operator++() { ++x; }
        };
        I i, n;

    public:
        range(int n) : i({0}), n({n}) {}
        range(int i, int n) : i({i}), n({n}) {}
        I &begin() { return i; }
        I &end() { return n; }
    };
    
    ll ans = 0;
    printf("%lld", ans);
}
