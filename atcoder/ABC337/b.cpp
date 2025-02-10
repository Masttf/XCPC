#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int ok=1;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]!=s[0])ok=0;
	}
	if(ok==1){
		cout<<"Yes\n";
	}else{
		char now = 'A';
		for(int i=0;i<n;i++){
			if(s[i]!=now){
				if(s[i]<now){
					cout<<"No\n";
					return ;
				}else{
					now=s[i];
				}
			} 
		}
		cout<<"Yes\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}