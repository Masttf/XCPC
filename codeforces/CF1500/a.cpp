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
	int n;cin>>n;
	vector<int>a(n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	vector<int>x(mx*2+1),y(mx*2+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int d=a[i]+a[j];
			if(x[d]){
				if(i!=x[d]&&i!=y[d]&&j!=x[d]&&j!=y[d]){
					cout<<"YES\n";
					cout<<i<<' '<<j<<' '<<x[d]<<' '<<y[d]<<'\n';
					return ; 
				}
			}else{
				x[d]=i;
				y[d]=j;
			}
		}
	}
	cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}