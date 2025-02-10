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
mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	map<int,int>res;
	vector<int>val(n+1);
	for(int i=1;i<=n;i++){
		val[i]=rnd();
	}
	int mx=0;
	for(int i=1;i<=m;i++){
		int rs=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]=='1')rs^=val[j];
		}
		for(int j=1;j<=n;j++){
			res[rs^val[j]]++;
			mx=max(mx,res[rs^val[j]]);
		}
	}
	cout<<mx<<'\n';
	for(int i=1;i<=m;i++){
		int rs=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]=='1')rs^=val[j];
		}
		for(int j=1;j<=n;j++){
			if(res[rs^val[j]]==mx){
				for(int k=1;k<=n;k++){
					if(k==j){
						if(a[k][i]=='0')cout<<1;
						else cout<<0;
					}else{
						if(a[k][i]=='1')cout<<1;
						else cout<<0;
					}
					
				}
				cout<<'\n';
				return ;
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