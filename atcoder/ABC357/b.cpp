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
    int cnt1 = 0, cnt2 = 0;
    for(auto x : s){
    	if(x >= 'a' && x <= 'z'){
    		cnt1++;
    	}else cnt2++;
    }
    if(cnt2 > cnt1){
    	for(auto &x : s){
    		if(x >= 'a' && x <= 'z'){
    			x = x - 'a' + 'A';
    		}
    	}
    }else{
    	for(auto &x : s){
    		if(x >= 'A' && x <= 'Z'){
    			x = x - 'A' + 'a';
    		}
    	}
    }
    cout << s << '\n';
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