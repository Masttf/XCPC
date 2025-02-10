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
    int n, q; cin >> n >> q;
    int tot = __lg(n);
    vector<int>p(n + 1);
    for(int i = 2; i <= n; i++){
    	cin >> p[i];
    }
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	pos[a[i]] = i;
    }
    set<int>s;
    auto check = [&](int x) -> bool{
    	if(x <= 0)return true;
    	int l = x << 1;
    	int r = x << 1 | 1;
    	if(l > n)return true;
    	if(pos[l] - 1 != pos[x] && pos[r] - 1 != pos[x])return false;
    	else{
    		int d = __lg(l);
    		int sz = (1ll << (tot - d + 1)) - 1;
    		if(pos[l] - 1 == pos[x]){
    			if(pos[r] - pos[l] != sz)return false;
    		}else{
    			if(pos[l] - pos[r] != sz)return false;
    		}
    	}
    	return true;
    };
    for(int i = 1; i <= n; i++){
    	if(!check(i)){
    		s.insert(i);
    	}
    }
    for(int i = 1; i <= q; i++){
    	int x, y; cin >> x >> y;
    	swap(pos[a[x]], pos[a[y]]);
    	swap(a[x], a[y]);
    	s.insert(a[x]);
    	s.insert(a[y]);
    	s.insert(a[x] / 2);
    	s.insert(a[y] / 2);
    	if(check(a[x])){
    		s.erase(a[x]);
    	}
    	if(check(a[y])){
    		s.erase(a[y]);
    	}
    	if(check(a[x] / 2)){
    		s.erase(a[x] / 2);
    	}
    	if(check(a[y] / 2)){
    		if(s.count(a[y] / 2))s.erase(a[y] / 2);
    	}
    	if(s.empty())cout << "Yes\n";
    	else cout << "No\n";
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}