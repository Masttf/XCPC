#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
int psum[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,r;cin>>n>>r;
	int x,y,v;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>v;
		psum[x+1][y+1]=v;
	}
	for(int i=1;i<maxn;i++){
		for(int j=1;j<maxn;j++){
			psum[i][j]=psum[i-1][j]+psum[i][j-1]+psum[i][j]-psum[i-1][j-1];
		}
	}
	int mx=0;
	for(int i=1;i<maxn-r;i++){
		for(int j=1;j<maxn-r;j++){
			int t=psum[i+r-1][j+r-1]-psum[i+r-1][j-1]-psum[i-1][j+r-1]+psum[i-1][j-1];
			mx=max(mx,t);
		}
	}
	cout<<mx;
	return 0;
}