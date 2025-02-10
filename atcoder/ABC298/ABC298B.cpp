#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
bool vis[maxn][maxn];
int n;
int check(){
	int f=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==1&&b[i][j]!=1)f=0;
		}
	}
	return f;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	int f=0;
	for(int i=1;i<=4;i++){
		f=max(f,check());
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=a[n+1-j][i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)a[i][j]=c[i][j];
		}
	}
	if(f)cout<<"Yes";
	else cout<<"No";
	return 0;
}
