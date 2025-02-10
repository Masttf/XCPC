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
int temp[] = {1,2,2,3,3,4};
void solve(){
    int n; cin >> n;
    vector<int>ans(n);
    for(int i = 0; i < n; i++){
    	ans[i] = i % 4 + 1;
    }
    if(n <= 6){
    	set<int>s;
    	for(int i = 0; i< n; i++){
    		s.insert(temp[i]);
    	}
    	cout << s.size() << '\n';
    	for(int i = 0; i< n; i++){
    		cout << temp[i] << ' ';
    	}
    	cout << '\n';
    }else{
    	cout << 4 << '\n';
    	for(int i = 0; i < n; i++){
    		cout << ans[i] << ' ';
    	}
    	cout << '\n';
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