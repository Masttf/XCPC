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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2){
    	swap(x1, x2);
    	swap(y1, y2);
    }
    if(x1 == x2){
    	cout << x1 + 1 << ' ' << y1 << '\n';
    	return ;
    }
    if(y1 == y2){
    	cout << x1 << ' ' << y1 + 1<< '\n';
    	return ;
    }
    pair<int, int>res;
    int ans = 1e18;
    
    auto get = [&](int x3, int y3) -> int{
        if((y1 - y3) * (x2 - x3) == (y2 - y3) * (x1 - x3))return 1e18;
        int temp=abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
        return temp;

    };
    for(int i = x1; i <= x2; i++){
        for(int j = min(y1, y2); j <= max(y1, y2); j++){
            int d = get(i, j);
            if(d < ans){
                ans = d;
                res = {i, j};
            }
        }
    }
    cout << res.first << ' ' << res.second << '\n';
    dbg(ans);
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}