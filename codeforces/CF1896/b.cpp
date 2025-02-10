#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	int last=0;
	int first=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='B')last=i;
		else{
			if(!first)first=i;
		}
	}
	if(!last||!first){
		cout<<0<<'\n';
	}else cout<<max(0ll,last-first)<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}