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
    int n, m; cin >> n >> m;
    string a; cin >> a;
    string b; cin >> b;
    vector<int> cnta(26), cntb(26);
    for(auto x : a){
    	cnta[x - 'a']++;
    }
    for(auto x : b){
    	cntb[x - 'a']++;
    }
    auto run = [&]() -> int{
    	int res = 0;
    	int pos = (n + m + 1) / 2;
    	int need = n - pos;//分 need个给b
    	int sum = 0;
    	for(int i = 0; i < 26; i++){
    		if(cntb[i] > cnta[i]){
    			res += cntb[i] - cnta[i];
    		}
    	}
    	int ans = res;
    	for(int i = 0; i < 26; i++){
    		if(cnta[i] > cntb[i]){
    			int d = cnta[i] - cntb[i];
    			int num = d / 2;
    			if(need >= num){
    				need -= num;
    				d -= num * 2;
    			}else{
    				d -= need * 2;
    				need = 0;
    			}
    			sum += d;
    		}
    	}
    	sum -= res;
    	ans += sum / 2;
    	return ans;
    };
    int len = (n + m);
    int pos = (n + m) / 2;
    pos += len % 2;
    if(n < pos){
    	swap(n, m);
    	swap(cnta, cntb);
    	swap(a, b);
    }
    int ans = (n + m);
    if(len % 2 == 1){
    	for(int i = 0; i < 26; i++){
    		if(cnta[i]){
    			cnta[i]--;
    			ans = min(ans, run());
    			cnta[i]++;
    		}
    	}
    }else ans = run();
    cout << ans << '\n';
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
回文
先确定中心？
长度是 （n + m）
如果是奇数
中间一个没用字母
也就是说只需要统计字母个数即可

每个字母个数都一样多

*/