#include<bits/stdc++.h>
// #define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
constexpr int maxn = 1e7 + 5;
int a[maxn], stk[maxn], top, n, id;
long long d, mx;
void solve(){
	n = read();
	// cin >> n;
	for(int i = 1; i <= n; ++i){
		a[i] = read();
		// cin >> a[i];
		d = 1ll * i * a[i];
		if(d > mx) mx = d;
	}
	for(int i = n; i >= 1; --i){
		
		if(a[i] < a[id]){
			d = 1ll * a[i] * (id + i);
			if(d > mx) mx = d;
		}
		if(!id || a[i] >= a[id])id = i;
	}
	top = 0;
	for(int i = 1; i <= n; ++i){
		while(top && a[stk[top]] < a[i]){
			top--;
		}
		if(top){
			d = 1ll * a[i] * (i + stk[top]);
			if(d > mx) mx = d;
		}
		stk[++top] = i;
	}
	cout << mx << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int t = 1;
	// cin >> t;
	// while(t--)solve();
	solve();
	return 0;
}
// min(kx, ky) * (x + y)
// 枚举某个位置作为最小值， 那么就是比它大的 越右越好
// 左边就是最近
// 右边 ? ><<<<<<