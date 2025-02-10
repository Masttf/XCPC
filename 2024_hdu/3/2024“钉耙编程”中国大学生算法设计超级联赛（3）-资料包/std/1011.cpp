#include <bits/stdc++.h>
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define repd(x, r, l) for(int x = r; x >= l; x--)
#define clr(x, y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

const int MAXN = 2e5 + 5;
const int dict[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
struct node{
    ll x, y;
    int d;
} a[MAXN];
int n;

ll check(ll mid){
    ll mxx = -INF, mxy = -INF;
    ll mnx = INF, mny = INF;
    rep(i, 1, n){
        mxx = max(mxx, a[i].x + mid * dict[a[i].d][0]);
        mxy = max(mxy, a[i].y + mid * dict[a[i].d][1]);
        mnx = min(mnx, a[i].x + mid * dict[a[i].d][0]);
        mny = min(mny, a[i].y + mid * dict[a[i].d][1]);
    }
    return 2 * (mxx - mnx + mxy - mny);
}

int main(){
    scanf("%d", &n);
    rep(i, 1, n){
        char ch[5];
        scanf("%lld%lld%s", &a[i].x, &a[i].y, ch);
        if(ch[0] == 'W') a[i].d = 0;
        if(ch[0] == 'S') a[i].d = 1;
        if(ch[0] == 'N') a[i].d = 2;
        if(ch[0] == 'E') a[i].d = 3;
    }
    ll l = 1, r = 2e9;
    while(r >= l){
        ll mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        if(check(mid1) > check(mid2)) l = mid1 + 1;
        else r = mid2 - 1;
    }
    printf("%lld\n", check(l));
    return 0;
}