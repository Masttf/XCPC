#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
int h[maxn];
int dp_max[maxn][20];
int dp_min[maxn][20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		dp_max[i][0]=h[i];
		dp_min[i][0]=h[i];
	}
	for(int k=1;(1<<k)<=n;k++){
		for(int s=1;s+(1<<k)<=n+1;s++){
			dp_max[s][k]=max(dp_max[s][k-1],dp_max[s+(1<<(k-1))][k-1]);
			dp_min[s][k]=min(dp_min[s][k-1],dp_min[s+(1<<(k-1))][k-1]);
		}
	}
	int a,b;
	for(int i=1;i<=q;i++){
		cin>>a>>b;
		int len=b-a+1;
		int k=log2(len);
		cout<<max(dp_max[a][k],dp_max[b-(1<<k)+1][k])-min(dp_min[a][k],dp_min[b-(1<<k)+1][k])<<'\n';
	}
	return 0;
}
