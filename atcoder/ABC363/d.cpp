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
    if(n == 1){
    	cout << 0 << '\n';
    	return ;
    }
    n -= 1;
    int p = 1;
    int wei = 0;
    while(n > p * 18){
    	n -= p * 18;
    	p *= 10;
    	wei += 2;
    }
    if(n <= p * 9){
    	wei++;
    }else{
    	n -= p * 9;
    	wei += 2;
    }
    n += p - 1;

    vector<int>res;
    while(n){
    	res.push_back(n % 10);
    	n /= 10;
    }
    reverse(res.begin(), res.end());
    for(auto x : res)cout << x;
    if(wei % 2 == 1){
    	for(int i = res.size() - 2; i >= 0; i--){
    		cout << res[i];
    	}
    }else{
    	for(int i = res.size() - 1; i >= 0; i--){
    		cout << res[i];
    	}
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