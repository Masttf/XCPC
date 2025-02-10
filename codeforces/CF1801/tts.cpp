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
	auto get = [&](string s,string t)->int{
		int n=s.size();
		int m=t.size();
		s=' '+s;
		t=' '+t;
		int j=1;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]!=t[j])j=1;
			if(s[i]==t[j]){
				j++;
			}
			if(j>m){
				ans++;
				j=1;
			}
		}
		return ans;
	};
	string ss,tt;cin>>ss>>tt;
	cout<<get(ss,tt)<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}