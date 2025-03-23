#include<bits/stdc++.h>
// #define int long long
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
template<class T, 
	class Cmp = std::less<T>>
struct ST{
	int n, k;
	const Cmp cmp = Cmp();
	vector<vector<T>> st;
	ST(){}
	ST(const vector<T> &a){
		init(a);
	}
	void init(const vector<T> &a){
		n = a.size() - 1;
		k = __lg(n);
		st.resize(k + 1, vector<T>(n + 1));
		for(int i = 1; i <= n; i++){
			st[0][i] = a[i];
		}
		for(int s = 1; s <= k; s++){
			for(int i = 1; i + (1 << s) <= n + 1; i++){
				st[s][i] = min(st[s - 1][i], st[s - 1][i + (1 << (s - 1))], cmp);
			}
		}
	}
	T get(int l, int r){
		int d = __lg(r - l + 1);
		return min(st[d][l], st[d][r - (1 << d) + 1], cmp);
	}
};
constexpr int N = 2e5;
vector<int> d[N + 1];
void init(){
	vector<int> vis(N + 1);
	for(int i = 2; i <= N; i++){
		if(!vis[i]){
			for(int j = i; j <= N; j += i){
				vis[j] = 1;
				d[j].push_back(i);
			}
		}
	}
}
void solve(){
	int n, m; cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> b(n);
	for(int i = 1; i < n; i++) cin >> b[i];
	
	vector<int> last(N + 1, -1);
	vector<int> l(n), r(n);
	for(int i = 1; i < n; i++){
		for(auto v : d[a[i]]){
			last[v] = i;
		}
		l[i] = last[b[i]];
	}
	for(int i = 1; i <= N; i++) last[i] = n + 1;
	for(int i = n; i > 1; i--){
		for(auto v : d[a[i]]){
			last[v] = i;
		}
		r[i - 1] = last[b[i - 1]];
	}
	
	vector<pair<int, int>> res(n + 1);
	for(int i = 1; i <= n; i++){
		res[i] = {i, i};
	}
	ST<int> st(l);
	for(int i = 1; i <= n; i++){
		int l = i + 1, r = n;
		int rs = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(st.get(i, mid - 1) >= i){
				rs = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		res[i].second = rs;
	}
	for(int i = 1; i <= n; i++){
		int L = res[i].first;
		int R = res[i].second;

		while(1){
			int ok = 0;
			if(L != 1 && r[L - 1] <= R){
				R = max(R, res[L - 1].second);
				L = min(L, res[L - 1].first);				
				ok = 1;	
			}
			if(R != n && l[R] >= L){
				ok = 1;  
				L = min(L, res[R + 1].first);
				R = max(R + 1, res[R + 1].second);
			}	
			if(!ok)break;
		}
		
		// dbg(i, L, R);
		res[i] = {L, R};
	}
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		int L = res[x].first;
		int R = res[x].second;
		if(L <= y && y <= R){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	} 
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    init();
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
1
5 5
7 1 6 6 14
7 2 3 2
1 2
1 4
3 5
5 1
3 1
*/