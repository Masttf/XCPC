#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	s=' '+s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='B')cnt++;
	}
	if(cnt==k){
		cout<<0<<'\n';
		return ;
	}else if(cnt>k){
		cout<<1<<'\n';
		for(int i=1;i<=n;i++){
			if(s[i]=='B')cnt--;
			if(cnt==k){
				cout<<i<<" "<<"A"<<'\n';
				return ;
			}
		}
		return ;
	}else{
		cout<<1<<'\n';
		for(int i=1;i<=n;i++){
			if(s[i]=='A')cnt++;
			if(cnt==k){
				cout<<i<<" "<<"B"<<'\n';
				return ;
			}
		}
		return ;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}