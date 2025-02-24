#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}


void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(m + 1);
	auto pf = [&]() -> void{
		int ok = 1;
		vector<int> vis(n * m + 1);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				int d = a[i] * b[j] % (n * m);
				// cout << d << ' ';
				if(vis[d])ok = 0;
				vis[d] = 1;
			}
			// cout << '\n';
		}
		if(ok){
			cout << "Yes\n";
			for(int i = 1; i <= n; i ++){
				cout << a[i] << ' ';
			}
			cout << '\n';
			for(int i = 1; i <= m; i++){
				cout << b[i] << ' ';
			}
			cout << '\n';
			for(int i = 1; i <= n; i++){
				assert(a[i] < n * m);
			}
			for(int i = 1; i <= m; i++){
				assert(b[i] < n * m);
			}
		}else{ 
			cout << "No\n";
		}
		
		
		// cout << endl << endl;
		// assert(ok);
	};
	if(n == 1 && m == 1){
		a[1] = 0;
		b[1] = 0;
		pf();
		return ;
	}
	if(n == 1){
		a[1] = 1;
		for(int i = 1; i <= m; i++){
			b[i] = i - 1;
		}
		pf();
		return ;
	}
	if(m == 1){
		b[1] = 1;
		for(int i = 1; i <= n; i++){
			a[i] = i - 1;
		}
		pf();
		return ;
	}
	for(int i = 1, j = 1; i <= n; i++, j += m){
		a[i] = j;
	}
	for(int i = 1, j = 1; i <= m; i++, j += n){
		b[i] = j;
	}
	pf();
	
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