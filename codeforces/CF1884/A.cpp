#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int x,k;cin>>x>>k;
	while(1){
		int temp=x;
		int res=0;
		while(temp)res+=temp%10,temp/=10;
		if(res%k==0){
			cout<<x<<'\n';
			return ;
		}
		x++;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}