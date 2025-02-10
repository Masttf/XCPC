#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	int d;cin>>d;
	int ans=INT_MAX;
	for(int i=1;i*i<=d;i++){
		int res=d-i*i;
		int j=sqrt(res);
		while(j*j<res)j++;
		while(j*j>res)j--;

		ans=min(ans,abs(i*i+j*j-d));
		j++;
		ans=min(ans,abs(i*i+j*j-d));
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}