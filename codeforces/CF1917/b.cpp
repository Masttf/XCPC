#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	int ans=0;
	vector<int>cnt(30);
	set<char>ss;
	for(int i=1;i<=n;i++){
		cnt[s[i]-'a']++;
		ss.insert(s[i]);
	}
	for(int i=n;i>=1;i--){
		ans+=ss.size();
		cnt[s[i]-'a']--;
		if(cnt[s[i]-'a']==0)ss.erase(s[i]);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}