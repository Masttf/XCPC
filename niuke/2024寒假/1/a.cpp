#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int res=0,res2=0;
	string temp="dfs";
	string temp2="DFS";
	int l=0;
	for(int i=0;i<n;i++){
		if(s[i]==temp[l])l++;
		if(l==3){
			res2=1;
			break;
		}
	}
	l=0;
	for(int i=0;i<n;i++){
		if(s[i]==temp2[l])l++;
		if(l==3){
			res=1;
			break;
		}
	}
	cout<<res<<' '<<res2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}