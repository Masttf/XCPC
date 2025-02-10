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
    vector<int> du(5), in(5);
    for(int i = 1; i <= 3; i++){
    	for(int j = i + 1; j <= 3; j++){
    		char x; cin >> x;
    		if(x == '<'){
    			du[j]++;
    			in[i]++;
    		}else{
    			du[i]++;
    			in[j]++;
    		}
    	}
    }
    for(int i = 1; i <= 3; i++){
    	if(du[i] && in[i]){
    		char ans = 'A';
    		ans += i - 1;
    		cout << ans << '\n';
    		return ;
    	}
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