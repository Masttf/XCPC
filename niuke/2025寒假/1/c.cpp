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
    int n; cin >> n;
    vector<string> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i] = ' ' + a[i];
    }
    vector<array<int, 4>> ans;
    
    auto swp = [&](int x0, int y0, int x1, int y1) -> void{
        ans.push_back({x0, y0, x1, y1});
        swap(a[x0][y0], a[x1][y1]);
    };
    auto run = [&](int x, int y, int nx, int ny) -> void{
        auto mx = [&]() -> void{
            while(x < nx){
                swp(x, y, x + 1, y);
                x++;
            }
            while(x > nx){
                swp(x, y, x - 1, y);
                x--;
            }
        };
        auto my = [&]() -> void{
            while(y < ny){
                swp(x, y, x, y + 1);
                y++;
            }
            while(y > ny){
                swp(x, y, x, y - 1);
                y--;
            }
        };
        if(x >= nx){
            my();
            mx();
        }else{
            mx();
            my();
        }
    };
    auto pf = [&]() -> void{
    	for(int i = 1; i <= n; i++){
	    	cout << a[i] << '\n';
	    }
        cout << endl;
    };
    int nx = 1, ny = 1;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){;
    		while(a[i][j] == '1'){
    			run(i, j, nx, ny);
                a[nx][ny] = '2';
                // pf();
                ny++;
                if(ny > n / 2){
                    nx++;
                    ny = 1;
                }
    		}
    	}
    }
    cout << ans.size() << '\n';
    int sz = ans.size();
    for(auto [x0, y0, x1, y1] : ans){
    	cout << x0 << ' ' << y0 << ' ' << x1 << ' ' << y1 << '\n';
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
模拟

2 * n * 
100 * 25


*/