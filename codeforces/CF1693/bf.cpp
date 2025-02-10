#include<bits/sdtc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=10;i++){
		int x,y;cin>>x>>y;
		int ans=0;
		for(int j=1;j<=y;j++)ans++x;
		cout<<ans<<'\n';
	}
	return 0;
}