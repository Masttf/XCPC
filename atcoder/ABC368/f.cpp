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
    int n; cin >> n;
    int N = 1e5 + 5;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
	// vector<int>m (N, -1);
    // auto sg = [&](auto self, int x) -> int{
    // 	if(x == 1)return 0;
    // 	if(m[x] != -1)return m[x];
    // 	set<int> s;
    // 	for(int i = 1; i * i <= x; i++){
    // 		if(x % i == 0){
    // 			if(x / i != x)s.insert(self(self, x / i));
    // 			if(i * i != x)s.insert(self(self, i));
    // 		}
    // 	}
    // 	int res = 0;
    // 	while(s.count(res))res++;
    // 	return m[x] = res;
    // };
    // for(int i = 1; i <= 300; i++){
    // 	dbg(i, sg(sg, i));
    // }
   	
    int ans = 0;
	for(int i = 1; i <= n; i++){
		//ans ^= sg(sg, a[i]);
		if(a[i] == 1)continue;
		int cnt = 0;
		for(int j = 2; j * j <= a[i]; j++){
			while(a[i] % j == 0){
				a[i] /= j;
				cnt++;
			}
		}
		if(a[i] != 1)cnt++;
		ans ^= cnt;
	}
	if(ans != 0)cout << "Anna\n";
	else cout << "Bruno\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}