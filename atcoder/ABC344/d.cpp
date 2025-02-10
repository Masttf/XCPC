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
struct node{
	int l,r,id;
	bool operator <(const node &y)const{
		if(id!=y.id)return id<y.id;
		return r<y.r;
	}
};
const int Max=1e18;
void solve(){
	string t;cin>>t;
	int l=t.size();
	t=' '+t;
	int n;cin>>n;
	vector dp(n+1,vector<int>(l+1,Max));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		vector<string>a;
		for(int j=1;j<=x;j++){
			string s;cin>>s;
			a.push_back(s);
		}
		for(int j=0;j<=l;j++){
			dp[i][j]=dp[i-1][j];
			for(int k=0;k<x;k++){
				if(a[k].size()>j)continue;
				int l=j-a[k].size()+1;
				if(t.substr(l,a[k].size())==a[k]){
					dp[i][j]=min(dp[i][j],dp[i-1][l-1]+1);
				}
			}
		}
	}
	if(dp[n][l]==Max)cout<<-1<<'\n';
	else cout<<dp[n][l]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}