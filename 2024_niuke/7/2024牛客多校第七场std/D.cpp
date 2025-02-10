#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <cstring>
#define int long long

#define fi first
#define se second
#define endl '\n'
// #define int long long
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double db;

const int N = 5e5+5;
const int INF = 1e9;

struct seg{
    int l, r;
    int mn,cnt,add;
    #define mn(x) tree[x].mn
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define cnt(x) tree[x].cnt
    #define add(x) tree[x].add
}tree[N*4];

void push_up(seg &x, seg l, seg r){
    x.mn = min(l.mn,r.mn);
    x.cnt = 0;
    if (x.mn == l.mn) x.cnt += l.cnt;
    if (x.mn == r.mn) x.cnt += r.cnt;
}
void update(int x, int v){
    mn(x) += v;
    add(x) += v;
}
void push_down(int x){
    update(x*2,add(x));
    update(x*2+1,add(x));
    add(x) = 0;
}
void build(int x, int l, int r){
    l(x) = l, r(x) = r;
    if (l == r){
        mn(x) = 0; cnt(x) = 1;
        return;
    }
    int mid = (l+r)>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    push_up(tree[x],tree[x*2],tree[x*2+1]);
}
void modify(int x, int l, int r, int v){
    if(l > r)
        return;
    if (l(x) >= l && r(x) <= r){
        update(x,v);
        return;
    }
    push_down(x);
    int mid = (l(x)+r(x))>>1;
    if (l <= mid) modify(x*2,l,r,v);
    if (r > mid) modify(x*2+1,l,r,v);
    push_up(tree[x],tree[x*2],tree[x*2+1]);
}
seg query(int x, int l, int r){
    if (l(x) >= l && r(x) <= r){
        return tree[x];
    }
    push_down(x);
    int mid = (l(x)+r(x))>>1;
    seg ans; ans.mn = INF;
    if (l <= mid && r > mid) push_up(ans, query(x*2,l,r),query(x*2+1,l,r));
    else if (l <= mid) ans = query(x*2,l,r);
    else if (r > mid) ans = query(x*2+1,l,r);
    return ans;
}

function< void() > undo[N];
map<int, vector<int>> mp;
int arr[N];
int n, K;

void Sol()
{
    memset(tree, 0, (4*n+10)*sizeof(seg));
    build(1, 1, n);
    
    mp.clear();
    int ans = 0;
    
    for(int i=n; i>=1; i--)
    {
        auto &v = mp[arr[i]];
        v.push_back(i);
        if(v.size() < K)
        {
            modify(1, i, n, +1);
            undo[i] = [=]()
            {
                modify(1, i, n, -1);
            };
        }
        else if(v.size() == K)
        {
            modify(1, i, v.front()-1, +1);
            int x = v.front()-1;
            undo[i] = [=]()
            {
                modify(1, i, x, -1);
            };
        }
        else
        {
            if (v[v.size()-K-1] <= n)
            {
                modify(1, i, v[v.size()-K]-1, +1);
                modify(1, v[v.size()-K-1], n, +1);
                int x = v[v.size()-K]-1;
                int y = v[v.size()-K-1];
                undo[i] = [=]()
                {
                    modify(1, i, x, -1);
                    modify(1, y, n, -1);
                };
            }
            else
            {
                modify(1, i, v[v.size()-K]-1, +1);
                int x = v[v.size()-K]-1;
                undo[i] = [=]()
                {
                    modify(1, i, x, -1);
                };
            }
        }
        
        // 撤销上次操作
        if(v.size() >= 2)
        {
            undo[ v[v.size()-2] ]();
        }
        
        // 查询 [i, n] 中 0 的数量
        seg qr = query(1, i ,n);
        if(qr.mn == 0)
        {
//          printf("i = %lld  %lld\n",i,qr.cnt);
            ans += qr.cnt;
        }
        
//      for(int j=1; j<=n; j++)
//          {
//              qr = query(1, j ,j);
//              printf("%d ", qr.mn);
//          }
//      printf("\n");
        
    }
    
    printf("%lld\n", ans);
}


signed main()
{
    int tt;
    scanf("%lld", &tt);
    while(tt--)
    {
        scanf("%lld %lld", &n, &K);
        for(int i=1; i<=n; i++)
            scanf("%lld", &arr[i]);
        Sol();
    }
    
    return 0;
}