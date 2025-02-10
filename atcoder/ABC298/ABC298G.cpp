#include<bits/stdc++.h>
#define int long long
using namespace std;
int g[10][10];
int s[10][10][10][10],f[10][10][10][10][55];
int mi;
void init(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int c=0;c<10;c++){
				for(int d=0;d<10;d++){
					for(int k=0;k<55;k++){
						f[i][j][c][d][k]=-1;
					}
				}
			}
		}
	}
	return ;
}
int dfs(int i,int j,int l,int r,int cnt){
	if((j-i)*(r-l)<=cnt)return f[i][j][l][r][cnt]=LONG_LONG_MAX;
	if(cnt==0){
		if(s[i][j][l][r]>=mi)return f[i][j][l][r][cnt]=s[i][j][l][r];
		else return f[i][j][l][r][cnt]=LONG_LONG_MAX;
	}
	if(f[i][j][l][r][cnt]!=-1)return f[i][j][l][r][cnt];
	int res=LONG_LONG_MAX;
	for(int a=i+1;a<=j-1;a++){
		for(int k=0;k<=cnt-1;k++){
			res=min(res,max(dfs(i,a,l,r,k),dfs(a,j,l,r,cnt-1-k)));
		}
	}
	for(int a=l+1;a<=r-1;a++){
		for(int k=0;k<=cnt-1;k++){
			res=min(res,max(dfs(i,j,l,a,k),dfs(i,j,a,r,cnt-1-k)));
		}
	}
	return f[i][j][l][r][cnt]=res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int h,w,t;cin>>h>>w>>t;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)cin>>g[i][j];
	}
	for(int a=0;a<=h-1;a++){
		for(int b=a+1;b<=h;b++){
			for(int c=0;c<=w-1;c++){
				for(int d=c+1;d<=w;d++){
					int temp=0;
					for(int i=a+1;i<=b;i++){
						for(int j=c+1;j<=d;j++)temp+=g[i][j];
					}
					s[a][b][c][d]=temp;
				}
			}
		}
	}
	int ans=LONG_LONG_MAX;
	for(int a=0;a<=h-1;a++){
		for(int b=a+1;b<=h;b++){
			for(int c=0;c<=w-1;c++){
				for(int d=c+1;d<=w;d++){
					mi=s[a][b][c][d];
					init();
					int res=dfs(0,h,0,w,t);
					if(res!=LONG_LONG_MAX)ans=min(ans,res-mi);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
