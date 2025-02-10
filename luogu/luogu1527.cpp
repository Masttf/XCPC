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
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
struct Num {
  int x,y,val;
};
struct node{
	int x1,y1,x2,y2,k,id;
};
void solve(){
    int n,q;cin>>n>>q;
    vector a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++)cin>>a[i][j];
    }
	vector tr(n+1,vector<int>(n+1));
	auto add = [&](int x, int y, int d)->void{
	    for (int i = x; i <= n; i+=lowbit(i)) {
	        for (int j = y; j <= n; j+=lowbit(j)) {
	            tr[i][j] += d;
	        }
	    }
	};
	auto ask = [&](int x, int y)->int{
	    int res = 0;
	    for (int i = x; i > 0; i -= lowbit(i)) {
	        for (int j = y; j > 0; j -=lowbit(j)) {
	            res += tr[i][j];
	        }
	    }
   		return res;
	};
	vector<node>Q;
	vector<int>ans(q+1);
	for(int i=1;i<=q;i++){
		int x1,y1,x2,y2,k;cin>>x1>>y1>>x2>>y2>>k;
		Q.push_back({x1,y1,x2,y2,k,i});
	}
	vector<Num>temp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			temp.push_back({i,j,a[i][j]});
		}
	}
	auto fz = [&](auto self,int l,int r,vector<Num>b,vector<node>QQ)->void{
		if(l==r){
			for(auto [x1,y1,x2,y2,k,id]:QQ){
				//dbg(id);
				ans[id]=l;
			}
			return ;
		}
		if(QQ.empty())return ;
		int mid=(l+r)>>1;
		vector<Num> a1, a2;
  		vector<node> q1, q2;
  		for(auto [x,y,val]:b){
  			if(val<=mid){
  				a1.push_back({x,y,val});
  				add(x,y,1);
  			}else a2.push_back({x,y,val});
  		}
  		for(auto [x1,y1,x2,y2,k,id]:QQ){
  			int d=ask(x2,y2)+ask(x1-1,y1-1)-ask(x1-1,y2)-ask(x2,y1-1);
  			if(k<=d){
  				q1.push_back({x1,y1,x2,y2,k,id});
  			}else{
  				q2.push_back({x1,y1,x2,y2,k-d,id});
  			}
  		}
  		for(auto [x,y,val]:b){
  			if(val<=mid){
  				add(x,y,-1);
  			}
  		}
  		self(self,l,mid,a1,q1);
  		self(self,mid+1,r,a2,q2);
	};
	fz(fz,0,1e9,temp,Q);
	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}