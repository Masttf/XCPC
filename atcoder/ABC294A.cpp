#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x%2==0)cout<<x<<' ';
	}
	return 0;
}
