#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    string s, t; cin >> s >> t;
    int n = s.size();
    vector<string>res;
    while(1){
    	set<string> m;
    	for(int i = 0; i < n; i++){
    		if(s[i] != t[i]){
    			string temp = s;
    			temp[i] = t[i];
    			m.insert(temp);
    		}
    	}
    	if(m.empty())break;
    	s = *m.begin();
    	res.push_back(s);
    }
    cout << res.size() << '\n';
    for(auto x : res) cout << x <<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}