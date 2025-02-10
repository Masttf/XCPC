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
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>res;
	int last=a[n];
	res.push_back(last);
	for(int i=n-1;i>=1;i--){
		if(a[i]>last){
			if(a[i]<10)res.push_back(a[i]),last=a[i];
			else{
				res.push_back(a[i]%10);
				res.push_back(a[i]/10);
				last=a[i]/10;
			}
		}else res.push_back(a[i]),last=a[i];
	}
	int ok=1;
	int sz=res.size();
	for(int i=0;i<sz-1;i++){
		//dbg(i,res[i]);
		if(res[i]<res[i+1])ok=0;
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