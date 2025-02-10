#include<bits/stdc++.h>
#define int long long
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
struct node{
	int val,tag;
};
constexpr int Max=1e18;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>pp;
    vector<int>a(n+5);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	pp.push_back(a[i]);
    }
    sort(pp.begin(),pp.end());
    pp.erase(unique(pp.begin(),pp.end()),pp.end());
    for(int i=1;i<=n;i++){
    	a[i]=lower_bound(pp.begin(),pp.end(),a[i])-pp.begin()+1;
    }
    a[0]=a[n+1]=Max;
    vector<int>last(n+1);
    vector<int>nt(n+1);
    vector<int>pos(n+1);
    for(int i=1;i<=n;i++){
    	last[i]=pos[a[i]];
    	pos[a[i]]=i;
    }
    pos.assign(n+1,n+1);
    for(int i=n;i>=1;i--){
    	nt[i]=pos[a[i]];
    	pos[a[i]]=i;
    }
    
	// for(int i=1;i<=n;i++){
	// 	dbg(i,lm[i],rm[i]);
	// }
	vector tr(3,vector<node>(n*4));
	auto up = [&](node x,node y)->node{
		node res={0,0};
		res.val=x.val+y.val;
		return res;
	};
	auto cg = [&](node &x,int val,int len)->void{
		x.val+=len*val;
		x.tag+=val;
	};
	auto down = [&](int p,int ty,int l,int r)->void{
		if(tr[ty][p].tag){
			int mid=(l+r)>>1;
			cg(tr[ty][p<<1],tr[ty][p].tag,mid-l+1);
			cg(tr[ty][p<<1|1],tr[ty][p].tag,r-mid);
			tr[ty][p].tag=0;
		}
	};
	auto updata = [&](auto self,int l,int r,int x,int y,int val,int ty,int p)->void{
		if(x<=l&&r<=y){
			cg(tr[ty][p],val,r-l+1);
			return ;
		}
		down(p,ty,l,r);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,val,ty,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,val,ty,p<<1|1);
		tr[ty][p]=up(tr[ty][p<<1],tr[ty][p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int ty,int p)->int{
		if(x<=l&&r<=y){
			//dbg(l,r,tr[ty][p].val);
			return tr[ty][p].val;
		}
		down(p,ty,l,r);
		int mid=(l+r)>>1;
		int res=0;
		if(x<=mid)res+=self(self,l,mid,x,y,ty,p<<1);
		if(y>mid)res+=self(self,mid+1,r,x,y,ty,p<<1|1);
		return res;
	};
	//bulid(bulid,1,n,1);
	vector<int>stk;
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&a[i]>=a[stk.back()]){
			if(a[i]==a[stk.back()]){
				if(stk.back()+1<=i-1){
					//dbg(stk.back()+1,i-1);
					updata(updata,1,n,stk.back()+1,i-1,-1,2,1);
				}
			}
			stk.pop_back();
		}
		updata(updata,1,n,i,i,stk.size(),0,1);
		stk.push_back(i);
	}
	stk.clear();
	for(int i=n;i>=1;i--){
		while(!stk.empty()&&a[i]>=a[stk.back()]){
			stk.pop_back();
		}
		updata(updata,1,n,i,i,stk.size(),1,1);
		stk.push_back(i);
	}

	vector<int>tr2(n*4);
	auto bulid2 = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr2[p]=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		tr2[p]=max(tr2[p<<1],tr2[p<<1|1]);
	};
	auto updata2 = [&](auto self,int l,int r,int x,int val,int p)->void{
		if(l==r){
			tr2[p]=val;
			a[l]=val;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,val,p<<1);
		else self(self,mid+1,r,x,val,p<<1|1);
		tr2[p]=max(tr2[p<<1],tr2[p<<1|1]);
	};
	//左边第一个大于等于val的位置
	auto query1 = [&](auto self,int l,int r,int x,int y,int val,int p)->int{
		if(x<=l&&r<=y){
			if(tr2[p]<val)return -1;
			if(l==r)return l;
		}
		int mid=(l+r)>>1;
		if(y>mid){
			int res=self(self,mid+1,r,x,y,val,p<<1|1);
			if(res!=-1)return res;
		}
		if(x<=mid)return self(self,l,mid,x,y,val,p<<1);
		return -1;
	};
	//左边第一个大于val的位置
	auto query2 = [&](auto self,int l,int r,int x,int y,int val,int p)->int{
		if(x<=l&&r<=y){
			if(tr2[p]<=val)return -1;
			if(l==r)return l;
		}
		int mid=(l+r)>>1;
		if(y>mid){
			int res=self(self,mid+1,r,x,y,val,p<<1|1);
			if(res!=-1)return res;
		}
		if(x<=mid)return self(self,l,mid,x,y,val,p<<1);
		return -1;
	};
	//右边第一个大于等于val的位置
	auto query3 = [&](auto self,int l,int r,int x,int y,int val,int p)->int{
		if(x<=l&&r<=y){
			if(tr2[p]<val)return -1;
			if(l==r)return l;
		}
		int mid=(l+r)>>1;
		if(x<=mid){
			int res=self(self,l,mid,x,y,val,p<<1);
			if(res!=-1)return res;
		}
		if(y>mid)return self(self,mid+1,r,x,y,val,p<<1|1);
		return -1;
	};
	//右边第一个大于val的位置
	auto query4 = [&](auto self,int l,int r,int x,int y,int val,int p)->int{
		if(x<=l&&r<=y){
			if(tr2[p]<=val)return -1;
			if(l==r)return l;
		}
		int mid=(l+r)>>1;
		if(x<=mid){
			int res=self(self,l,mid,x,y,val,p<<1);
			if(res!=-1)return res;
		}
		if(y>mid)return self(self,mid+1,r,x,y,val,p<<1|1);
		return -1;
	};
	bulid2(bulid2,0,n+1,1);
    int q;cin>>q;
	for(int i=1;i<=q;i++){
		int op;cin>>op;
		if(op==2){
			int l,r;cin>>l>>r;
			int ans=(r-l+1)*(n-1);
			// dbg(query(query,1,n,l,r,0,1));
			// dbg(query(query,1,n,l,r,1,1));
			// dbg(query(query,1,n,l,r,2,1));
			ans+=k*(query(query,1,n,l,r,0,1)+query(query,1,n,l,r,1,1)+query(query,1,n,l,r,2,1));
			//dbg(i,ans);
			cout<<ans<<'\n';
		}else{
			int x;cin>>x;
			if(a[x]==a[x]+1)continue;
			else if(a[x]>a[x+1]){
				int vl=query(query,1,n,x,x,0,1);
				int vr=query(query,1,n,x+1,x+1,0,1);
				int l=query2(query2,0,n+1,0,x-1,a[x+1],1);
				int r=query3(query3,0,n+1,x+2,n+1,a[x+1],1);
				int d=0;
				if(l!=0)d=query(query,1,n,l,l,0,1)+1;
				updata(updata,1,n,x,x,d-vl,0,1);
				updata(updata,1,n,x+1,r-1,-1,0,1);

				vl=query(query,1,n,x,x,1,1);
				vr=query(query,1,n,x+1,x+1,1,1);
				l=query1(query1,0,n+1,0,x-1,a[x+1],1);
				updata(updata,1,n,x+1,x+1,vl-vr,1,1);
				updata(updata,1,n,l+1,x,1,1,1);

			}else{
				int vl=query(query,1,n,x,x,0,1);
				int vr=query(query,1,n,x+1,x+1,0,1);
				int r=query3(query3,0,n+1,x+1,n+1,a[x],1);
				updata(updata,1,n,x,x,vr-vl,0,1);
				updata(updata,1,n,x+1,r-1,1,0,1);

				vl=query(query,1,n,x,x,1,1);
				vr=query(query,1,n,x+1,x+1,1,1);
				int l=query1(query1,0,n+1,0,x-1,a[x],1);
				r=query4(query4,0,n+1,x+1,n+1,a[x],1);
				int d=0;
				if(r<=n)d=query(query,1,n,r,r,1,1)+1;
				updata(updata,1,n,x+1,x+1,d-vr,1,1);
				updata(updata,1,n,l+1,x,-1,1,1);
			}
			
			if(a[x]<a[x+1]){
				int l=query1(query1,0,n+1,0,x-1,a[x],1);
				if(last[x]&&last[x]==l){
					if(last[x]+1<=x-1)updata(updata,1,n,last[x]+1,x-1,1,2,1);
				}

				int r=query3(query3,0,n+1,x+2,n+1,a[x],1);
				if(nt[x]!=n+1&&nt[x]==r){
					if(x+2<=r-1)updata(updata,1,n,x+2,r-1,-1,2,1);
				}

				l=query1(query1,0,n+1,0,x-1,a[x+1],1);
				r=query3(query3,0,n+1,x+2,n+1,a[x+1],1);
				if(last[x+1]&&last[x+1]==l){
					updata(updata,1,n,x,x,1,2,1);
				}
				if(nt[x+1]!=n+1&&nt[x]==r){
					updata(updata,1,n,x+1,x+1,-1,2,1);
				}
			}else{
				int l=query1(query1,0,n+1,0,x-1,a[x],1);
				if(last[x]&&last[x]==l){
					updata(updata,1,n,x,x,-1,2,1);
				}
				int r=query3(query3,0,n+1,x+2,n+1,a[x],1);
				if(nt[x]!=n+1&&nt[x]==r){
					updata(updata,1,n,x+1,x+1,1,2,1);
				}

				l=query1(query1,0,n+1,0,x-1,a[x+1],1);
				r=query3(query3,0,n+1,x+2,n+1,a[x+1],1);
				if(last[x+1]&&last[x+1]==l){
					if(last[x+1]+1<=x-1)updata(updata,1,n,last[x+1]+1,x-1,-1,2,1);
				}
				if(nt[x+1]!=n+1&&nt[x+1]==r){
					if(x+2<=r-1)updata(updata,1,n,x+2,r-1,1,2,1);
				}
			}
			if(last[x]){
				nt[last[x]]=x+1;
			}
			if(nt[x]!=n+1){
				last[nt[x]]=x+1;
			}
			if(last[x+1]){
				nt[last[x+1]]=x;
			}
			if(nt[x+1]!=n+1){
				last[nt[x+1]]=x;
			}
			swap(last[x],last[x+1]);
			swap(nt[x],nt[x+1]);
			int ll=a[x];
			int rr=a[x+1];
			updata2(updata2,0,n+1,x,rr,1);
			updata2(updata2,0,n+1,x+1,ll,1);
		}
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
