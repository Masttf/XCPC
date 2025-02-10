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
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(a.begin()+1,a.end());
	int ans=Max;
	int res=-1;
	for(int i=1;i<=n;i++){
		int p=lower_bound(a.begin()+1,a.end(),b[i])-a.begin();
		if(p!=1){
			int d=abs(b[i]-a[p-1]);
			if(ans>d){
				ans=d;
				res=i;
			}
		}
		if(p!=n+1){
			int d=abs(b[i]-a[p]);
			if(ans>d){
				ans=d;
				res=i;
			}
		}
	}
	int p=lower_bound(a.begin()+1,a.end(),b[res])-a.begin();
	if(p!=1){
		int d=abs(b[res]-a[p-1]);
		if(ans==d){
			swap(a[res],a[p-1]);
			for(int i=1;i<=n;i++)cout<<a[i]<<' ';
			cout<<'\n';
			return ;
		}
	}
	if(p!=n+1){
		int d=abs(b[res]-a[p]);
		if(ans==d){
			swap(a[res],a[p]);
			for(int i=1;i<=n;i++)cout<<a[i]<<' ';
			cout<<'\n';
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