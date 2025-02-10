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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    for(int i = 1; i <= q; i++){
    	int l, r; cin >> l >> r;
    	if(r - l >= 50){
    		cout << "Yes\n";
    		continue;
    	}else{
    		vector<int>temp(r - l + 2);
    		for(int j = l; j <= r; j++){
    			temp[j - l + 1] = a[j];
    		}
    		auto check = [&](int x, int y, int z) -> bool{
    			if(z >= x + y)return false;
    			return true;
    		};
    		sort(temp.begin() + 1, temp.end());
    		int len = r - l + 1;
    		vector<int>dp(len + 1);
    		for(int j = 3; j <= len; j++){
    			dp[j] = dp[j - 1];
    			if(check(temp[j - 2], temp[j - 1], temp[j])){
    				dp[j] = max(dp[j], dp[j - 3] + 1);
    			}
                if(j >= 6){
                    for(int k = j - 5; k <= j ; k++){
                        for(int kk = k + 1; kk <= j; kk++){
                            for(int kkk = kk + 1; kkk <= j; kkk++){
                                int p[4], c = 0;
                                for(int ll = j - 5; ll <= j; ll++){
                                    if(ll != k && ll != kk && ll != kkk){
                                        p[++c] = temp[ll];
                                    }
                                }
                                if(check(temp[k], temp[kk], temp[kkk]) && check(p[1], p[2], p[3])){
                                    dp[j] = max(dp[j], dp[j - 6] + 2);
                                }
                            }
                        }
                    }
                }
    		}
    		if(dp[len] >= 2)cout << "Yes\n";
    		else cout << "No\n";
    		
    	}

    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}