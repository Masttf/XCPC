#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,res;
bool check(int x){
	return x*n>=m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n<(m+n-1)/n)cout<<-1;
	else{
		int ans=LONG_LONG_MAX;
		for(int i=1;i<=min(n,1000000LL);i++){//因子最大不会超过1e6
			int j=(m+i-1)/i;
			if(j>n)continue;
			if(i*j>=m)ans=min(ans,i*j);
		}
		cout<<ans;
	}
	return 0;
}

