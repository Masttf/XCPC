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
	auto add = [&](node &x,node &y)->void{
		if(x.c1==y.c1){
			x.v1=max(x.v1,y.v1);
		}else if(x.c2==y.c1){
			x.v2=max(x.v2,y.v1);
		}else{
			if(y.v1>=x.v1){
				x.v2=x.v1;
				x.c2=x.c1;
				x.v1=y.v1;
				x.c1=y.c1;
			}else if(y.v1>x.v2){
				x.v2=y.v1;
				x.c2=y.c1;
			}
		}
	};
	auto get = [&](node x,int val,int color)->node{
		node res={-1,0,-1,0};
		if(color==x.c1){
			if(x.v2==-1)return res;
			res.v1=x.v2+val;
		}else{
			if(x.v1==-1)return res;
			res.v1=x.v1+val;
		}
		res.c1=color;
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
			dbg(i,j);
			dbg(dp_1[j]);
		}
		for(int j=0;j<=min(i-1,k);j++){
			if(j==i){
				dp_1[j]={0,0,-1,0};
			}else{
				node temp=get(dp_2[j],v[i],c[i]);
				add(dp_1[j],temp);
				dbg(i,j);
				dbg(dp_1[j]);
				dbg(temp);
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