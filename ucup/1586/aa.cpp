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
constexpr int maxn=1e7+5;
constexpr int mod=998244353;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
};
int cnt[maxn],pre[maxn];
vector<int>f;
void init(){
	for(int i=2;i<=16;i++){
		for(int j=0;j<i;j++){
			int num=0;
			for(int k=0;k<=20;k++){
				int d=j*qmi(i,k);
				if(num+d>=maxn)break;
				num+=d;
				cnt[num]=1;
			}
		}
	}
	int num=0;
	for(int i=1;i<maxn;i++){
		if(cnt[i])num++;
	}
	dbg(num);
};
void solve(){
	int x,y;cin>>x>>y;
	int ans=(pre[y]-pre[x-1]+mod)%mod;
	cout<<ans<<'\n';
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