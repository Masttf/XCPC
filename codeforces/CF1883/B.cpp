#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	vector<int>cnt(26);
	for(auto it:s){
		cnt[it-'a']++;
	}
	int ans=0;
	for(int i=0;i<26;i++){
		if(cnt[i]%2==1)ans++;
	}
	if(ans<=k+1)cout<<"YES"<<'\n';
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}