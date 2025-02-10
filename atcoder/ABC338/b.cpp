#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	vector<int>cnt(30);
	for(auto i:s){
		cnt[i-'a']++;
	}
	int mx=0;
	for(int i=0;i<26;i++)mx=max(mx,cnt[i]);
	for(int i=0;i<26;i++){
		if(cnt[i]==mx){
			char ans=i+'a';
			cout<<ans<<'\n';
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