#include<bits/stdc++.h>
#define int long long
using namespace std;
int qpow(int a,int b,int m){
	int res=1%m;
	a%=m;
	while(b){
		if(b&1)res=res*a%m;
		b>>=1;
		a=a*a%m;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cout.tie(0);cin.tie(0);
	int n,p;cin>>n>>p;
	for(int i=1;i<=n;i++){
		cout<<qpow(i,p-2,p)<<'\n';
	}
	return 0;
}
