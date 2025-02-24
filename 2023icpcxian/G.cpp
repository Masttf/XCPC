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

template <class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<arg<<' ';
	err(args...);
}
const int maxn=1e6+5;
vector<int>p;
bool vis[maxn];
void init(){
	vis[1]=1;
	for(int i=2;i<maxn;i++){
		if(!vis[i])p.push_back(i);
		for(int j=0;p[j]*i<maxn;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	return ;
}
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>res;
	int tot=1;
	int temp=n;
	for(int j=0;p[j]*p[j]<=temp;j++){
		if(temp%p[j]==0){
			int cnt=0;
			while(temp%p[j]==0){
				temp/=p[j];
				cnt++;
			}
			tot*=(cnt+1);
			res.push_back({p[j],cnt});

		}
	}
	if(temp!=1)res.push_back({temp,1}),tot*=2;

	int sz=res.size();
	int ans=0;
	int k=1;
	auto dfs = [&](auto self,int now)->void{
		if(now==sz){
			ans+=k*tot;
			return ;
		}
		self(self,now+1);
		k*=res[now].second;
		tot/=(res[now].second+1);
		self(self,now+1);
		k/=res[now].second;
		tot*=res[now].second+1;
	};
	dfs(dfs,0);

	ans=(ans+1)/2;
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int t;cin>>t;
	while(t--)solve();
	return 0;
}