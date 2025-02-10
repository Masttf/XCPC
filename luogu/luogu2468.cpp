#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct node{
	int l,r,sum,val;
};
const int maxn=205;
int cnt[maxn][maxn][1001];
int val[maxn][maxn][1001];
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
	int n,m,q;cin>>n>>m>>q;
	vector a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	if(n!=1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=1000;k++){
					cnt[i][j][k]=cnt[i-1][j][k]+cnt[i][j-1][k]-cnt[i-1][j-1][k]+(a[i][j]>=k?1:0);
					val[i][j][k]=val[i-1][j][k]+val[i][j-1][k]-val[i-1][j-1][k]+(a[i][j]>=k?a[i][j]:0);
				}
			}
		}
		auto ask = [&](int x,int y,int xx,int yy,int k)->int{
			return val[xx][yy][k]-val[x-1][yy][k]-val[xx][y-1][k]+val[x-1][y-1][k];
		};
		for(int i=1;i<=q;i++){
			int x,y,xx,yy,k;cin>>x>>y>>xx>>yy>>k;
			int res=-1;
			int l=1,r=1000;
			while(l<=r){
				int mid=(l+r)>>1;
				if(ask(x,y,xx,yy,mid)>=k){
					res=mid;
					l=mid+1;
				}else r=mid-1;
			}
			if(res==-1)cout<<"Poor QLW\n";
			else{
				int ans=cnt[xx][yy][res]-cnt[x-1][yy][res]-cnt[xx][y-1][res]+cnt[x-1][y-1][res];
				int tot=ask(x,y,xx,yy,res);
				ans-=(tot-k)/res;
				cout<<ans<<'\n';
			}
		}
	}else{
		vector<int>root(m+1);
		vector<node>tr(m*20);
		int tot=0;
		auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
			u=++tot;
			tr[u]=tr[v];
			tr[u].sum++;
			tr[u].val+=x;
			if(l==r)return ;
			int mid=(l+r)>>1;
			if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
			else self(self,tr[u].r,tr[v].r,mid+1,r,x);
		};
		auto query = [&](auto self,int u,int v,int l,int r,int k)->int{
			if(l==r)return (k+l-1)/l;
			int mid=(l+r)>>1;
			int d=tr[tr[u].r].val-tr[tr[v].r].val;
			if(k>d)return self(self,tr[u].l,tr[v].l,l,mid,k-d)+tr[tr[u].r].sum-tr[tr[v].r].sum;
			else return self(self,tr[u].r,tr[v].r,mid+1,r,k);
		};
		for(int i=1;i<=m;i++){
			updata(updata,root[i],root[i-1],1,1000,a[1][i]);
		}
		//dbg("yes");
		for(int i=1;i<=q;i++){
			int x,y,xx,yy,k;cin>>x>>y>>xx>>yy>>k;
			int res=query(query,root[yy],root[y-1],1,1000,k);
			//dbg(res);
			if(res>yy-y+1)cout<<"Poor QLW\n";
			else cout<<res<<'\n';
		}
	}	
	
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}