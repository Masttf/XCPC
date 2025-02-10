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
	int l,r,val;
};
void solve(){
	int n;cin>>n;
	map<string,int>a;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		a[s]=i;
	}
	int m;cin>>m;
	vector<int>val(m+1);
	int ans1=0;
	vector<int>vis(n+1);
	for(int i=1;i<=m;i++){
		string s;cin>>s;
		if(a.count(s)){
			val[i]=a[s];
			if(!vis[val[i]])ans1++;
			vis[val[i]]=1;
		}
	}
	if(!ans1){
		cout<<0<<'\n'<<0<<'\n';
		return ;
	}
	// for(int i=1;i<=m;i++){
	// 	cout<<val[i]<<' ';
	// }
	// cout<<endl;
	int ans2=m;
	vector<node>tr(m*40);
	vector<int>root(m+1);
	int tot=0;
	auto updata = [&](auto self,int &u,int v,int l,int r,int x,int val)->void{
		//dbg(l,r,x,val);
		u=++tot;
		tr[u]=tr[v];
		if(l==r){
			tr[u].val=val;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x,val);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x,val);
		tr[u].val=tr[tr[u].l].val+tr[tr[u].r].val;
	};
	auto query = [&](auto self,int u,int v,int l,int r,int x,int y)->int{
		if(x<=l&&r<=y)return tr[u].val-tr[v].val;
		int mid=(l+r)>>1;
		int res=0;
		if(x<=mid)res+=self(self,tr[u].l,tr[v].l,l,mid,x,y);
		if(y>mid)res+=self(self,tr[u].r,tr[v].r,mid+1,r,x,y);
		return res;
	};
	vector<int>p(n+1);
	for(int i=1;i<=m;i++){
		if(val[i]==0)root[i]=root[i-1];
		else{
			if(!p[val[i]]){
				//dbg("t3");
				updata(updata,root[i],root[i-1],1,m,i,1);
			}else{
				int temp;
				//dbg("t1");
				updata(updata,temp,root[i-1],1,m,i,1);
				//dbg("t2",p[val[i]]);
				updata(updata,root[i],temp,1,m,p[val[i]],0);
			}
			p[val[i]]=i;
		}
	}
	//dbg("yes");
	//dbg(ans1);
	for(int i=1;i<=m;i++){
		int l=i,r=m;
		int res=-1;
		while(l<=r){
			//dbg(i,l,r);
			int mid=(l+r)>>1;
			if(query(query,root[mid],root[0],1,m,i,m)>=ans1){
				res=mid;
				r=mid-1;
			}else l=mid+1;
		}
		//dbg(i,res);
		if(res!=-1){
			ans2=min(ans2,res-i+1);
		}
	}
	cout<<ans1<<'\n'<<ans2<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}