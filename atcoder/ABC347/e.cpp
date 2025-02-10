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
const int mod=1e9+7;
const int Max=1e18;
void solve(){
	int n,q;cin>>n>>q;
	vector<int>ans(n+1);
	set<int>s;
	vector<int>res(q+1),val(q+1);
	for(int i=1;i<=q;i++){
		int x;cin>>x;
		res[i]=x;
		if(s.count(x)){
			s.erase(x);
			val[i]=s.size();
		}else{
			s.insert(x);
			val[i]=s.size();
		}
	}
	vector<int>pre(q+1);
	for(int i=1;i<=q;i++)pre[i]=pre[i-1]+val[i];
	vector<int>last(n+1);
	vector<int>cnt(n+1);
	for(int i=1;i<=q;i++){
		int x=res[i];
		cnt[x]++;
		if(cnt[x]%2==0)ans[x]+=pre[i-1]-pre[last[x]-1];
		last[x]=i;
	}
	for(int i=1;i<=n;i++){
		if(last[i]&&cnt[i]%2==1){
			ans[i]+=pre[q]-pre[last[i]-1];
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}