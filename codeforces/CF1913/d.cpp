#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector st(21,vector<pair<int,int>>(n+1));
	for(int i=1;i<=n;i++)st[0][i]={a[i],i};
	for(int s=1;(1<<s)<=n;s++){
		for(int i=1;i+(1<<s)<=n+1;i++){
			st[s][i]=min(st[s-1][i],st[s-1][i+(1<<(s-1))]);
		}
	}
	auto get = [&](int l,int r)->int{
		int len=r-l+1;
		pair<int,int>res={INT_MAX,0};
		for(int i=20;i>=0;i--){
			if(len>>i&1){
				res=min(res,st[i][l]);
				l+=(1<<i);
			}
		}
		return res.second;
	};
	//dp lr 表示lr这段区间的方案数,假设x为这个区间最小值的位置
	//如果x这个位置不删那么方案数明显是dp l x-1 * dp x+1 r
	//那么如果这个数被删那么有删掉左边一半如果左边有比它小的数和右边一半如果右边有比它小的数
	//注意全删的情况被重复计算了一次
	auto dfs = [&](auto self,int l,int r)->int{
		int d1=1,d2=1;
		int x=get(l,r);
		if(x!=l)d1=self(self,l,x-1);
		if(x!=r)d2=self(self,x+1,r);
		int ans=d1*d2%mod;
		if(l==1&&r==n){

		}else if(l==1){
			ans+=d1;
		}else if(r==n){
			ans+=d2;
		}else{
			ans+=d1+d2-1;
		}
		return (ans%mod+mod)%mod;
	};
	cout<<dfs(dfs,1,n)<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}