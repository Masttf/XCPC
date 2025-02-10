#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n;cin >> n;
	string l, r;cin >> l >> r;
    auto get_mx = [&](__int128 lim) ->__int128{
    	__int128 res = 0;
		__int128 l = 0;
		__int128 r = 1e15;
		while(l <= r){
			__int128 mid = (l + r) / 2;
			if(mid * mid > lim){
				r = mid - 1;
			}else{
				res = mid;
				l = mid + 1;
			}
		}
		return res;
    };
    auto check = [&](__int128 x) -> bool{
    	__int128 l = get_mx(x);
    	return l * l == x;
    };
	auto get = [&](string x) -> __int128{
		__int128 a = 0;
		for(int i = 0; i < n / 2; i++){
			a = a * 10 + x[i] - '0';
		}
		__int128 b = 0;
		__int128 b2 = 0;
		for(int i = n / 2; i < n; i++){
			b = b * 10 + x[i] - '0';
			b2 = b2 * 10 + 9;
		}

		__int128 res1 = get_mx(a);
		__int128 res2 = get_mx(b);
		__int128 res3 = get_mx(b2);
		if(res1 * res1 != a){
			return (res1 + 1) * (res3 + 1);
		}else{
			__int128 ans = res1 * (res3 + 1);
			ans += res2 + 1;
			return ans;
		}
	};
	__int128 ans = get(r) - get(l);
    __int128 t = 0;
    int ok = 1;
    for(int i = 0; i < n; i++){
        t = t * 10 + l[i] - '0';
        if(i == n / 2 - 1){
            if(!check(t))ok = 0;
            t = 0;
        }
    }
    if(check(t) && ok)ans++;
    vector<int>res;
    while(ans){
    	res.push_back(ans % 10);
    	ans /= 10;
    }
    reverse(res.begin(), res.end());
    for(auto x : res)cout << x;
    cout << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}