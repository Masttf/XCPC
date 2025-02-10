#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int phi[maxn],vis[maxn];
vector<int>prim;
void init(int n){
	phi[1]=1;
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			phi[i]=i-1;
			prim.push_back(i);
		}
		for(int j=0;prim[j]<=n/i;j++){
			vis[prim[j]*i]=1;
			if(i%prim[j]==0){
				phi[prim[j]*i]=prim[j]*phi[i];
				break;
			}
			phi[prim[j]*i]=(prim[j]-1)*phi[i];
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	if(n==1)cout<<0;
	else{
		init(n);
		int cnt=0;
		for(int i=1;i<=n-1;i++)cnt+=phi[i];
		cout<<2*cnt+1;
	}
	return 0;
}
