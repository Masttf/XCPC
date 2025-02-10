#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int k,g,m;cin>>k>>g>>m;
	int res1=0,res2=0;
	for(int i=1;i<=k;i++){
		if(res1==g)res1=0;
		else if(res2==0)res2=m;
		else{
			int d=min(res2,g-res1);
			res2-=d;
			res1+=d;
		}
	}
	cout<<res1<<' '<<res2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}