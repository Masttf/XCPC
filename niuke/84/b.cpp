#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int x,y;cin>>x>>y;
	int res=x*y;
	for(int i=1;i<=y;i++){
		if(res%i==0){
			int d=res/i;
			if(__gcd(i,d)==x){
				cout<<i<<' '<<d<<'\n';
				return ;
			}
		}
	}
	cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}