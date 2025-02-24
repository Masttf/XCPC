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
    if(s[1] == '-'){
    	cout << "No\n";
    	return ;
    }
    for(int j = n - 2; j <= n; j++){
    	if(s[j] != '>'){
    		cout << "No\n";
    		return ;
    	}
    }
    vector<pair<int, int>>res;
    int j;
    for(j = n; j >= 5; j--){
    	if(s[j] == '>' && s[j - 1] == '>' && s[j - 2] == '>'){
    		res.push_back({1, j});
    	}else{
    		j++;
    		break;
    	}
    }
    if(j < 5)j++;
    // dbg(j);
    if(s[j - 3] != '-'){
    	cout << "No\n";
    	return ;
    }
    for(int i = 2; i < j - 3; i++){
    	if(s[i] == '>'){
    		res.push_back({i, j - i + 1});
    	}
    }
    cout << "Yes " << res.size() << '\n';
    for(auto [x, y] : res){
    	cout << x << ' ' << y << '\n';
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