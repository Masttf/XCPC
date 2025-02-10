#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	vector<string>a(5);
	for(int i=1;i<=3;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	for(int i=1;i<=3;i++){
		int ok=0;
		for(int j=1;j<=3;j++){
			if(a[i][j]=='?')ok=1;
		}
		if(ok){
			map<char,int>m;
			for(int j=1;j<=3;j++){
				m[a[i][j]]=1;
			}
			for(int j=1;j<=3;j++){
				if(!m.count('A'+j-1)){
					char ans='A'+j-1;
					cout<<ans<<'\n';
					return ;
				}
			}
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