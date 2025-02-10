#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int res[maxn];
int dpmi[maxn][22],dpmx[maxn][22];//左边表示起始点，右边表示以2的多少次方的长度
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		dpmi[i][0]=res[i];
		dpmx[i][0]=res[i];
	}
	int p=log2(n);
	for(int k=1;k<=p;k++){
		for(int s=1;s+(1<<k)<=n+1;s++){
			dpmx[s][k]=max(dpmx[s][k-1],dpmx[s+(1<<(k-1))][k-1]);//递推dp明显的该组的最值可以用上一组的最值推出
			dpmi[s][k]=min(dpmi[s][k-1],dpmi[s+(1<<(k-1))][k-1]);
		}
	}
	int l,r;
	while(m--){
		cin>>l>>r;
		int k=log2(r-l+1);
		cout<<max(dpmx[l][k],dpmx[r-(1<<k)+1][k])<<'\n';
	}
	return 0;
}
