#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ll   long long
#define pb   emplace_back
#define mp   make_pair
#define orz  1000000007
#define fi   first
#define se   second
#define N    2005
using namespace std;
int su[N][N],sd[N][N],sl[N][N],sr[N][N];
int fu[N][N],fd[N][N],fl[N][N],fr[N][N];
int n,m,k,ans=orz;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i){
		int u,d,l,r;
		scanf("%d%d%d%d",&u,&l,&d,&r);
		++su[u][l],--su[u][r+1];
		++sd[d][l],--sd[d][r+1];
		++sl[u][l],--sl[d+1][l];
		++sr[u][r],--sr[d+1][r];
	}
	++su[1][1],++sl[1][1],++sd[n][1],++sr[1][m];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			su[i][j]+=su[i][j-1];
			sd[i][j]+=sd[i][j-1];
			sl[i][j]+=sl[i-1][j];
			sr[i][j]+=sr[i-1][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)fu[i][j]=(su[i][j]?i:fu[i-1][j]);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)fl[i][j]=(sl[i][j]?j:fl[i][j-1]);
	}
	for(int i=n;i;--i){
		for(int j=m;j;--j)fd[i][j]=(sd[i][j]?i:fd[i+1][j]);
	}
	for(int i=n;i;--i){
		for(int j=m;j;--j)fr[i][j]=(sr[i][j]?j:fr[i][j+1]);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)if(fu[i][j]==i&&fl[i][j]==j)ans=min(ans,(fd[i][j]-i+1)*(fr[i][j]-j+1));
	}
	printf("%d\n",ans);
    return 0;
}

