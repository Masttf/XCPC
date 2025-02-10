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
	int val1,val2;
};
void solve(){
	int n,q;cin>>n>>q;
	string s;cin>>s;
	s=' '+s;
	vector<node>t(n<<2);
	vector<int>f(n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)f[i]=f[i-1]*131;
	auto up = [&](int p,int len1,int len2)->void{
		t[p].val1=t[p<<1].val1*f[len2]+t[p<<1|1].val1;
		t[p].val2=t[p<<1|1].val2*f[len1]+t[p<<1].val2;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			t[p].val1=s[l]-'a'+1;
			t[p].val2=s[l]-'a'+1;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		up(p,mid-l+1,r-mid);
	};
	auto updata = [&](auto self,int x,int l,int r,int p,int val)->void{
		if(l==r){
			t[p].val1=val;
			t[p].val2=val;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,x,l,mid,p<<1,val);
		else self(self,x,mid+1,r,p<<1|1,val);
		up(p,mid-l+1,r-mid);
	};

	auto query = [&](auto self,int x,int y,int l,int r,int p)->pair<int,int>{
		if(x<=l&&r<=y){
			return {t[p].val1,t[p].val2};
		}
		int mid=(l+r)>>1;
		pair<int,int>res={0,0};
		if(x<=mid){
			res=self(self,x,y,l,mid,p<<1);
		}
		if(y>mid){
			pair<int,int>temp=self(self,x,y,mid+1,r,p<<1|1);
			if(x<=mid){
				res.first=res.first*f[min(r,y)-mid]+temp.first;
				res.second=temp.second*f[mid-max(x,l)+1]+res.second;
			}else res=temp;
		}
		return res;
	};

	bulid(bulid,1,n,1);
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int x;
			char c;
			cin>>x>>c;
			updata(updata,x,1,n,1,c-'a'+1);
		}else{
			int l,r;cin>>l>>r;
			pair<int,int>res=query(query,l,r,1,n,1);
			if(res.first==res.second)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}