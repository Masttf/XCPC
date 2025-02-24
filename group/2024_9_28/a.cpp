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
char t[] = {'r', 'w', 'x'};
void solve(){
    string s; cin >> s;
    for(auto x : s){
    	int d = x - '0';
    	vector<int>res;
    	for(int i = 1; i <= 3; i++){
    		res.push_back(d % 2);
    		d /= 2;
    	}
    	reverse(res.begin(), res.end());
    	for(int i = 0 ;i < 3; i++){
    		if(res[i] == 1)cout << t[i];
    		else cout << '-';
    	}
    }
    cout << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;  cin >> t;
    while(t--)solve();
    return 0;
}