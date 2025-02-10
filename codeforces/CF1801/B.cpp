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
template<class T>
using  vec = std::vector<T>;
struct node{
	int l,r;
	bool operator <(const node &y)const{
		if(l!=y.l)return l<y.l;
		return r>y.r;
	}
};
void solve(){
	int n;cin>>n;
	vector<node>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r;
	sort(a.begin()+1,a.end());
	vector<int>suf(n+5);
	for(int i=n;i>=1;i--){
		suf[i]=max(suf[i+1],a[i].r);
	}
	int ans=1e18;
	set<int>s;
	for(int i=1;i<=n;i++){
		auto p=s.lower_bound(a[i].l);
		int mi=1e18;
		if(p!=s.end()){
			mi=min((*p)-a[i].l,mi);
		}
		if(p!=s.begin()){
			p--;
			mi=min(a[i].l-(*p),mi);
		}
		if(i<n)ans=min(ans,abs(a[i].l-suf[i+1]));
		if(i==n||suf[i+1]<=a[i].l)ans=min(ans,mi);
		s.insert(a[i].r);
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