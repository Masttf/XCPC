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
    int a, b, c, d; cin >> a >> b >> c >> d;
    auto pf = [&](int x, int y) -> void{
    	cout << x << ' ' << y << '\n';
    };
    if(b - a == 1 && d - c == 1){
    	pf(a, c);
    	pf(a, d);
    	pf(b, d);
    	return ;
    }
    if(b - a >= d - c){
    	pf(a, d);
    	pf(a + 1, d);
    	pf(b, d - 1);
    }else{
    	pf(b - 1, c);
    	pf(b, d - 1);
    	pf(b, d);
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
/*
r max
圆上三点如何确定半径
两个点做中垂线交于圆心

*/