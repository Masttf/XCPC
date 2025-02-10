#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int ans[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n-1;i++)cin>>a[i],ans[i]=0;
	ans[n]=0;
	for(int i=1;i<=n-1;i++){// 讨论关系 
		if(a[i]<a[i+1])ans[i+1]=a[i];
		else{
			if(i!=1&&a[i]>a[i-1])ans[i+1]=a[i];
			else{
				if(ans[i]&&ans[i]!=a[i])ans[i+1]=a[i];//如果相等
				else ans[i]=a[i];
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
