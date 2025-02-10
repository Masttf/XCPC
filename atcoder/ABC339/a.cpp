#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	vector<char>ans;
	int n=s.size();
	for(int i=n-1;i>=0;i--){
		if(s[i]=='.')break;
		ans.push_back(s[i]);
	}
	int x=ans.size();
	for(int i=x-1;i>=0;i--)cout<<ans[i];
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}