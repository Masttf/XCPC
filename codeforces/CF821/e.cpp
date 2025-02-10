#include<bits/stdc++.h>
//#define int long long
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
const int maxn=1e4+5;
int g[maxn][maxn];
int d[maxn][maxn];
bool vis[maxn][maxn];
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<pair<int,int>>a(k+1);
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		g[x][y]=1;
		a.push_back({x,y});
	}
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}