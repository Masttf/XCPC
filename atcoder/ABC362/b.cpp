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
    vector<int> x(5), y(5);
    for(int i = 1; i <= 3; i++){
    	cin >> x[i] >> y[i];
    }
    int tot = 0;
    vector<int> len;
    for(int i = 1; i <= 3; i++){
    	for(int j = i + 1; j <= 3; j++){
    		int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    		len.push_back(d);
    	}
    }
    sort(len.begin(), len.end());
    if(len[0] + len[1] == len[2]) cout << "Yes\n";
    else cout << "No\n";
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