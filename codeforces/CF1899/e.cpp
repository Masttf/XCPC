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
	int n;cin>>n;
	vector<int>a(n+1);
	int mi=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[mi]>a[i])mi=i;
	}
	int mmi=INT_MAX;
	int p=0;
	for(int i=n;i>=1;i--){
		if(a[i]>mmi){
			p=i;
			break;
		}
		mmi=min(mmi,a[i]);
	}
	if(p>mi)cout<<-1<<'\n';
	else cout<<p<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}