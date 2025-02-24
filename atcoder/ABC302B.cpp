#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
string a[maxn];
string res="snuke";
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='s'){
				for(int k=0;k<8;k++){
					int t=1;
					int tx=i+dx[k];
					int ty=j+dy[k];
					int ok=1;
					while(t<=4){
						if(tx>=0&&tx<n&&ty>=0&&ty<m&&a[tx][ty]==res[t])t++;
						else{
							ok=0;
							break;
						}
						tx+=dx[k];
						ty+=dy[k];
					}
					if(ok){
						cout<<i+1<<' '<<j+1<<'\n';
						t=1;
						tx=i+dx[k];
						ty=j+dy[k];
						while(t<=4){
							cout<<tx+1<<' '<<ty+1<<'\n';
							t++;
							tx+=dx[k];
							ty+=dy[k];
						}
						
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
