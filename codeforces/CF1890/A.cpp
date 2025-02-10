#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	map<int,int>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		m[x]++;
	}
	if(m.size()>2){
		cout<<"NO\n";
	}else if(m.size()==1){
		cout<<"YES\n";
	}else{
		int d=n/2;
		int ok=1;
		for(auto it=m.begin();it!=m.end();it++){
			if(it->second==d)ok=0;
		}
		if(!ok)cout<<"YES\n";
		else cout<<"NO\n";
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