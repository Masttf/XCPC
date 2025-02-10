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
	int x;cin>>x;
	cout<<32<<'\n';
	vector<int>ans(32);
	for(int i=0;i<=31;i++){
		ans[i]=x>>i&1;
	}
	for(int i=0;i<=31;i++){
		if(ans[i]!=1)continue;
		int j=i;
		while(j<=31&&ans[j]==1){
			ans[j]=0;
			j++;
		}
		if(j==i+1){
			ans[i]=1;
			continue;
		}
		ans[i]=-1;
		ans[j]=1;
		i=j-1;
	}
	for(int i=0;i<=31;i++)cout<<ans[i]<<" \n"[i==31];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}