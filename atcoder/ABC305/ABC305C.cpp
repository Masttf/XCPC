#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='#')continue;
			int res=0;
			for(int k=0;k<4;k++){
				int tx=i+dx[k];
				int ty=j+dy[k];
				if(tx>=0&&tx<n&&ty>=0&&ty<m&&a[tx][ty]=='#')res++;
			}
			//if(i==1&&j==3)cout<<res<<endl;
			if(res>=2){
				cout<<i+1<<' '<<j+1<<'\n';
				return ;
			}
		}
	}
	//cout<<"YES"<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}