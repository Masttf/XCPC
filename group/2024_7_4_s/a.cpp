#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]=i-a[i];
	vector qq(n+1,vector<pair<int,int>>());
	vector<int>ans(q+1);
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		l=l+1;
		r=n-r;
		qq[r].push_back({l,i});
	}
	vector<int>tr(n+1);
	auto add = [&](int x,int val)->void{
		while(x<=n){
			tr[x]+=val;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=tr[x];
			x-=lowbit(x);
		}
		return res;
	};
	for(int i=1;i<=n;i++){
		if(a[i]>=0){
			int pos=0;
			int sum=0;
			for(int j=__lg(i);j>=0;j--){
				//dbg(i,j,pos);
				if(pos+(1<<j)<=i&&sum+tr[pos+(1<<j)]>=a[i]){
					sum+=tr[pos+(1<<j)];
					pos+=(1<<j);

				}
			}
			//dbg(i,pos);
			add(1,1);
			add(pos+1,-1);
			// int l=1,r=i;
			// int pos=-1;
			// while(l<=r){
			// 	int mid=(l+r)>>1;
			// 	//dbg(i,mid,ask(mid));
			// 	if(ask(mid)>=a[i]){
			// 		pos=mid;
			// 		l=mid+1;
			// 	}else r=mid-1;
			// }
			// if(pos!=-1){
			// 	add(1,1);
			// 	add(pos+1,-1);
			// }
			//dbg(i,pos);
		}
		for(auto [l,id]:qq[i]){
			ans[id]=ask(l);
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
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