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
	int v1,c1,v2,c2;
	friend ostream &operator <<(ostream&os,const node &x){
		return os<<x.v1<<' '<<x.c1<<' '<<x.v2<<' '<<x.c2;
	}
};
void solve(){
	int n,k;cin>>n>>k;
	vector<int>c(n+1),v(n+1);
	for(int i=1;i<=n;i++)cin>>c[i]>>v[i];
	// auto add = [&](node &x,node &y)->void{
	// 	if(x.c1==y.c1){
	// 		x.v1=max(x.v1,y.v1);
	// 	}else if(x.c2==y.c1){
	// 		x.v2=max(x.v2,y.v1);
	// 	}else{
	// 		if(y.v1>=x.v1){
	// 			x.v2=x.v1;
	// 			x.c2=x.c1;
	// 			x.v1=y.v1;
	// 			x.c1=y.c1;
	// 		}else if(y.v1>x.v2){
	// 			x.v2=y.v1;
	// 			x.c2=y.c1;
	// 		}
	// 	}
	// };
	vector<int>vis(n+1,-1);
	auto mmx = [&](node x,int val,int color)->node{
		set<int>s;
		s.insert(x.c1);
		s.insert(color);
		s.insert(x.c2);
		vis[x.c1]=max(vis[x.c1],x.v1);
		vis[color]=max(vis[color],val);
		vis[x.c2]=max(vis[x.c2],x.v2);
		int mx1=-1,p1=0,mx2=-1,p2=0;
		for(auto it:s){
			if(mx1<=vis[it]){
				mx2=mx1;
				p2=p1;
				mx1=vis[it];
				p1=it;
			}else if(mx2<vis[it]){
				mx2=vis[it];
				p2=it;
			}
		}
		vis[x.c1]=-1;
		vis[color]=-1;
		vis[x.c2]=-1;
		node res={mx1,p1,mx2,p2};
		return res;
	};
	auto get = [&](node x,int val,int color)->pair<int,int>{
		pair<int,int> res={-1,0};
		if(color==x.c1){
			if(x.v2==-1)return res;
			res.first=x.v2+val;
		}else{
			if(x.v1==-1)return res;
			res.first=x.v1+val;
		}
		res.second=color;
		return res;
	};
	vector<node>dp_1(k+1);
	vector<node>dp_2(k+1);
	for(int i=0;i<=k;i++){
		dp_1[i]={-1,0,-1,0};
		dp_2[i]={-1,0,-1,0};
	}
	dp_1[0]={0,0,-1,0};
	for(int i=1;i<=n;i++){
		swap(dp_1,dp_2);
		for(int j=1;j<=min(i,k);j++){
			dp_1[j]=dp_2[j-1];
		}
		dp_1[0]={-1,0,-1,0};
		for(int j=0;j<=min(i-1,k);j++){
			if(j==i){
				dp_1[j]={0,0,-1,0};
			}else{
				pair<int,int> temp=get(dp_2[j],v[i],c[i]);
				dp_1[j]=mmx(dp_1[j],temp.first,temp.second);
			}
			
		}
	}
	node ans=dp_1[k];
	cout<<ans.v1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
