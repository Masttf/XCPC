#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=1e4+5;
const int INFN=23;
int n,k,m,a[INF],f[INF][INFN][INFN][2],F[INFN],sum[INF];
multiset <int> s;
// dp 到第 i 个数，里面删掉 x 个，外面加进来 y 个，是否在延长区间内 
signed main()
{
	memset(f,-63,sizeof f);
	ios::sync_with_stdio(false);
	cin>>n>>k>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=k;i++) s.insert(a[i]);
	f[0][0][0][0]=0; 
	for (int i=1;i<=n;i++) {
		if (i+k-1<=n) {
			auto it=s.begin();
			for (int j=1;j<=m;j++) {
				F[j]=F[j-1]+(*it);
				it++;
			}
		}
		int S=0;
		if (i+k-1<=n) S=sum[i+k-1]-sum[i-1];
		int j=(i-1)%k;
		for (int x=0;x<=m;x++) {
			for (int y=0;y<=m;y++) {
				// 如果是区间外 
				if (j<k-1) {
					f[i][x][y][0]=max({f[i-1][x][y][0],f[i-1][x][y][1],f[i][x][y][0]});
					f[i][x][y+1][0]=max({f[i][x][y+1][0],f[i-1][x][y][0]+a[i],f[i-1][x][y][1]+a[i]});
				}	
				
				if (j<k-1) {
					f[i][x][y][1]=max({f[i][x][y][1],f[i-1][x][y][1]+a[i]});
					f[i][x+1][y][1]=max({f[i][x+1][y][1],f[i-1][x][y][1]});
				}
				
				if (i+k-1<=n) {
//					if (i==1) cerr<<" "<<f[i-1][0][0][0]<<" "<<k<<" oked!\n";
					for (int z=0;z<=m;z++) 
						if (x+z<=m) {
							f[i+k-1][x+z][y][1]=max({f[i+k-1][x+z][y][1],f[i-1][x][y][0]+S-F[z],f[i-1][x][y][1]+S-F[z]});
//							cerr<<i+k-1<<" "<<x+z<<" "<<y<<" "<<f[i+k-1][x+z][y][1]<<" awerjert\n";
						}
				}
			}
		}
		
		if (i+k<=n) s.insert(a[i+k]),s.erase(s.find(a[i]));
	}
//	cerr<<f[10][0][0][1]<<" awej\n"; 
	int res=-1e18;
	for (int z=0;z<=m;z++) res=max({res,f[n][z][z][0],f[n][z][z][1]});
	cout<<res<<"\n";
	return 0;
}