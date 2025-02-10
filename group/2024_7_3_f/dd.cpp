#include<bits/stdc++.h>
//#define int long long
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
	int cnt[26];
	int tag;
};
void solve(){
	int n,q;cin>>n>>q;
	string s;cin>>s;
	s=' '+s;
	vector<node>tr(n*4);
	auto up = [&](node x,node y)->node{
		node res;
		res.tag=-1;
		for(int i=0;i<26;i++){
			res.cnt[i]=x.cnt[i]+y.cnt[i];
		}
		return res;
	};
	auto down = [&](int p,int l,int r)->void{
		if(tr[p].tag==-1)return ;
		tr[p<<1].tag=tr[p].tag;
		tr[p<<1|1].tag=tr[p].tag;
		for(int i=0;i<26;i++){
			tr[p<<1].cnt[i]=0;
			tr[p<<1|1].cnt[i]=0;
		}
		int mid=(l+r)>>1;
		int num=(mid-l+1);
		int flag=0;
		int sum=0;
		if(tr[p].tag==1){
			for(int i=0;i<26;i++){
				if(flag)tr[p<<1|1].cnt[i]=tr[p].cnt[i];
				else{
					if(sum+tr[p].cnt[i]<num){
						sum+=tr[p].cnt[i];
						tr[p<<1].cnt[i]=tr[p].cnt[i];
					}else{
						tr[p<<1].cnt[i]=num-sum;
						tr[p<<1|1].cnt[i]=sum+tr[p].cnt[i]-num;
						flag=1;
					}
				}
			}
		}else{
			for(int i=25;i>=0;i--){
				if(flag)tr[p<<1|1].cnt[i]=tr[p].cnt[i];
				else{
					if(sum+tr[p].cnt[i]<num){
						sum+=tr[p].cnt[i];
						tr[p<<1].cnt[i]=tr[p].cnt[i];
					}else{
						tr[p<<1].cnt[i]=num-sum;
						tr[p<<1|1].cnt[i]=sum+tr[p].cnt[i]-num;
						flag=1;
					}
				}
			}
		}
		tr[p].tag=-1;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].cnt[s[l]-'a']++;
			tr[p].tag=-1;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	vector<int>temp(30);
	int last=0;
	auto updata = [&](auto self,int l,int r,int x,int y,int val,int p)->void{
		if(x<=l&&r<=y){
			tr[p].tag=val;
			for(int i=0;i<26;i++)tr[p].cnt[i]=0;
			int num=r-l+1;
			if(val==1){
				for(int &i=last;i<26;i++){
					if(num>=temp[i]){
						tr[p].cnt[i]=temp[i];
						num-=temp[i];
					}else{
						tr[p].cnt[i]=num;
						temp[i]-=num;
						break;
					}
				}
			}else{
				for(int &i=last;i>=0;i--){
					if(num>=temp[i]){
						tr[p].cnt[i]=temp[i];
						num-=temp[i];
					}else{
						tr[p].cnt[i]=num;
						temp[i]-=num;
						break;
					}
				}
			}
			return ;
		}
		down(p,l,r);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,val,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,val,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
		for(int i=0;i<26;i++){
			cout<<tr[p].cnt[i]<<' ';
		}
		cout<<endl;
	};
	string ans="";
	auto query = [&](auto self,int l,int r,int x,int y,int p)->node{
		if(x<=l&&r<=y){
			return tr[p];
		}
		down(p,l,r);
		int mid=(l+r)>>1;
		node res;
		for(int i=0;i<26;i++)res.cnt[i]=0;
		if(x<=mid)res=up(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=up(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	auto get = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			for(int i=0;i<26;i++){
				if(tr[p].cnt[i]){
					ans+='a'+i;
					return ;
				}
			}
		};
		down(p,l,r);
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
	};
	bulid(bulid,1,n,1);
	for(int i=1;i<=q;i++){
		int l,r,k;cin>>l>>r>>k;
		if(k==1)last=0;
		else last=25;
		node res=query(query,1,n,l,r,1);
		for(int j=0;j<26;j++)temp[j]=res.cnt[j];
		updata(updata,1,n,l,r,k,1);
	}
	get(get,1,n,1);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}