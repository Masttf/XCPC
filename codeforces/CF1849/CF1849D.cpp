#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
bool vis[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(a[i]==2){
			ans++;
			vis[i]=1;
			int l=i,r=i;
			while(l>=1&&a[l]>=1){
				l--;
				vis[l]=1;
			}
			while(r<=n&&a[r]>=1){
				r++;
				vis[r]=1;
			}
			i=r-1;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(a[i]==1){
			ans++;
			int flag=0;
			if(i!=1&&!vis[i-1]){
				vis[i-1]=1;
				flag=1;
			}
			int j=i;
			while(j<=n&&a[j]>=1){
				vis[j]=1;
				j++;
			}
			if(flag==0)vis[j]=1;
			i=j-1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])ans++;
	}
	cout<<ans;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
