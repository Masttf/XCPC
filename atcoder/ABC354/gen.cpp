#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
const int mod=1e9;
mt19937 rnd(time(0));
void solve(){
	
	int d1=rnd()%(2*mod)-mod;
	int d2=rnd()%(2*mod)-mod;
	int d3=rnd()%(2*mod)-mod;
	while(d3<d1){
		d3=rnd()%(2*mod)-mod;
	}
	int d4=rnd()%(2*mod)-mod;
	while(d4<d2){
		d4=rnd()%(2*mod)-mod;
	}
	cout<<d1<<' ';
	cout<<d2<<' ';
	cout<<d3<<' ';
	cout<<d4<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}