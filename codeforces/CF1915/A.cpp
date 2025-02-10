#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	vector<int>cnt(10);
	for(int i=1;i<=3;i++){
		int x;cin>>x;
		cnt[x]++;
	}
	for(int i=0;i<10;i++){
		if(cnt[i]==1){
			cout<<i<<'\n';
			return  ;
		}
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