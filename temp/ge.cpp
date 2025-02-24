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
    int n = 5;
    cout << n << '\n';
    srand(time(0));
    for(int i = 1; i <= n; i++){
    	cout << rand() << ' ';
    }
    cout << '\n';
    for(int i = 1; i <= n; i++){
    	cout << rand() << ' ';
    }
    cout << '\n';
    int q = 5;
    cout << q << '\n';
    for(int i = 1; i <= 5; i++){
    	cout << 1 << ' ' << i << '\n';
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    cout << 0 << '\n';
    while(t--)solve();
    return 0;
}