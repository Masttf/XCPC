#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int l=0;
	while(l<n/2&&((s[l]=='0'&&s[n-1-l]=='1')||(s[l]=='1'&&s[n-1-l]=='0')))l++;
	cout<<n-l*2<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
