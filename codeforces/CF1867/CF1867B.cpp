#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	int cnt=0;
	for(int i=1;i<=n/2;i++){
		if(s[i]!=s[n-i+1])cnt++;
	}
	vector<int>ans(n+1);
	for(int i=0;i<=n;i++){
		if(i>=cnt&&i<=n-cnt){
			if(n%2==1)ans[i]=1;
			else{
				if((i-cnt)%2==0)ans[i]=1;
				else ans[i]=0;
			}
		}else ans[i]=0;
	}
	for(int i=0;i<=n;i++)cout<<ans[i];
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
