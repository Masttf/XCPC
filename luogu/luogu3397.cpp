#include<bits/stdc++.h>
using namespace std;
int res[1005][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int x1,y1,x2,y2;
	for(int i=1;i<=m;i++){
		cin>>x1>>y1>>x2>>y2;
		res[x1][y1]++;
		res[x2+1][y2+1]++;
		res[x1][y2+1]--;
		res[x2+1][y1]--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			res[i][j]=res[i-1][j]+res[i][j-1]-res[i-1][j-1]+res[i][j];
			cout<<res[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
