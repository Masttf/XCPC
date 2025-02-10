#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int pos=1;
	for(int i=19;i>=0;i--){//倍增
		if(pos+(1LL<<i)<=n){
			cout<<"? "<<pos+(1LL<<i)<<endl;
			int x;cin>>x;
			if(x==0)pos+=(1LL<<i);
		}
	}
	cout<<"! "<<pos;
	return 0;
}
