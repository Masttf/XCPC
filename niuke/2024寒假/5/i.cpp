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
	int t,a,k;cin>>t>>a>>k;
	if(t==0){
		cout<<2*abs(a)<<'\n';
		return ;
	}
	if(t<0){
		t=-t;
		a=-a;
	}
	if(a>=t){
		cout<<a+a-t<<'\n';
		return ;
	}
	if(0<=a&&a<=t){
		cout<<t<<'\n';
		return ;
	}
	if(a<0){
		if(a<-k){
			cout<<t+2*(t-a)<<'\n';
			return ;
		}else{
			cout<<t-2*a<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}