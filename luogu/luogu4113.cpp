#include<bits/stdc++.h>
//#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
struct node{
	int l,r,id;
	bool operator < (const node& y)const{
		return r<y.r;
	}
};
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}

template<class T, class... Ts>
void err(T arg, Ts &... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,m,q;cin>>n>>m>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>t(n+1);
	auto updata = [&](int x,int val)->void{
		while(x<=n){
			t[x]+=val;
			x+=lowbit(x);
		}
	};
	auto ask =[&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};
	vector<int>p1(m+1);
	vector<int>p2(m+1);
	vector<node>res(q+1);
	vector<int>ans(q+1);
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		res[i]={l,r,i};
	}
	sort(res.begin()+1,res.end());
	int r=1;
	for(int i=1;i<=q;i++){
		int ll=res[i].l;
		int rr=res[i].r;
		int id=res[i].id;
		while(r<=n&&r<=rr){
			//dbg(i,r);
			if(p1[a[r]]){
				updata(p1[a[r]],-1);
				updata(p2[a[r]],1);
			}else if(p2[a[r]]){
				//dbg(r,p2[a[r]]);
				updata(p2[a[r]],1);
			}
			p1[a[r]]=p2[a[r]];
			p2[a[r]]=r;
			r++;
		}
		//dbg(ll,rr);
		ans[id]=ask(rr)-ask(ll-1);
	}
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