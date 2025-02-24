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
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    vector<char> a(n + 1), b(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
    	if(s[i] == '1')cnt++;
    }
    if(cnt % 2 != 0){
    	cout << "NO\n";
    	return ;
    }
    cnt /= 2;
    int f = 1;
    for(int i = 1; i <= n; i++){
    	if(s[i] == '1'){
    		cnt--;
    		if(cnt < 0)a[i] = b[i] = ')';
    		else a[i] = b[i] = '(';
    	}else{
    		f ^= 1;
    		if(f){
    			a[i] = '(';
    			b[i] = ')';
    		}else{
    			a[i] = ')';
    			b[i] = '(';
    		}
    	}
    }
    auto check = [&](vector<char> &x) -> bool{
    	int cnt = 0;
    	for(int i = 1; i <= n; i++){
    		if(x[i] == '(')cnt++;
    		else cnt--;
    		if(cnt < 0)return false;
    	}
    	return cnt == 0;
    };
    bool ok = check(a) & check(b);
    // for(int i = 1; i <= n; i++){
	// 	cout << a[i];
	// }
	// cout << '\n';
	// for(int i = 1; i <= n; i++){
	// 	cout << b[i];
	// }
	// cout << '\n';
    if(ok){
    	cout << "YES\n";
    	for(int i = 1; i <= n; i++){
    		cout << a[i];
    	}
    	cout << '\n';
    	for(int i = 1; i <= n; i++){
    		cout << b[i];
    	}
    	cout << '\n';
    }else{
    	cout << "NO\n";
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
1 相同
0 不同
1001
()()
(())
0000
)()(
()()
*/