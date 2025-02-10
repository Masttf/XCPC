#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int l,r;
	bool operator <(const node&y)const{
		return l<y.l;
	}
};
struct node2{
	int l,r,max,min,val,tag;
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
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,m;cin>>n>>m;
	vector<node>a(n+1);
	vector<int>p;
	p.push_back(1);
	p.push_back(m);
	for(int i=1;i<=n;i++){
		int l,r;cin>>l>>r;
		a[i]={l,r};
		p.push_back(l);
		p.push_back(r);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	for(int i=1;i<=n;i++){
		a[i].l=get(a[i].l);
		a[i].r=get(a[i].r);
		//dbg(a[i].l,a[i].r);
	}
	int len=p.size();
	vector<node2>t(len<<4);
	auto up = [&](int p)->void{
		t[p].max=max(t[p<<1].max,t[p<<1|1].max);
		t[p].min=min(t[p<<1].min,t[p<<1|1].min);
		t[p].val=t[p<<1].val+t[p<<1|1].val;
		return ;
	};

	auto push = [&](int p)->void{
		t[p<<1].max+=t[p].tag;
		t[p<<1].min+=t[p].tag;
		t[p<<1].val+=t[p].tag;
		t[p<<1].tag+=t[p].tag;

		t[p<<1|1].max+=t[p].tag;
		t[p<<1|1].min+=t[p].tag;
		t[p<<1|1].val+=t[p].tag;
		t[p<<1|1].tag+=t[p].tag;
		t[p].tag=0;
	};

	auto bulid = [&](auto self,int l,int r,int p)->void{
		t[p].l=l,t[p].r=r;
		if(l==r){
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		return ;
	};

	auto updata = [&](auto self,int x,int y,int val,int p)->void{
		int l=t[p].l,r=t[p].r;
		if(x<=l&&r<=y){
			t[p].max+=val;
			t[p].min+=val;
			t[p].val+=val;
			t[p].tag+=val;
			return ;
		}
		push(p);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,x,y,val,p<<1);
		if(y>mid)self(self,x,y,val,p<<1|1);
		up(p);
		return ;
	};

	sort(a.begin()+1,a.end());
	int ans=0;
	bulid(bulid,1,len,1);
	//dbg(len);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1,j=1;i<=len;i++){
		while(j<=n&&a[j].l<=i){
			updata(updata,a[j].l,a[j].r,1,1);
			q.push({a[j].r,a[j].l});
			j++;
		}
		
		while(!q.empty()&&q.top().first<i){
			int l=q.top().second;
			int r=q.top().first;
			q.pop();
			updata(updata,l,r,-1,1);
		}
		ans=max(t[1].max-t[1].min,ans);
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