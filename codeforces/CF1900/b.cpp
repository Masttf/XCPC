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
	int a,b,c;cin>>a>>b>>c;
	a%=2;
	b%=2;
	c%=2;
	int cnt=0;
	if(a==1)cnt++;
	if(b==1)cnt++;
	if(c==1)cnt++;
	if(cnt==2){
		a=1-a;
		b=1-b;
		c=1-c;
	}else if(cnt==0){
		a=1;
		b=1;
		c=1;
	}
	cout<<a<<' '<<b<<' '<<c<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}