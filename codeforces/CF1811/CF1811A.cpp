#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int k;cin>>k;
	string s;cin>>s;
	int p=n;
	for(int i=0;i<n;i++){
		if(s[i]-'0'<k){
			p=i;
			break;
		}
	}
	for(int i=0;i<p;i++)cout<<s[i];
	cout<<k;
	for(int i=p;i<n;i++)cout<<s[i];
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
