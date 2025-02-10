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
		int ans=0;
		for(int i=1;i<n;i++){
			if(a[i]>a[i+1]){
				ans=max(ans,a[i]-a[i+1]);
			}
		}
		cout<<ans<<'\n';
		return ;
	}
	int k=0;
	vector<int>res(n+1);
	for(int i=n-1;i>=1;i--){
		int temp1=a[i+1]+k*(i+1);
		int temp2=a[i]+k*i;
		if(temp2>temp1){
			cout<<"-1\n";
			return ;
		}
		if(i%2==0){
			k+=(temp1-temp2)/i;
		}
		res[i]=k;
	}
	auto check = [&](int kk)->bool{
		vector<int>t(n+1);
		for(int i=1;i<=n;i++){
			t[i]=min(kk,res[i]);
		}
		for(int i=1;i<n;i++){
			int temp1=a[i]+i*t[i];
			int temp2=a[i+1]+(i+1)*t[i+1];
			if(temp1>temp2)return false;
		}
		return true;
	};
	int ans=res[1];
	int l=0,r=res[1];
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}