#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int p=n-1;
	for(int i=n-1;i>=0;i--){
		if(s[p]>s[i])p=i;
	}
	if(p==0)cout<<s<<'\n';
	else{
		cout<<s[p];
		for(int i=0;i<n;i++){
			if(i==p)continue;
			cout<<s[i];
		}
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
