#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b;cin>>a>>b;
	int cnt=0;
	while(max(a,b)%min(a,b)!=0){
		if(a>b){
			cnt+=a/b;
			a%=b;
		}else cnt+=b/a,b%=a;
	}
	cnt+=max(a,b)/min(a,b)-1;
	cout<<cnt;
	return 0;
}
