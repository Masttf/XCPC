#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		sum+=x;
	}
	int d=sqrt(sum);
	while(d*d<sum)d++;
	while(d*d>sum)d--;
	if(d*d==sum){
		cout<<"YES\n";
		return ;
	}
	cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}