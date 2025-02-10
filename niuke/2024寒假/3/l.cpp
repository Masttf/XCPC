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
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			__int128 res=a[i];
			int d=a[j];
			while(d){
				res=res*10;
				d/=10;
			}
			res+=a[j];
			if(res%36==0){
				ans++;
				cout<<i<<' '<<j<<'\n';
				vector<int>temp;
				while(res){
					temp.push_back(res%10);
					res/=10;
				}
				reverse(temp.begin(),temp.end());
				for(auto x:temp)cout<<x;
				cout<<'\n';
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
//82596182084415629686507012905463560