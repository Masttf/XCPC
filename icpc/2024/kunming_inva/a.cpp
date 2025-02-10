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
    int n, m, K; cin >> n >> m >> K;
    vector<int> s(n + 1);
    vector p(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		for(int j = 1; j <= m; j++){
			cin >> p[i][j];
		}
	}
	// dbg(n, m);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) a[i] = i;
	sort(a.begin() + 1, a.end(), [&](int x, int y) -> bool{
		return s[x] < s[y];
	});
	int ok = 1;
	int limit = 0;
	for(int i = 1; i <= n; i++){
		int j = i;
		while(j <= n && s[a[j]] == s[a[i]]){
			j++;
		}
		j--;
		int last = limit;
		for(int k = i; k <= j; k++){
			int now = a[k];
			int sum = 0;
			for(int t = 1; t <= m; t++){
				if(p[now][t] != -1)sum += p[now][t];
			}
			for(int t = 1; t <= m; t++){
				if(p[now][t] == -1){
					p[now][t] = max(0ll, min(limit - sum, K));
					sum += p[now][t];
				}
			}
			if(sum < limit)ok = 0;
			last = max(last, sum + 1);
		}
		limit = last;
		i = j;
	}
	if(!ok){
		cout << "No\n";
		return ;
	}else{
		cout << "Yes\n";
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << p[i][j] << ' ';
			}
			cout << '\n';
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