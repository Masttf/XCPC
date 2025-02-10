#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
	mt19937 rd(time(0));
    int n = 5000;
    int R = 1e5;
    int id = 0;
    vector<int> vis(n + 1);
    cout << n << '\n';
    for(int i = 1; i <= 1000; i++){
    	int d = rd() % 1000 + 1;
    	++id;
    	vis[id] = 1;
    	cout << 1 << ' ' << d << '\n';
    	// int dd = rd() % R + 1;
    	// cout << 3 << ' ' << dd << '\n';
    }
    for(int i = 1; i <= 500; i++){
    	int chose = rd() % id + 1;
    	while(!vis[chose]){
    		chose = rd() % id + 1;
    	}
    	vis[chose] = 0;
    	cout << 2 << ' ' << chose << '\n';
    	int dd = rd() % R + 1;
    	cout << 3 << ' ' << dd << '\n';
    }
    for(int i = 1; i <= 1000; i++){
    	int d = rd() % 1000 + 1;
    	++id;
    	vis[id] = 1;
    	cout << 1 << ' ' << d << '\n';
    	int dd = rd() % R + 1;
    	cout << 3 << ' ' << dd << '\n';
    }
    for(int i = 1; i <= 1000; i++){
    	int dd = rd() % R + 1;
    	cout << 3 << ' ' << dd << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}