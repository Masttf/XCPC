#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	string temp=s;
	for(int i=1;i<=n;i++){
		if(temp[i]=='a'||temp[i]=='e')temp[i]='V';
		else temp[i]='C';
	}
	vector<char>ans;
	for(int i=n;i>=1;i--){
		ans.push_back(s[i]);
		if(i!=1&&i!=n&&temp[i]=='C'&&temp[i+1]=='V'){
			ans.push_back('.');
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans)cout<<x;
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