#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	int n=20;
	cout<<n<<'\n';
	for(int i=1;i<=n;i++){
		cout<<rand()<<' ';
	}
	return 0;
}