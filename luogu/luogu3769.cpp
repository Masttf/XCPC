#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b,c,d,val,id,mk;
	bool operator == (const node&y)const{
		return ((a==y.a)&&(b==y.b)&&(c==y.c)&&(d==y.d));
	}
	bool operator < (const node&y)const{
		if(b!=y.b)return b<y.b;
		if(a!=y.a)return a<y.a;
		if(c!=y.c)return c<y.c;
		return d<y.d;
	}
};
bool cmp1 (node&x,node&y){
	if(x.a!=y.a)return x.a<y.a;
	if(x.b!=y.b)return x.b<y.b;
	if(x.c!=y.c)return x.c<y.c;
	return x.d<y.d;
}
bool cmp2 (node&x,node&y){
	if(x.c!=y.c)return x.c<y.c;
	if(x.a!=y.a)return x.a<y.a;
	if(x.b!=y.b)return x.b<y.b;
	return x.d<y.d;
}
void solve(){
	int n;cin>>n;
	vector<node>aa(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++){
		int a,b,c,d;cin>>a>>b>>c>>d;
		aa[i]={a,b,c,d,1,0,0};
		p.push_back(d);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	vector<node>res(1);
	sort(aa.begin()+1,aa.end(),cmp1);
	for(int i=1;i<=n;i++){
		int j=i;
		int val=0;
		while(j<=n&&aa[i]==aa[j]){
			val++;
			j++;
		}
		aa[i].val=val;
		aa[i].id=res.size();
		aa[i].d=get(aa[i].d);
		res.push_back(aa[i]);
		i=j-1;
	}
	n=res.size()-1;
	int mx=p.size();
	vector<int>tr(n*4);
	auto updata = [&](auto self,int l,int r,int x,int k,int t,int p)->void{
		if(l==r){
			if(t==2)tr[p]=0;
			else tr[p]=max(tr[p],k);
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,k,t,p<<1);
		else self(self,mid+1,r,x,k,t,p<<1|1);
		tr[p]=max(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->int{
		if(x<=l&&r<=y)return tr[p];
		int mid=(l+r)>>1;
		int res=0;
		if(x<=mid)res=max(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=max(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	vector<int>dp(n+1);
	for(int i=1;i<=n;i++)dp[i]=res[i].val;
	vector<node>temp=res;
	auto cdq2 = [&](auto self,int l,int r)->void{
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,l,mid);
		sort(res.begin()+mid+1,res.begin()+r+1,cmp2);
		int i=l,j=mid+1;
		for(;j<=r;j++){
			if(!res[j].mk)continue;
			while(i<=mid&&res[i].c<=res[j].c){
				if(!res[i].mk)updata(updata,1,mx,res[i].d,dp[res[i].id],1,1);
				i++;
			}
			int d=query(query,1,mx,1,res[j].d,1);
			d+=res[j].val;
			dp[res[j].id]=max(dp[res[j].id],d);
		}
		for(i--;i>=l;i--)updata(updata,1,mx,res[i].d,0,2,1);
		sort(res.begin()+mid+1,res.begin()+r+1);
		self(self,mid+1,r);
		sort(res.begin()+l,res.begin()+r+1,cmp2);
	};
	auto cdq1 = [&](auto self,int l,int r)->void{
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,l,mid);
		for(int k=l;k<=r;k++){
			temp[k]=res[k];
			if(k<=mid)res[k].mk=0;
			else res[k].mk=1;
		}
		sort(res.begin()+l,res.begin()+r+1);
		cdq2(cdq2,l,r);
		for(int k=l;k<=r;k++)res[k]=temp[k];
		self(self,mid+1,r);
	};
	cdq1(cdq1,1,n);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
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
