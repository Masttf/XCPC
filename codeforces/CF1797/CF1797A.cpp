#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void solve(){
	int n,m;cin>>n>>m;
	int x,y,xx,yy;cin>>x>>y>>xx>>yy;
	int mi=min(n,m);
	int cnt=0;
	for(int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m)cnt++;
	}
	int ans=min(cnt,mi);
	cnt=0;
	for(int i=0;i<4;i++){
		int tx=xx+dx[i];
		int ty=yy+dy[i];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=m)cnt++;
	}
	ans=min(ans,cnt);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
