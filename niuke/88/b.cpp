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
const int Max=1e18;
void solve(){
	vector<string>a(10);
	for(int i=1;i<=5;i++){
		getline(cin,a[i]);
		//cin>>a[i];
		a[i]=' '+a[i];
		//dbg(a[i]);
	}
	//char t=a[3][6];
	//cout<<t<<endl;
	if(a[3][1]!=' '){
		int ans=a[3][1]-'0';
		cout<<1-ans<<'\n';
		return ;
	}
	int x=a[2][1]-'0';
	int y=a[4][1]-'0';

	if(a[3][6]=='&'){
		int ans=x&y;
		//dbg("yes");
		cout<<ans<<'\n';
		return ;
	}
	int ans=x|y;
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