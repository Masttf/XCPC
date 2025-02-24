#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n, w;
	cin >> n >> w;
	vector<int>cnt(14);
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		cnt[x]++;
	}
	sort(cnt.begin()+1,cnt.end());
	vector<int>res;
	int ans=0;
	// for(int i=13;i>=1;i--){
	// 	if(res.empty()){
	// 		res.push_back(w-cnt[i]);
	// 		ans++;
	// 	}else{
	// 		int ok=0;
	// 		for(auto &x:res){
	// 			if(x>=cnt[i]){
	// 				x-=cnt[i];
	// 				ok=1;
	// 				break;
	// 			}
	// 		}
	// 		if(!ok){
	// 			ans++;
	// 			res.push_back(w-cnt[i]);
	// 		}
	// 	}
	// }
	for(int i = 13; i >= 1; --i) {
		if(cnt[i] != 0) ++ans;
		else continue;
		int last = w;
		for(int j = i; j >= 1; --j) {
			if(cnt[j] <= last) last -= cnt[j], cnt[j] = 0;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}