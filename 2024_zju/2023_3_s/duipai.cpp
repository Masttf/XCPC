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
void solve(){
	for(int i=1;i<100;i++){
		system("ge.exe > c_ex.txt");
		system("test.exe < c_ex.txt > ac.txt");
		system("c.exe < c_ex.txt > wa.txt");
		if(system("fc ac.txt wa.txt"))break;
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