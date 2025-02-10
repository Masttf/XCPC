#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<1<<'\n';
	int n=1000;
	cout<<n<<' '<<n-1<<'\n';
	for(int i=2;i<=n;i++){
		cout<<i-1<<' '<<i<<' '<<100000<<'\n';
	}
	for(int i=1;i<=n;i++){
		cout<<1000<<' ';
	}
	return 0;
}