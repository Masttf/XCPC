#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	int n;cin>>n;
	vector<string>a(n);
	for(int i=0;i<n;i++)cin>>a[i];

	vector<int>rcnt(n+1);
	vector<int>ccnt(n+1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]=='o'){
				rcnt[i]++;
				ccnt[j]++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]=='o'){
				ans+=(rcnt[i]-1)*(ccnt[j]-1);
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