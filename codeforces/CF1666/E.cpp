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
	int len,n;cin>>len>>n;
	vector<int>a(n+2);
	a[n+1]=len;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0<<' '<<len<<'\n';
		return ;
	}
	auto check2 = [&](int x)->bool{
		int l=0;
		for (int i = 1;i <= n;i++) {
			l=max(l+x,a[i]);
			if(l>a[i+1]) return 0;
		}
		return 1;
	};
	auto check = [&](int mi,int mx)->bool{
		int l=0,r=0;
		for(int i=1;i<=n;i++){
			l=max(l+mi,a[i]);
			r=min(r+mx,a[i+1]);
			if(l>r)return false;
		}
		return l<=len&&len<=r;
	};
	int mi=-1,mx=-1;
	int l=0,r=len;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check2(mid)){
			mi=mid;
			l=mid+1;
		}else r=mid-1;
	}
	l=mi,r=len;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mi,mid)){
			if(mx==-1||mid<mx){
				mx=mid;
			}
			r=mid-1;
		}else l=mid+1;
	}
	
	vector<pair<int,int>>ans;
	vector<int>resl(n+1);
	vector<int>resr(n+1);
	l=0,r=0;
	for(int i=1;i<=n;i++){
		resl[i]=l;
		resr[i]=r;
		l=max(l+mi,a[i]);
		r=min(r+mx,a[i+1]);
	}
	int last=len;
	for(int i=n;i>=1;i--){
		int ll=max(resl[i],last-mx);
		int rr=min(resr[i],last-mi);
		ans.push_back({ll,last});
		last=ll;
	}
	reverse(ans.begin(),ans.end());
	for(auto [x,y]:ans)cout<<x<<' '<<y<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}