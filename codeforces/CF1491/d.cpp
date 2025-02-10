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
	int l,r;cin>>l>>r;
	if(l>r){
		cout<<"NO\n";
		return ;
	}
	int cnt=0;
	int ok=1;
	for(int i=0;i<=30;i++){
		int d1=l>>i&1;
		int d2=r>>i&1;
		if(d1==d2)continue;
		if(d1==1)cnt++;
		else{
			if(cnt)cnt--;
			else ok=0;
		}
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}