#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int l,r;
	int val;
	char l1,l2,r1,r2;
	int tag;
};
void debug(){
	cout<<"YES"<<endl;
}
void solve(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	s=' '+s;
	vector<node>t(n<<2+1);
	
	auto change = [&](char x,int k)->char{
		int res=x+k;
		if(res>'z'){
			res-='z'+1;
			res+='a';
		}
		return (char)res;
	};
	auto up = [&](int p)->void{
		t[p].tag=0;
		t[p].l1=t[p<<1].l1;
		t[p].l2=t[p<<1].l2;
		t[p].r1=t[p<<1|1].r1;
		t[p].r2=t[p<<1|1].r2;
		if(t[p<<1].r1==t[p<<1|1].l1)t[p].tag=1;
		else if(t[p<<1].r1==t[p<<1|1].l2)t[p].tag=1;
		else if(t[p<<1].r2==t[p<<1|1].l1)t[p].tag=1;
		return ;
	};
	
	auto push = [&](int p)->void{
		t[p<<1].val+=t[p].val;
		t[p<<1].l1=change(t[p<<1].l1,t[p].val);
		t[p<<1].l2=change(t[p<<1].l2,t[p].val);
		t[p<<1].r1=change(t[p<<1].r1,t[p].val);
		t[p<<1].r2=change(t[p<<1].r2,t[p].val);
		
		t[p<<1|1].val+=t[p].val;
		t[p<<1|1].l1=change(t[p<<1|1].l1,t[p].val);
		t[p<<1|1].l2=change(t[p<<1|1].l2,t[p].val);
		t[p<<1|1].r1=change(t[p<<1|1].r1,t[p].val);
		t[p<<1|1].r2=change(t[p<<1|1].r2,t[p].val);
		
		t[p].val=0;
		return ;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		t[p].l=l,t[p].r=r;
		if(l==r){
			t[p].l1=s[l];
			t[p].l2=s[l];
			t[p].r1=s[l];
			t[p].r2=s[l];
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		up(p);
		return ;
	};
	bulid(bulid,1,n,1);
	//debug();
	
	auto updata = [&](auto self,int l,int r,int p,int val){
		int ll=t[p].l,rr=t[p].r;
		if(l<=ll&&rr<=r){
			t[p].l1=change(t[p].l1,val);
			t[p].l2=change(t[p].l2,val);
			t[p].r1=change(t[p].r1,val);
			t[p].r2=change(t[p].r2,val);
			t[p].val+=val;
			if(t[p].val>=26)t[p].val-=26;
			//cout<<t[1].l1<<' '<<t[1].l2<<' '<<t[1].r2<<' '<<t[1].r1<<endl;
			return ;
		}
		int mid=(ll+rr)>>1;
		push(p);
		if(l<=mid)self(self,l,r,p<<1,val);
		if(r>mid)self(self,l,r,p<<1|1,val);
		up(p);
		return ;
	};
	
	auto query = [&](auto self,int l,int r,int p)->node{
		int ll=t[p].l,rr=t[p].r;
		if(l<=ll&&rr<=r){
			return t[p];
		}
		//cout<<"YES"<<p<<'\n';
		push(p);
		node res;
		int mid=(ll+rr)>>1;
		node temp1,temp2;
		int ok1=0,ok2=0;
		if(l<=mid)temp1=self(self,l,r,p<<1),ok1=1;
		if(r>mid)temp2=self(self,l,r,p<<1|1),ok2=1;
		up(p);
		if(ok1&&ok2){
			res.l1=temp1.l1;
			res.l2=temp1.l2;
			res.r1=temp2.r1;
			res.r2=temp2.r2;
			if(temp1.r1==temp2.l1)res.tag=1;
			else if(temp1.r1==temp2.l2)res.tag=1;
			else if(temp1.r2==temp2.l1)res.tag=1;
		}else if(ok1)res=temp1;
		else res=temp2;
		return res;
	};
	
	for(int i=1;i<=m;i++){
		int t,l,r;cin>>t>>l>>r;
		if(t==1){
			int x;cin>>x;
			updata(updata,l,r,1,x%26);
		}else{
			//debug();
			node res=query(query,l,r,1);
			if(res.tag==1)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}