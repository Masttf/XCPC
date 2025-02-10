#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	vector<int>vis(k+1);
	for(int i=1;i<=n;i++)cin>>a[i],vis[a[i]]=1;
	vector<int>pre(n+1);
	vector<int>suf(n+2);
	for(int i=1;i<=n;i++){
		pre[i]=max(pre[i-1],a[i]);
	}
	for(int i=n;i>=1;i--){
		suf[i]=max(suf[i+1],a[i]);
	}
	
	for(int i=1;i<=k;i++){
		int l=1,r=n;
		int ansl=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(pre[mid]>=i){
				ansl=mid;
				r=mid-1;
			}else l=mid+1;
		}
		
		l=1,r=n;
		int ansr=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(suf[mid]>=i){
				ansr=mid;
				l=mid+1;
			}else r=mid-1;
		}
		if(vis[i])cout<<(ansr-ansl+1)*2<<' ';
		else cout<<0<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
