//floyd算法
//如果两点间的路径要缩短要引进另一个点即i-j>i-k-j，因此g[i][k]+g[k][j]<g[i][j]
//如果引进两个点则应该在第一个的基础上 why?如果第二个点没有与第一个点相连且路径最短则更新，
//如果第二个与第一个点相连那么第二个点到所有点的距离已经被更新即如果变短已经是加上第一个点的路径
//因此可以考虑枚举所有引进的点即可完成最短路径
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=99999999;
int n,m;
int g[205][205],res[205];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>res[i];
	for(int i=1;i<205;i++){//初始化
		for(int j=1;j<205;j++){
			if(i==j)g[i][j]=0;
			else g[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		u+=1,v+=1;
		g[u][v]=w;
		g[v][u]=w;
	}
	int s=1;
	int q;cin>>q;
	int x,y,t;
	for(int i=1;i<=q;i++){
		cin>>x>>y>>t;
		x+=1,y+=1;
		while(s<=n&&res[s]<=t){
			for(int j=1;j<=n;j++){
				for(int h=1;h<=n;h++){
					if(g[j][s]+g[s][h]<g[j][h])g[j][h]=g[j][s]+g[s][h];
				}
			}
			s++;
		}
		if(res[x]>t||res[y]>t||g[x][y]==inf)cout<<-1<<'\n';
		else cout<<g[x][y]<<'\n';
	}
	return 0;
}
