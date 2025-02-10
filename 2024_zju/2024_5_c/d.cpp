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
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<__int128>d(n+5);
	vector<__int128>pre(n+5);
	int s=1;
	while(s<=n&&a[s]==0)s++;
	if(s>n){
		cout<<0<<'\n';
	}else{
		cout<<2*n+n-s+1<<'\n';
		for(int i=1;i<=2*n;i++){
			cout<<s<<' ';
			d[s+1]+=a[s];
		}
		for(int i=s;i<=n;i++){
			cout<<i<<' ';
			pre[i]=pre[i-1]+d[i];
			d[i+1]+=pre[i];
		}
		cout<<'\n';
		// int ok1=1,ok2=1;
		// for(int i=2;i<=n;i++){
		// 	if(pre[i]-pre[i-1])
		// }
		for(int i=1;i<=n;i++){
			vector<int>temp;
			int flag=0;
			if(pre[i]<0){
				flag=1;
				pre[i]=-pre[i];
			}
			while(pre[i]){
				temp.push_back(pre[i]%10);
				pre[i]/=10;
			}
			reverse(temp.begin(),temp.end());
			if(flag)cout<<'-';
			for(auto x:temp)cout<<x;
			cout<<' ';
			//cout<<pre[i]<<' ';
		}
		cout<<'\n';
		cout<<'\n';
		for(int i=1;i<=n;i++){
			if(pre[i]>0)assert(pre[i]<=Max);
			if(pre[i]<0)assert(pre[i]>=-Max);
			
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