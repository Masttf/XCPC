#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int b[maxn];
int c[5][5];//表示 i 到j 有边
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		c[a[i]][b[i]]++;
	}
	for(int i=1;i<=4;i++)ans+=c[i][i],c[i][i]=0;
	for(int i=1;i<=4;i++){
		for(int j=i+1;j<=4;j++){
			int t=min(c[i][j],c[j][i]);
			c[i][j]-=t;
			c[j][i]-=t;
			ans+=t;
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			for(int k=1;k<=4;k++){
				int t=min({c[i][j],c[j][k],c[k][i]});
				c[i][j]-=t;
				c[j][k]-=t;
				c[k][i]-=t;
				ans+=t;
			}
		}
	}
	int res=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++)res+=c[i][j];
	}
	res/=4;
	ans+=res;
	ans=n-ans;
	cout<<ans;
	return 0;
}
