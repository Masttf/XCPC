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
    string s; cin >> s;
    int a = 0, b = 0;
    int flag = 0;
    for(auto x : s){
    	if(x == '-'){
    		flag = 1;
    	}else{
    		if(!flag)a = a * 10 + x - '0';
    		else b = b * 10 + x - '0';
    	}
    }
    cout << a - b << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}