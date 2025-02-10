#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
void solve(){
	int n;cin>>n;
	map<int,int>ma,mb;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n&&a[j]==a[i])j++;
		ma[a[i]]=max(ma[a[i]],j-i);
		i=j-1;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n&&b[j]==b[i])j++;
		mb[b[i]]=max(mb[b[i]],j-i);
		i=j-1;
	}
	int ans=1;
	for(auto it=ma.begin();it!=ma.end();it++){
		ans=max(it->second+mb[it->first],ans);
	}
	for(auto it=mb.begin();it!=mb.end();it++){
		ans=max(it->second+ma[it->first],ans);
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
