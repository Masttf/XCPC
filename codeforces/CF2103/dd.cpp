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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int mx = 0;
    for(int i = 1; i <= n; i++){
        mx = max(mx, a[i]);
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == -1){
            a[i] = mx + 1;
            break;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     cout << a[i] << " \n"[i == n];
    // }
    // cout << endl;
    mx++;
    vector<int> ans(n + 1);
    auto run = [&](auto self, int L, int R, int now, vector<int> pos){
        // dbg(L, R);
        // if(pos.empty() || L > R){
        //     dbg(">????");
        //     return ;
        // }
        if(L == R){
            ans[pos[0]] = L;
            return ;
        }
        if(now % 2 == 1){
            vector<int> temp;
            for(auto x : pos){
                if(a[x] > now){
                    temp.push_back(x);
                }
            }
            int l = temp[0];
            int r = temp.back();
            for(auto x : pos){
                if(a[x] > now)continue;
                if(x < l){
                    ans[x] = R--;
                }
            }
            for(auto it = pos.begin(); it != pos.end(); it++){
                int x = *it;
                if(a[x] > now)continue;
            }
            for(auto it = pos.rbegin(); it != pos.rend(); it++){
                int x = *it;
                if(a[x] > now)continue;
                if(x > r){
                    ans[x] = R--;
                }
            }
            for(auto x : pos){
                if(a[x] > now)continue;
                if(x >= l && x <= r){
                    ans[x] = R--;
                }
            }
            self(self, L, R, now + 1, temp);
        }else{
            vector<int> temp;
            for(auto x : pos){
                if(a[x] > now){
                    temp.push_back(x);
                }
            }
            int l = temp[0];
            int r = temp.back();
            for(auto x : pos){
                if(a[x] > now)continue;
                if(x < l){
                    ans[x] = L++;
                }
            }
            for(auto it = pos.rbegin(); it != pos.rend(); it++){
                int x = *it;
                if(a[x] > now)continue;
                if(x > r){
                    ans[x] = L++;
                }
            }
            for(auto x : pos){
                if(a[x] > now)continue;
                if(x >= l && x <= r){
                    ans[x] = L++;
                }
            }
            self(self, L, R, now + 1, temp);
        }

    };
    vector<int> pos;
    for(int i = 1; i <= n; i++){
        pos.push_back(i);
    }
    run(run, 1, n, 1, pos);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i == n];
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