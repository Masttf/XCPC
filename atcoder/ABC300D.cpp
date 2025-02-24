#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
vector<int>prim;
int vis[maxn+5];
void init(){
	for(int i=2;i<=maxn;i++){
		if(!vis[i])prim.push_back(i);
		for(int j=0;prim[j]*i<=maxn;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	init();
	int len=prim.size();
	int ans=0;
	for(int i=0;i<len;i++){
		if(prim[i]*prim[i]*prim[i]*prim[i]*prim[i]>n)break;
		for(int j=i+1;j<len;j++){
			if(prim[i]*prim[i]*prim[j]*prim[j]*prim[j]>n)break;
			for(int k=j+1;k<len;k++){
				if(prim[i]*prim[i]*prim[j]*prim[k]*prim[k]<=n)ans++;
				else break;
			}
		}
	}
	cout<<ans;
	return 0;
}
