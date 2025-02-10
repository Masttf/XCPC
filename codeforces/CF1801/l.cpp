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
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	vector<int>nt(n+1);
	int j=0;
	int ok=0;
	for(int i=2;i<=n;i++){
		while(j&&s[i]!=s[j+1])j=nt[j];
		if(s[i]==s[j+1])j++;
		nt[i]=j;
		if(nt[i])ok=1;
	}
	if(ok)cout<<"Wrong Answer\n";
	else cout<<"Correct\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}