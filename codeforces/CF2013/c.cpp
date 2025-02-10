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
    string ans = "";
    int ok = 0;
    while(1){
    	if(ans.size() == n){
    		cout << "! " << ans << endl;
    		return ;
    	}
    	if(ok){
    		string t = ans;
    		t = '0' + t;
    		cout << "? " << t << endl;
	    	int x; cin >> x;
	    	if(x == 1)ans = '0' + ans;
	    	else ans = '1' + ans;
    	}else{
    		string t = ans;
	    	t.push_back('0');
	    	cout << "? " << t << endl;
	    	int x; cin >> x;
	    	if(x == 1){
	    		ans.push_back('0');
	    	}else{
	    		t = ans;
	    		t.push_back('1');
	    		cout << "? " << t << endl;
	    		cin >> x;
	    		if(x == 1)ans.push_back('1');
	    		else{
	    			ok = 1;
	    		}
	    	}
    	}
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