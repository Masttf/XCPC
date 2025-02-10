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
int C(int m,int n){
	int res=1;
	for(int i=1;i<=m;i++)res=res*(n-i+1);
	int res2=1;
	for(int i=1;i<=m;i++)res2=res2*i;
	return res/res2;
}
void solve(){
	string s;cin>>s;
	vector<int>cnt(30);
	int n=s.size();
	s=' '+s;
	// for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
	// int ans=n*(n-1)/2;
	// int d=0;
	// for(int i=0;i<26;i++){
	// 	if(cnt[i]>1){
	// 		ans-=(cnt[i])*(cnt[i]-1)/2;
	// 	}
	// }
	int ans=0;
	for(int i=n;i>=1;i--){
		ans+=n-i;
		if(cnt[s[i]-'a'])ans-=cnt[s[i]-'a'];
		cnt[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]>1){
			ans++;
			break;
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}