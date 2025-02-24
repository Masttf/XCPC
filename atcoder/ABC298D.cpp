#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=6e5+5,mod=998244353;
int p[maxn],a[maxn];
void init(){
	p[0]=1;
	for(int i=1;i<maxn;i++){
		p[i]=p[i-1]*10%mod;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init();
	int res=1;
	a[1]=1;
	int l=1,r=1;
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int x;cin>>x;
			a[++r]=x;
			res=res*10%mod+x;
		}else if(t==2){
			res=((res-a[l]*p[r-l])%mod+mod)%mod;
			l++;
		}else cout<<res<<'\n';
	}
	return 0;
}
