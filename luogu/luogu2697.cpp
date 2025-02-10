#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	s=' '+s;
	vector<int>cnt(2000005,-1);
	int last=1000000;
	cnt[last]=0;
	int ans=0;
	for(int i=1;i<s.size();i++){
		if(s[i]=='G'){
			last++;
		}else last--;
		if(cnt[last]==-1)cnt[last]=i;
		else ans=max(ans,i-cnt[last]);
	}
	cout<<ans<<'\n';
	return ;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}