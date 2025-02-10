#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string a[10];
	for(int i=0;i<8;i++)cin>>a[i];
	char ans;
	for(int i=0;i<8;i++){
		int len=0;
		if(a[i][0]!='.'){
			while(len<=7&&a[i][len]=='R')len++;
			if(len==8){
				ans='R';
				break;
			}
		}
		len=0;
		if(a[0][i]!='.'){
			while(len<=7&&a[len][i]=='B')len++;
			if(len==8){
				ans='B';
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
