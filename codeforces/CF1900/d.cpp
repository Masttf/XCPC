#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
const int maxn=1e5;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>cnt(maxn+5);
	vector<int>pre(maxn+5);
	for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=maxn;i++)pre[i]=pre[i-1]+cnt[i];

	vector<int>res(maxn+5);
	for(int i=1;i<=maxn;i++){
		int temp=0;
		for(int j=i;j<=maxn;j+=i){
			if(cnt[j]){
				res[i]+=cnt[j]*temp*(pre[maxn]-pre[j]);
				res[i]+=cnt[j]*(cnt[j]-1)/2*(pre[maxn]-pre[j]);
				res[i]+=cnt[j]*(cnt[j]-1)*(cnt[j]-2)/6;
				res[i]+=cnt[j]*(cnt[j]-1)/2*temp;
				temp+=cnt[j];
				//dbg(i,j,res[i]);
			}
			
		}
		//dbg(i,res[i]);
	}
	for(int i=maxn;i>=1;i--){
		for(int j=i*2;j<=maxn;j+=i){
			res[i]-=res[j];
		}
	}
	int ans=0;
	for(int i=1;i<=maxn;i++){
		ans+=i*res[i];
		//dbg(i,res[i]);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
/*
1
8
6 12 8 10 15 12 15 16


*/