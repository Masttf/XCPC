#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5005;
int a[maxn];
bool vis[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],vis[i]=0;//在零之前要有一张牌
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=0)continue;
		int mx=i;
		for(int j=1;j<i;j++){
			if(a[j]!=0&&!vis[j]){
				if(a[j]>a[mx])mx=j;
			}
		}
		vis[mx]=1;
		ans+=a[mx];
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
