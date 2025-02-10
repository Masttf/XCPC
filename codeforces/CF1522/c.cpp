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
void solve(){
	int n,k;cin>>n>>k;
	vector<int>vis(2*n+5);
	vector<pair<int,int>>res;
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		if(x>y)swap(x,y);
		res.push_back({x,y});
		vis[x]=vis[y]=1;
	}
	vector<int>un;
	for(int i=1;i<=2*n;i++){
		if(!vis[i])un.push_back(i);
	}
	for(int i=0;i<n-k;i++){
		res.push_back({un[i],un[i+n-k]});
	}
	//dbg(res.size());
	int ans=0;
	auto check = [&](pair<int,int>x,pair<int,int>y)->bool{
		if(x.first>y.first)swap(x,y);
		return x.second>y.first&&x.second<y.second;
	};
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(check(res[i],res[j]))ans++;
		}
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