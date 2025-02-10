#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>f;
	for(int i=2;i<=n/i;i++){
		if(n%i==0){
			int t=0;
			while(n%i==0)n/=i,t++;
			f.push_back({t,i});
		}
	}
	if(n>1)f.push_back({1,n});
	sort(f.begin(),f.end());
	int sum=1;
	for(int i=0;i<f.size();i++){
		sum*=f[i].second;
	}
	int last=1,s=1,cnt=0;
	int ans=0;
	for(int i=0;i<f.size();i++){
		while(i<f.size()-1&&f[i].first==f[i+1].first)s*=f[i].second,i++;
		s*=f[i].second;
		ans+=sum/last*(f[i].first-cnt);
		last=s;
		cnt=f[i].first;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
