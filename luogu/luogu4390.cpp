#include<bits/stdc++.h>
#define int long long
#define lowbit(x)((x)&-(x))
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
	int id,t,x1,y1,y2,val;
};
bool cmp (node&x,node&y){
	return x.x1<y.x1;
}
void solve(){
	int _,w;cin>>_>>w;
	vector<node>res(1);
	int op;cin>>op;
	_=1;
	while(op!=3){
		if(op==1){
			int x,y,val;cin>>x>>y>>val;
			res.push_back({_,2,x,y,y,val});
		}else{
			int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
			res.push_back({_,1,x2,y1,y2,0});
			res.push_back({_,-1,x1-1,y1,y2,0});
		}
		cin>>op;
		_++;
	}
	int n=res.size()-1;
	vector<int>tr(w+1);
	auto updata = [&](int x,int val)->void{
		while(x<=w){
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
	auto cdq = [&](auto self,int l,int r)->void{
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,l,mid);
		self(self,mid+1,r);
		int i=l,j=mid+1;
		//dbg(l,r);
		for(;j<=r;j++){
			if(res[j].t==2)continue;
			while(i<=mid&&res[i].x1<=res[j].x1){
				if(res[i].t==2){
					updata(res[i].y1,res[i].val);
				}
				i++;
			}
			res[j].val+=res[j].t*(ask(res[j].y2)-ask(res[j].y1-1));
			//dbg(res[j].id,res[j].t,res[j].y1,res[j].y2,res[j].val);
		}
		for(i--;i>=l;i--){
			if(res[i].t==2)updata(res[i].y1,-res[i].val);
		}
		sort(res.begin()+l,res.begin()+r+1,cmp);
	};
	cdq(cdq,1,n);
	vector<int>ans(_,0);
	for(int i=1;i<=n;i++){
		if(res[i].t==2){
			ans[res[i].id]=-1;
			continue;
		}
		ans[res[i].id]+=res[i].val;
	}
	for(int i=1;i<_;i++){
		if(ans[i]==-1)continue;
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