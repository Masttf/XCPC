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
    int n, k; cin >> n >> k;
    deque<int> a;
    for(int i = 0; i < n; i++){
    	int x; cin >> x;
    	a.push_back(x);
    }
    for(int i = 1; i <= k; i++){
    	a.push_front(a.back());
    	a.pop_back();
    }
    while(!a.empty()){
    	cout << a.front() << ' ';
    	a.pop_front();
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