#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,b;cin>>a>>b;
	int d=b-a;
	if(-3<=d&&d<=2){
		cout<<"Yes\n";
	}else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}