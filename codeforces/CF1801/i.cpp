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
	vector<int>a(7);
	for(int i=1;i<=6;i++){
		string s;cin>>s;
		if(s[0]=='t')a[i]=1;
	}
	int cnt=0;
	for(int i=1;i<=3;i++){
		if(a[i]!=a[i+3])cnt++;
	}
	if(cnt==0) {
		if(a[1] != a[2] and a[2] != a[3]) cout << 7 << '\n';
		else cout << 8 << '\n';
	}
	else if(cnt==3)cout<<4<<'\n';
	else if(cnt==2)cout<<5<<'\n';
	else cout<<6<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}