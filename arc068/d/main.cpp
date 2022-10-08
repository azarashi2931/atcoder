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
    vector<ll> A(N);
    for (ll i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }

    sort(A.begin(), A.end());

    ll except = 0;
    ll mod2 = 0;
    ll j = 0;
    for (ll i = 0; i < N; i++)
    {
        j++;

        if (i == N - 1 || A[i] != A[i + 1])
        {
            if (j > 0 && j % 2 == 0)
            {
                mod2++;
            }
            if (j > 2)
            {
                except += (j - 1) / 2;
            }

            j = 0;
        }
    }
    except += mod2 / 2;
    if (mod2 % 2 == 1)
        except++;
    printf("%lld", N - except * 2);
}
