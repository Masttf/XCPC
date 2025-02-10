#include<bits/stdc++.h>
using namespace std;
const int N=252,p=998244353; 
int n,a[N],f[N][N][N],g[N][N][N],h[N][N][N],w[N][N][N];
int inc(int a,int b){
	if(a+b>=p) return a+b-p; return a+b;
}
int main(){
//	freopen("3.in","r",stdin);
//	freopen("3.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(a[i]==a[j]&&a[j]==a[k])
					f[i][j][k]=inc(w[i-1][j-1][k-1],1);
				g[i][j][k]=inc(g[i-1][j][k],f[i][j][k]);
				h[i][j][k]=inc(h[i][j-1][k],g[i][j][k]);
				w[i][j][k]=inc(w[i][j][k-1],h[i][j][k]);
			}
	cout<<w[n][n][n]<<endl;
	return 0;
}
