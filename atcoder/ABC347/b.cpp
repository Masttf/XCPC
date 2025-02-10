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
const int mod=1e9+7;
const int Max=1e18;
void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	set<string>m;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			m.insert(s.substr(i,j-i+1));
		}
	}
	cout<<m.size()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}