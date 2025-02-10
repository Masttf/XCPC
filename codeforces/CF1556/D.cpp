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
	int n,k;cin>>n>>k;
	vector<int>val(n+1);
	for(int i=2;i<=n;i++){
		int x1,x2;
		cout<<"and "<<1<<' '<<i<<endl;
		cin>>x1;
		cout<<"or "<<1<<' '<<i<<endl;
		cin>>x2;
		val[i]=x1+x2;
	}
	int x1,x2;
	cout<<"and "<<2<<' '<<3<<endl;
	cin>>x1;
	cout<<"or "<<2<<' '<<3<<endl;
	cin>>x2;
	int x=x1+x2;
	int d=x-val[2];
	val[1]=(val[3]-d)/2;
	for(int i=2;i<=n;i++)val[i]-=val[1];
	sort(val.begin()+1,val.end());
	cout<<"finish "<<val[k]<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}