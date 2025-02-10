#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	unordered_map<char,int>m;
	for(int i=0;i<n;i++)m[s[i]]=i;
	if(m.count('R')&&m.count('L')){
		for(int i=0;i<n-1;i++){
			if(s[i]=='L'&&s[i+1]=='R'){
				cout<<i+1<<'\n';
				return ;
			}
		}
		cout<<0<<'\n';
	}else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
