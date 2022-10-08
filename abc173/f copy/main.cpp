#include <stdio.h>
#include <vector>

std::vector<int> mem(261, (int)-1);

int g(int x)
{
    if (mem[x] != -1)
        return mem[x];

    if (x == 1 || x == 2)
        return 1;
    return 2 * g(x - 2) + 3 * g(x - 1);
}

int main()
{
    int ans = g(260);
    printf("%d\n", ans);
}
