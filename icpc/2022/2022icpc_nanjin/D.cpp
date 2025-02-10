#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
	std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
	std::cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,k,m,c,d;cin>>n>>k>>m>>c>>d;
	vector<int>a(n+1);
	vector<int>b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b.begin()+1,b.end(),greater<int>());
	vector<int>p(m);
	p[0]=c;
	for(int i=1;i<m;i++)p[i]=p[i-1]+d;
	auto check = [&](int x)->bool{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=x)cnt++;
		}
		vector<int>res(n+5);
		for(int i=1;i<=n;i++){
			if(a[i]>=x)continue;
			int temp=lower_bound(p.begin(),p.end(),x-a[i])-p.begin();
			temp=max(temp,0ll);
			if(temp>m-1)continue;
			int l=i-m+1,r=i-temp;
			l=max(1ll,l);
			if(r<l)continue;
			res[l]++;
			res[r+1]--;
		}
		for(int i=1;i<=n;i++)res[i]+=res[i-1];
		for(int i=1;i<=n;i++){
			if(res[i]+cnt>=k)return true;
		}
		return false;
	};
	int l=b[k],r=b[1]+c+(m-1)*d;
	
	int ans=-1;
	while(l<=r){
		//dbg(l,r);
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
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