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
void err(T arg, Ts &... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	int ans=0;
	vector<int>cnt(30);
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n&&s[i]==s[j])j++;
		cnt[s[i]-'a']=max(cnt[s[i]-'a'],j-i);
		i=j-1;
	}
	for(int i=0;i<26;i++)ans+=cnt[i];
	cout<<ans;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}