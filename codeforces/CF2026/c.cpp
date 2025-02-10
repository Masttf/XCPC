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
    int ans = n * (n + 1) / 2;
    
    set<int>s1;
    set<int, greater<>> s2;
    set<int> s3;
    vector<int> vis(n + 1);
    for(int i = 1; i <= n; i++){
    	s1.insert(i);
    	s2.insert(i);
    	if(s[i] == '1' && s2.size() >= 2){
    		ans -= *s2.begin();
    		int x = *s2.begin();
    		int y = *s1.begin();
    		s2.erase(x), s2.erase(y);
    		s1.erase(x), s1.erase(y);
    		s3.insert(x);
    	}else if(s[i] == '1' && s2.size() == 1){
    		if(!s3.empty()){
    			ans -= *s2.begin() - *s3.begin();
    			int x = *s2.begin();
    			int y = *s3.begin();
    			s2.erase(x), s1.erase(x);
    			s3.insert(x);
    			s3.erase(y);
    			s2.insert(y), s1.insert(y);
    		}
    	}
    }
    cout << ans << '\n';
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