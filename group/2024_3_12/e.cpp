#include<bits/stdc++.h>
//#define int long long
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
struct node{
	int l,r,id;
	bool operator <(const node&y)const{
		if(r!=y.r)return r<y.r;
		return l>y.l;
	}
};
struct node2{
	int l,r,sum;
};
void solve(){
	int n,k;cin>>n>>k;
	vector<node>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++){
		int l,r;cin>>l>>r;
		p.push_back(l);
		a[i]={l,r,i};
	}
	sort(a.begin()+1,a.end());
	// for(int i=1;i<=n;i++){
	// 	cout<<a[i].l<<' '<<a[i].r<<'\n';
	// }
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};

	vector<node2>tr(n*40);
	vector<int>root(n+1);
	int tot=0;
	auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].sum++;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x);
	};
	auto query = [&](auto self,int u,int v,int l,int r,int k)->int{
		//dbg(l,r);
		if(l==r){
			return p[l-1];
		}
		int d=tr[tr[u].l].sum-tr[tr[v].l].sum;
		int mid=(l+r)>>1;
		if(k>d)return self(self,tr[u].r,tr[v].r,mid+1,r,k-d);
		else return self(self,tr[u].l,tr[v].l,l,mid,k);
	};
	for(int i=1;i<=n;i++){
		updata(updata,root[i],root[i-1],1,n,get(a[i].l));
	}
	int ans=-1;
	int mxi=-1;
	for(int i=1;i+k-1<=n;i++){
		if(k==1){
			if(a[i].r-a[i].l+1>ans){
				ans=a[i].r-a[i].l+1;
				mxi=i;
			}
		}else{
			int l=query(query,root[n],root[i],1,n,k-1);
			//dbg(l);
			l=max(l,a[i].l);
			int d=max(0ll,1ll*a[i].r-l+1);
			//dbg(i,d,l);
			if(d>ans){
				ans=d;
				mxi=i;
			}
		}
	}
	if(k==1){
		cout<<ans<<'\n';
		cout<<a[mxi].id<<'\n';
	}else{
		//dbg("yes",mxi);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		vector<int>res;
		res.push_back(a[mxi].id);
		for(int i=mxi+1;i<=n;i++){
			q.push({a[i].l,a[i].id});
		}
		for(int i=1;i<k;i++){
			auto [val,id]=q.top();
			q.pop();
			res.push_back(id);
		}
		sort(res.begin(),res.end());
		cout<<ans<<'\n';
		for(auto x:res)cout<<x<<' ';
		cout<<'\n';
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