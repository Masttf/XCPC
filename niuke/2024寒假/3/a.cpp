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
void solve(){
	string a,b;cin>>a>>b;
	if(a[0]>='A'&&a[0]<='Z'){
		a[0]=a[0]-'A'+'a';
	}
	if(b[0]>='A'&&b[0]<='Z'){
		b[0]=b[0]-'A'+'a';
	}
	if(a[0]==b[0])cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}