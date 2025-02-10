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
constexpr int Max = 1e18;
void solve(){
    int n, p, q; cin >> n >> p >> q;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    for(int i = 1; i <=n; i++){
    	cin >> b[i];
    }
    int ans = 0;
    vector<int> bl(n + 5);
    priority_queue<pair<int, int>>q1, q2, q3, q4;
    q1.push({-Max, 0});
    q2.push({-Max, 0});
    q3.push({-Max, n + 1});
    q4.push({-Max, n + 2});
    bl[n + 1] = 1;
    bl[n + 2] = 2;
    for(int i = 1; i <= n; i++){
    	q1.push({a[i], i});
    	q2.push({b[i], i});
    }
    while(p || q){
    	while(bl[q1.top().second])q1.pop();
    	while(bl[q2.top().second])q2.pop();
    	while(bl[q3.top().second] != 1)q3.pop();
    	while(bl[q4.top().second] != 2)q4.pop();
    	int mx = 0, op = 0;
    	pair<int, int> c1 = q1.top(), c2 = q2.top(), c3 = q3.top(), c4 = q4.top();
    	if(p && c1.first > mx) mx = c1.first, op = 1;
    	if(q && c2.first > mx) mx = c2.first, op = 2;
    	if(q && c1.first + c3.first > mx) mx = c1.first + c3.first, op = 3;
    	if(p && c2.first + c4.first > mx) mx = c2.first + c4.first, op = 4;
    	ans += mx;
    	//dbg(p, q, op);
    	if(op == 1){
    		p--;
    		q1.pop();
    		int v = c1.second;
    		bl[v] = 1;
    		q3.push({b[v] - a[v], v});
    	}else if(op == 2){
    		q--;
    		q2.pop();
    		int v = c2.second;
    		bl[v] = 2;
    		q4.push({a[v] - b[v], v});
    	}else if(op == 3){
    		q--;
    		q1.pop();
    		q3.pop();
    		int u = c1.second;
    		int v = c3.second;
    		bl[u] = 1;
    		bl[v] = 2;
    		q3.push({b[u] - a[u], u});
    		q4.push({a[v] - b[v], v});
    	}else{
    		p--;
    		q2.pop();
    		q4.pop();
    		int u = c2.second;
    		int v = c4.second;
    		bl[u] = 2;
    		bl[v] = 1;
    		q4.push({a[u] - b[u], u});
    		q3.push({b[v] - a[v], v});
    	}
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++){
    	if(bl[i] == 1)cout << i << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
    	if(bl[i] == 2)cout << i << ' ';
    }
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