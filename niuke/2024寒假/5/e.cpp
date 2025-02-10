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
	if(n%2==0){
		cout<<"YES\n";
		return ;
	}
	int k=0;
	for(int i=n-1;i>=1;i--){
		int temp1=a[i+1]+k*(i+1);
		int temp2=a[i]+k*i;
		if(temp2>temp1){
			cout<<"NO\n";
			return ;
		}
		if(i%2==1)continue;
		k+=(temp1-temp2)/i;
	}
	cout<<"YES\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}