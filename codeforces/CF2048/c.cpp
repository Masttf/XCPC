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
    int n = s.size();
    s = ' ' + s;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++){
    	b[i] = s[i] - '0';
    }
    cout << 1 << ' ' << n << ' ';
    int ansl = -1, ansr = -1;
    int ok = 0;
    for(int i = 1; i <= n; i++){
    	if(s[i] == '0'){
    		ok = i;
    		break;
    	}
    }
    if(ok == 0){
    	cout << 1 << ' ' << 1 << '\n';
    	return ;
    }
    int len = n - ok + 1;
    vector<int> res(len + 1);
    vector<int> temp(len + 1);
    auto get = [&](int st) -> void{
    	for(int i = st, j = 1; i <= st + len - 1; i++, j++){
    		temp[j] = b[ok + j - 1] ^ b[i];
    	}
    };
    auto check = [&]() -> bool{
    	for(int i = 1; i <= len; i++){
    		if(res[i] > temp[i])return true;
    		else if(res[i] < temp[i])return false;
    	}
    	return true;
    };
    for(int i = 1; i + len - 1 <= n; i++){
    	if(s[i] == '1'){
    		// dbg(i);
    		if(ansl == -1){
    			get(i);
    			ansl = i, ansr = i + len - 1;
    			swap(res, temp);
    		}else{
    			get(i);
    			if(!check()){
    				ansl = i, ansr = i + len - 1;
    				swap(res, temp);
    			}
    		}
    	}
    }
    // cout << endl;
    // for(int i = 1; i <= len; i++){
    // 	cout << res[i] << ' ';
    // }
    // cout << endl;
    cout << ansl << ' ' << ansr << '\n';
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