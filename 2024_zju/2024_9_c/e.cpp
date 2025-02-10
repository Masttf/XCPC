#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int maxn=2e7+5;
int pre[maxn],vis[maxn];
vector<int>prim;
void init(){
	vis[1]=1;
	for(int i=2;i<maxn;i++){
		if(!vis[i])prim.push_back(i);
		for(int j=0;prim[j]*i<maxn;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
	vis[2]=1;
	vis[4]=0;
	for(int i=1;i<maxn;i++){
		pre[i]=pre[i-1];
		if(!vis[i])pre[i]++;
	}
}
void solve(){
	int l,r;cin>>l>>r;
	l++,r++;
	cout<<pre[r]-pre[l-1]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}