#include<bits/stdc++.h>
#define int long long
#define Max 1e18
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
	int a,b,r;cin>>a>>b>>r;
	int d=0;
	for(int i=63;i>=0;i--){
		int d1=a>>i&1;
		int d2=b>>i&1;
		if(d1!=d2){
			if((1ll<<i)<=r){
				int nd=d+(d1<<i)-(d2<<i);
				int nnd=d+((1-d1)<<i)-((1-d2)<<i);
				if(abs(nd)>abs(nnd)){
					r-=1ll<<i;
					d=nnd;
				}else d=nd;
			}else{
				d+=(d1<<i)-(d2<<i);
			}
		}
		//dbg(i,d);
	}
	cout<<abs(d)<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}