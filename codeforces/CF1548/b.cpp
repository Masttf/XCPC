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
	vector<int>b(n);
	for(int i=1;i<n;i++){
		b[i]=abs(a[i]-a[i+1]);
	}
	n--;
	int d=__lg(n);
	vector st(d+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		st[0][i]=b[i];
	}
	for(int s=1;s<=d;s++){
		for(int i=1;i+(1<<s)<=n+1;i++){
			st[s][i]=__gcd(st[s-1][i],st[s-1][i+(1<<(s-1))]);
		}
	}
	auto get = [&](int l,int r)->int{
		int len=r-l+1;
		int k=__lg(len);
		int res=__gcd(st[k][l],st[k][r-(1<<k)+1]);
		return res;
	};
	// dbg(get(3,4));
	// dbg(st[1][3]);
	auto check = [&](int len)->bool{
		for(int i=1;i+len-1<=n;i++){
			int res=get(i,i+len-1);
			if(res>=2)return true;
		}
		return false;
	};
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		//dbg(l,r);
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans+1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}