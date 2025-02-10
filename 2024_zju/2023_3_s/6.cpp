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
void solve(){
	int n;cin>>n;
	vector<int>res(n);
	for(int i=n-1;i>=0;i--){
		if(res[i])continue;
		int ans=0;
		int flag=-1;
		for(int j=20;j>=0;j--){
			if(i>>j&1){
				if(flag==-1)flag=j;
			}
			if(flag!=-1){
				if(!(i>>j&1))ans+=1<<j;
			}
		}
		res[i]=ans;
		res[ans]=i;
	}
	for(auto x:res)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}