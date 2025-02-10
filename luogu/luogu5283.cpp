#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int val,id,rk;
	node(int _val,int _id,int _rk):val(_val),id(_id),rk(_rk){}
	bool operator <(const node& y)const{
		return val<y.val;
	}
};
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
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	vector t(2,vector<int>((n+1)*35));
	vector<int>val((n+1)*35);
	int tot=0;
	auto ins = [&](int u,int v,int x)->void{
		for(int i=31;i>=0;i--){
			t[0][u]=t[0][v];
			t[1][u]=t[1][v];
			int d=x>>i&1;
			t[d][u]=++tot;
			u=t[d][u];
			v=t[d][v];
			val[u]=val[v]+1;
		}
	};

	auto ask = [&](int u,int x,int k)->int{
		int res=0;
		for(int i=31;i>=0;i--){
			int d=x>>i&1;
			d^=1;
			int sz=val[t[d][u]];
			if(sz>=k){
				res+=1ll<<i;
			}else{
				k-=sz;
				d^=1;
			}
			u=t[d][u];
		}
		return res;
	};

	vector<int>root(n+1);
	root[0]=++tot;
	ins(root[0],0,0);
	priority_queue<node>q;
	int ans=0;
	for(int i=1;i<=n;i++){
		root[i]=++tot;
		ins(root[i],root[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		q.push({ask(root[i],a[i],1),i,1});
	}
	for(int i=1;i<=m;i++){
		int res=q.top().val;
		int id=q.top().id;
		int rk=q.top().rk;
		q.pop();
		ans+=res;
		if(rk==n)continue;
		q.push({ask(root[id],a[id],rk+1),id,rk+1});
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}