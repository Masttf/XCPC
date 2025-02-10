#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...)\
do{\
	cout<<#x<<" -> ";\
	err(x);\
}while(0)
void err(){
	cout<<endl<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<arg<<' ';
	err(args...);
}

void solve(){
	int n,k;cin>>n>>k;
	int temp=n;
	n=(1ll<<n);
	vector<pair<int,int>>a(n+1);
	vector<int>b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i,b[i]=a[i].first;

	vector<int>ans(n+1,-1);

	auto mg = [&](auto self,int l,int r,int now)->void{
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,l,mid,now-1);
		self(self,mid+1,r,now-1);

		int len=r-l+1;
		vector<pair<int,int>>res(len);
		int i=l,j=mid+1;
		for(int s=0;s<len;s++){
			if(i==mid+1||j<=r&&a[i].first>a[j].first)res[s]=a[j++];	
			else res[s]=a[i++];
			if(ans[res[s].second]==-1&&len-s-1>k){
				ans[res[s].second]=now-1;
			}
		}
		for(int s=0;s<len;s++)a[l+s]=res[s];
	};
	mg(mg,1,n,temp);

	for(int i=1;i<=n;i++){
		if(ans[i]==-1)ans[i]=__lg(b[i]);
		else ans[i]=min(ans[i],__lg(b[i]));
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}