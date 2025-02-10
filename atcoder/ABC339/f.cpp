#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p1=998244353;
const int p2=1000000993;
void solve(){
	int n;cin>>n;
	vector<string>a(n+1);
	vector<pair<int,int>>val(n+1);
	map<pair<int,int>,int>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int v1=0,v2=0;
		for(auto x:a[i]){
			v1=(v1*10+x-'0')%p1;
			v2=(v2*10+x-'0')%p2;
		}
		val[i]={v1,v2};
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int v1=val[i].first*val[j].first%p1;
			int v2=val[i].second*val[j].second%p2;
			m[{v1,v2}]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=m[val[i]];
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}