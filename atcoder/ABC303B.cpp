#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=55;
int a[maxn][maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>m>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	map<pair<int,int>,int>kk;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				if(kk.count({a[i][j],a[i][k]})||kk.count({a[i][k],a[i][j]}))continue;
				kk[make_pair(a[i][j],a[i][k])]++;	
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			if(kk.count({a[i][j],a[i][j+1]}))kk.erase({a[i][j],a[i][j+1]});
			if(kk.count({a[i][j+1],a[i][j]}))kk.erase({a[i][j+1],a[i][j]});
		}
	}
	cout<<kk.size();
	return 0;
}
