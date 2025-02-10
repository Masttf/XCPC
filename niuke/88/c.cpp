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
const int Max=1e18;
void solve(){
	int n;cin>>n;
	set<pair<int,int>>s;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		if(y<1){
			x--;
			y+=60;
		}
		s.insert({x,y-1});
		if(y<3){
			x--;
			y+=60;
		}
		s.insert({x,y-3});
		if(y<5){
			x--;
			y+=60;
		}
		s.insert({x,y-5});
	}
	cout<<s.size()<<'\n';
	for(auto [x,y]:s){
		cout<<x<<' '<<y<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}