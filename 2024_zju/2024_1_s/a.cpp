#include<bits/stdc++.h>
#define int long long
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
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	vector<int>f(n+5);
	for(int i=1;i<=n+1;i++)f[i]=i;
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	int sz=n;
	vector<int>cnt(n+1);
	for(int i=1;i<=n;i++){
		if(a[i]%i==0){
			cnt[a[i]/i]++;
		}
	}
	for(int i=1;i<=n;i++){
		ans+=cnt[i]*(cnt[i]-1)/2;
	}
	for(int i=1;i<=n;i++)cnt[i]=1;
	while(sz>1){
		for(int i=1;i<=n;i++){
			i=find(find,i);
			if(i>n)break;
			if(a[i]>0)cnt[a[i]]--;
			a[i]-=i;
			if(a[i]>0)cnt[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			i=find(find,i);
			if(i>n)break;
			if(a[i]<0&&a[i]>-n){
				ans+=cnt[abs(a[i])];
			}else if(a[i]<-n){
				sz--;
				f[i]=i+1;
			}
		}
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