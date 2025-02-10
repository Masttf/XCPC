#include<bits/stdc++.h>
using namespace std;
#define int long long
int res[1005][1005];
signed main(){
	int n,m,c;
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>res[i][j];
			res[i][j]+=res[i-1][j]+res[i][j-1]-res[i-1][j-1];
		}
	}
	int mx=res[2][2];
	int x=2,y=2;
	for(int i=c;i<=n;i++){
		for(int j=c;j<=m;j++){
			if(mx<res[i][j]-res[i-c][j]-res[i][j-c]+res[i-c][j-c]){
				mx=res[i][j]-res[i-c][j]-res[i][j-c]+res[i-c][j-c];
				x=i;
				y=j;
			}
		}
	}
	cout<<x-c+1<<" "<<y-c+1;
	return 0;
}
