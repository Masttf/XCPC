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
	int n,k;cin>>n>>k;
	int ans=1;
	for(int i=k-1;i>=0;i--){
		int d=n>>i&1;
		int cnt=0;
		for(int j=0;j<=1;j++){
			for(int k=0;k<=1;k++){
				for(int p=0;p<=1;p++){
					for(int q=0;q<=1;q++){
						if((((j&k)^p)|q)==d)cnt++;
					}
				}
			}
		}
		ans*=cnt;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}