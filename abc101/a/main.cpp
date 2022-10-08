#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int num = 0;

    for (int i = 0; i < 4; i++)
    {
        if (s[i] == '+')
        {
            num++;
        }
        else
        {
            num--;
        }
    }

    printf("%d", num);
}
