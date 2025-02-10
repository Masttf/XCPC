#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='L')sum+=i-1;
		else sum+=n-i;
	}
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(s[i]=='L')ans.push_back(n-i-(i-1));
		else ans.push_back(i-1-(n-i));
	}
	sort(ans.begin(),ans.end(),greater<int>());
	for(int i=1;i<ans.size();i++){
		ans[i]=max(ans[i]+ans[i-1],ans[i-1]);
	}
	for(int i=1;i<=n;i++){
		cout<<max(sum,sum+ans[i-1])<<" \n"[i==n];
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