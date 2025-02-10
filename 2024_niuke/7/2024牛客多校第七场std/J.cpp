#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    long long l, x, y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld %lld %lld", &l, &x, &y);
        if (x * x + y * y <= l * l)
        {
            printf("Yes\n0\n");
        } else if ((x - l) * (x - l) + y * y <= l * l)
        {
            printf("Yes\n%lld\n", l);
        } else
        {
            printf("No\n");
        }
    }
    return 0;
}