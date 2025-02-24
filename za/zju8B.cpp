#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=114520;
bitset<maxn>g[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++){
		int op;cin>>op;
		int u,v;cin>>u>>v;
		if(op==1){
			g[u][v]=1;
			g[v][u]=1;
		}else{
			if(g[u][v]==1){
				cout<<"No\n";
			}else{
				if((g[u]&g[v]).count()>0){
					cout<<"Yes\n";
				}else cout<<"NO\n";
			}
		}
		
	}
	return 0;
}
