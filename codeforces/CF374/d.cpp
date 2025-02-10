#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(m+1);
	for(int i=1;i<=m;i++)cin>>a[i];
	vector<int>res(n+1);
	for(int i=1;i<=n;i++)cin>>res[i];
	vector<int>t(n*4);
	auto updata = [&](auto self,int l,int r,int p,int x)->void{
		if(l==r){
			t[p]=1;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,p<<1,x);
		else self(self,mid+1,r,p<<1|1,x);
		t[p]=t[p<<1]+t[p<<1|1];
	};
	auto query = [&](auto self,int l,int r,int p,int k)->int{
		if(l==r){
			t[p]=0;
			return l;
		}
		int mid=(l+r)>>1;
		int d=t[p<<1];
		int rs=-1;
		if(k<=d)rs=self(self,l,mid,p<<1,k);
		else rs=self(self,mid+1,r,p<<1|1,k-d);
		t[p]=t[p<<1]+t[p<<1|1];
		return rs;
	};
	for(int i=1;i<=n;i++){
		int len=t[1];
		if(res[i]==-1){
			for(int j=1;j<=m;j++){
				if(a[j]>len)break;
				query(query,1,n,1,a[j]-j+1);
			}
		}else{
			updata(updata,1,n,1,i);
		}
	}
	int len=t[1];
	if(len==0){
		cout<<"Poor stack!\n";
		return ;
	}
	for(int i=1;i<=len;i++){
		cout<<res[query(query,1,n,1,1)];
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}