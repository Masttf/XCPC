#include<bits/stdc++.h>
#define int int long long
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
const int mod=998244353;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=1;
	auto get = [&](int x,int d)->int{
		vector<int>temp(1);
		for(int i=2;i*i<=d;i++){
			if(d%i==0){
				temp.push_back(i);
				while(d%i==0)d/=i;
			}
		}
		if(d!=1)temp.push_back(d);
		int sz=temp.size()-1;
		int res=0;
		auto dfs = [&](auto self,int now,int sum,int cnt)->void{
			if(now==sz+1){
				if(cnt%2==0)res+=m/(x*sum);
				else res-=m/(x*sum);
				res%=mod;
				if(res<0)res+=mod;
				// dbg(x,sum,x*sum,res);
				return ;
			}
			self(self,now+1,sum,cnt);
			self(self,now+1,sum*temp[now],cnt+1);
		};
		dfs(dfs,1,1,0);
		return res;
	};
	for(int i=2;i<=n;i++){
		if(a[i-1]%a[i]!=0){
			ans=0;
			break;
		}
		int d=a[i-1]/a[i];
		//dbg(get(a[i],d));
		ans=ans*get(a[i],d)%mod;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}