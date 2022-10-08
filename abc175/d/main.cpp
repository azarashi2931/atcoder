#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ll N, K;
    scanf("%lld", &N);
    scanf("%lld", &K);

    vector<ll> P(N);
    vector<ll> C(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &P[i]);
        P[i]--;
    }
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &C[i]);
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        ll score = 0, length = 1;
        vector<ll> checkLen(N, 0), checkSum(N, 0);
        ll j = i;
        while (checkLen[j] == 0)
        {
            checkLen[j] = length;
            checkSum[j] = score;
            j = P[j];
            score += C[j];
            length++;
        }

        ll loopLen = length - checkLen[j];
        ll loopScore = score - checkSum[j];
        ll sum = checkSum[j];

        if (loopScore > 0)
            sum += (K / loopLen) * loopScore;

        ll restColumn = (K - checkLen[j] + 1) % loopLen;
        if (restColumn > 0)
        {
            vector<ll> restSums(restColumn);
            restSums[0] = C[j];
            for (ll k = 1; k < restColumn; k++)
            {
                restSums[k] = restSums[k - 1] + C[j];
                j = P[j];
            }
            sort(restSums.begin(), restSums.end());
            sum += restSums[restColumn - 1];
        }

        ans = max(sum, ans);
    }

    printf("%lld\n", ans);
}
