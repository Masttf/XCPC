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
	int x,k;cin>>x>>k;
	map<int,int>m;
	int ans=0;
	int temp=x;
	while(temp>1&&k>=0){
		ans++;
		if(!m.count(temp*temp)){
			ans+=k;
		}
		m[temp]=1;
		k--;
		temp=sqrt(temp);
	}

	if(temp==1&&k>=0)ans++;
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