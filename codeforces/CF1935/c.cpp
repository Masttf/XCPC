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
struct node{
	int v1,v2;
	bool operator <(const node&y)const{
		if(v2!=y.v2)return v2<y.v2;
		return v2<y.v2;
	}
};
struct node2{
	int l,r,val,cnt;
};
void solve(){
	int n,l;cin>>n>>l;
	vector<node>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		p.push_back(x);
		a[i]={x,y};
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	sort(a.begin()+1,a.end());
	// for(int i=1;i<=n;i++){
	// 	cout<<a[i].v1<<' '<<a[i].v2<<'\n';
	// }
	vector<int>root(n+1);
	vector<node2>tr(n*40);
	int tot=0;
	auto updata = [&](auto self,int &u,int v,int l,int r,int k,int x)->void{
		//dbg(l,r,k,x);
		u=++tot;
		tr[u]=tr[v];
		tr[u].val+=x;
		tr[u].cnt++;
		if(l==r){
			return ;
		}
		int mid=(l+r)>>1;
		if(k<=mid)self(self,tr[u].l,tr[v].l,l,mid,k,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,k,x);
	};
	auto query = [&](auto self,int u,int v,int l,int r,int sum)->int{
		//dbg(l,r,sum);
		if(l==r){
			int d=p[l-1];
			int kk=sum/d;
			return min(kk,tr[u].cnt-tr[v].cnt);
		}
		int mid=(l+r)>>1;
		int d=tr[tr[u].l].val-tr[tr[v].l].val;
		//dbg(l,r,d,sum);
		if(sum>d)return tr[tr[u].l].cnt-tr[tr[v].l].cnt+self(self,tr[u].r,tr[v].r,mid+1,r,sum-d);
		else return self(self,tr[u].l,tr[v].l,l,mid,sum);
	};
	for(int i=1;i<=n;i++){
		//dbg(i);
		updata(updata,root[i],root[i-1],1,n,get(a[i].v1),a[i].v1);
	}
	//dbg("yes");
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].v1<=l)ans=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			int sum=a[i].v1+a[j].v1+a[i].v2-a[j].v2;
			if(sum>l)continue;
			if(j==i-1){
				ans=max(ans,2ll);
			}else{
				//dbg(i,j);
				int d=query(query,root[i-1],root[j],1,n,l-sum);
				ans=max(ans,d+2);
			}
			
		}
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