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
    int n, k; cin >> n >> k;
	vector<int>a(n + 1), b(n + 1);
	vector<int> p(1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p.push_back(a[i]);
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		p.push_back(b[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	vector<int> num1(2 * n + 5), num2(2 * n + 5);
	for(int i = 1; i <= n; i++){
		int r = lower_bound(p.begin(), p.end(), b[i]) - p.begin();
		int l = upper_bound(p.begin(), p.end(), a[i]) - p.begin();
		num1[1]++;
		num1[r + 1]--;
		num2[l]++;
		num2[r + 1]--;
	}
	int ans = 0;
	for(int i = 1; i <= 2 * n; i++){
		if(i >= p.size())break;
		num1[i] += num1[i - 1];
		num2[i] += num2[i - 1];
		if(num2[i] <= k){
			ans = max(ans, num1[i] * p[i]);
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