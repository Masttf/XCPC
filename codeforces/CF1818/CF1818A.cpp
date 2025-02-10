#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1005;
void solve(){
	map<string,int>m;
	int n,k;cin>>n>>k;
	string a;
	for(int i=0;i<n;i++){
		string temp;cin>>temp;
		if(!i)a=temp;
		m[temp]++;
	}
	cout<<m[a]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
