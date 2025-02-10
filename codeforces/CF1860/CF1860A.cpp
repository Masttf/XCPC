#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int n=s.size();
	int ok=0;
	if(n==2&&s=="()")ok=1;
	if(ok)cout<<"NO\n";
	else{
		cout<<"YES\n";
		string res1="";
		for(int i=1;i<=n;i++)res1+="()";
		string res2="";
		for(int i=1;i<=n;i++)res2+='(';
		for(int i=1;i<=n;i++)res2+=')';
		if(res1.find(s)==res1.npos){
			cout<<res1<<'\n';
		}else cout<<res2<<'\n';
		//cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
