#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
struct node{
	int l,r,id;
	bool operator <(const node& y)const{
		return r<y.r;
	}
};
struct node2{
	int l,r,val;
};
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<node>qy(q+1);
	for(int i=1;i<=q;i++)cin>>qy[i].l>>qy[i].r,qy[i].id=i;
	sort(qy.begin()+1,qy.end());
	
	//for(int i=1;i<=q;i++)cout<<qy[i].r<<' ';
	//cout<<endl;
	vector<int>t(n+1);
	auto add = [&](int x,int w)->void{
		while(x<=n){
			t[x]+=w;
			x+=lowbit(x);
		}
	};

	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};

	vector<vector<int>>po(n+1);
	for(int i=1;i<=n;i++){
		po[a[i]].push_back(i);
	}

	vector<node2>mx((n<<2)+1);
	auto bulid =[&](auto bulid,int l,int r,int p)->void{
		mx[p].l=l;
		mx[p].r=r;
		if(l==r){
			mx[p].val=0;
			return ;
		}
		int mid=(l+r)>>1;
		bulid(bulid,l,mid,p<<1);
		bulid(bulid,mid+1,r,p<<1|1);
	};
	bulid(bulid,1,n,1);
	//cout<<"YES"<<endl;
	auto updata =[&](auto updata,int l,int p){
		if(mx[p].l==mx[p].r){
			mx[p].val=a[l];
			//cout<<"ud "<<l<<' '<<mx[l].val<<endl;
			return ;
		}
		int mid=(mx[p].l+mx[p].r)>>1;
		if(l<=mid)updata(updata,l,p<<1);
		else updata(updata,l,p<<1|1);
		mx[p].val=max(mx[p<<1].val,mx[p<<1|1].val);
		return ;
	};

	auto query = [&](auto query,int l,int r,int p){
		if(l<=mx[p].l&&mx[p].r<=r){
			return mx[p].val;
		}
		int res=0;
		int mid=(mx[p].l+mx[p].r)>>1;
		if(l<=mid)res=max(res,query(query,l,r,p<<1));
		if(r>mid)res=max(res,query(query,l,r,p<<1|1));
		return res;
	};
	vector<int>ans(q+1);
	int last=1;
	for(int i=1;i<=q;i++){
		if(i!=1&&qy[i].r==qy[i-1].r){
			ans[qy[i].id]=ask(qy[i].l)+1;
			continue;
		}
		while(last<=qy[i].r){
			for(auto x:po[last]){
				updata(updata,x,1);
			}
			last++;
		}
		int sz=po[qy[i].r].size();
		if(sz==0){
			ans[qy[i].id]=ask(qy[i].l)+1;
			continue;
		}
		//cout<<"YES"<<' '<<qy[i].r<<' '<<sz<<endl;
		//updata(updata,po[qy[i].r][0],1);
		for(int j=1;j<sz;j++){
			//updata(updata,po[qy[i].r][j],1);
			//cout<<query(query,po[qy[i].r][j],po[qy[i].r][j],1)<<endl;
			int x=po[qy[i].r][j-1];
			int y=po[qy[i].r][j];
			if(y==x+1)continue;
			int d=query(query,x+1,y-1,1);
			cout<<x<<' '<<y<<' '<<d<<endl;
			if(!d)continue;
			add(1,1);
			add(d+1,-1);
		}
		ans[qy[i].id]=ask(qy[i].l)+1;
		//cout<<"YES"<<endl;
		//cout<<qy[i].id<<' '<<ans[qy[i].id]<<endl;
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