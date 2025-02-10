#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	vector<int>cnt(30);
	for(int i=1;i<=n;i++){
		cnt[s[i]-'a']++;
	}
	int mx=0;
	for(int i=0;i<26;i++)mx=max(cnt[i],mx);
	if(mx>n/2){
		cout<<2*mx-n<<'\n';
		return ;
	}else{
		cout<<n%2<<'\n';
		return ;
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