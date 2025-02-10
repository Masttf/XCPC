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
    int n, h, m; cin >> n >> h >> m;
    vector a(3, vector<pair<string, string>>());
    a[0].push_back({"07:00:00", "09:00:00"});
    a[0].push_back({"18:00:00" ,"20:00:00"});
    a[1].push_back({"11:00:00", "13:00:00"});
    a[2].push_back({"22:00:00", "24:00:00"});
    a[2].push_back({"00:00:00", "01:00:00"});
    auto getTime = [&](string s) -> int{
    	int t1 = (s[0] - '0') * 10 + (s[1] - '0');
    	int h1 = (s[3] - '0') * 10 + (s[4] - '0');
    	int s1 = (s[6] - '0') * 10 + (s[7] - '0');
    	int tot = t1 * 60 * 60 + h1 * 60 + s1;
    	return tot;
    };
    auto check = [&](string year) -> bool{
    	int y = (year[0] - '0') * 1000 + (year[1] - '0') * 100 + (year[2] - '0') * 10 + (year[3] - '0');
    	int mo = (year[5] - '0') * 10 + (year[6] - '0');
    	return y == h && mo == m;
    };
    vector<map<string, int>> ans(3);
    for(int i = 1; i <= n; i++){
    	string id; cin >> id;
    	string year; cin >> year;
    	string time; cin >> time;
    	if(check(year)){
    		for(int j = 0; j < 3; j++){
    			for(auto [s, e] : a[j]){
    				if(getTime(s) <= getTime(time) && getTime(time) <= getTime(e)){
    					// dbg(i, j, id);
    					ans[j][id]++;
    				}
    			}
    		}
    	}
    }
    for(int i = 0; i < 3; i++){
    	cout << ans[i].size() << ' ';
    }
    cout << '\n';
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

/*

13 2021 12
2 2021-12-03 07:00:00
3 2021-12-03 11:00:00
3 2021-12-05 12:00:00
2 2021-12-06 09:20:00
2 2021-12-06 18:20:00
2 2021-12-07 13:00:00
2 2021-12-31 22:00:00
3 2021-12-30 21:00:00
4 2021-12-30 00:50:00
4 2021-12-31 00:30:00

1 2?/1? 
1 2 0
1 2 1
1 2 2

每个时间都只算一次
*/