#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int l=1;
	int sum=s.size();
	for(char it:s){
		int temp=it-'0';
		if(temp==0)temp=10;
		sum+=abs(temp-l);
		l=temp;
	}
	cout<<sum<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}