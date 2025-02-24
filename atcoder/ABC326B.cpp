#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	for(int i=n;i<=999;i++){
		int d1=i/100;
		int d2=i%100/10;
		int d3=i%10;
		if(d1*d2==d3){
			cout<<i<<'\n';
			return ;
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}