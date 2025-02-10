#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	if(s=="abc"){
		cout<<"YES\n";
		return ;
	}
	s=' '+s;
	for(int i=1;i<=3;i++){
		for(int j=i+1;j<=3;j++){
			string temp=s;
			swap(temp[i],temp[j]);
			if(temp==" abc"){
				cout<<"YES\n";
				return ;
			}
		}
	}
	cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
