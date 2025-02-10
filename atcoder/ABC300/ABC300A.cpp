#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,a,b;cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x==a+b){
			cout<<i;
			break;
		}
	}
	return 0;
}
