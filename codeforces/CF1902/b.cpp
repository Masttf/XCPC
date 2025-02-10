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
	int n,p,l,t;cin>>n>>p>>l>>t;
	int tot=(n-1)/7;
	tot++;
	//dbg(tot);
	if(tot%2==0){
		int res=(tot/2)*(2*t+l);
		if(res>=p){
			cout<<n-(p+2*t+l-1)/(2*t+l)<<'\n';
		}else{
			int d=p-res;
			int ans=(d+l-1)/l+tot/2;
			cout<<n-ans<<'\n';
		}
	}else{
		int res=(tot/2)*(2*t+l);
		if(res>=p){
			cout<<n-(p+2*t+l-1)/(2*t+l)<<'\n';
		}else{
			res+=t+l;
			if(res>=p)cout<<n-tot/2-1<<'\n';
			else{
				int d=p-res;
				int ans=(d+l-1)/l+tot/2+1;
				cout<<n-ans<<'\n';
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}