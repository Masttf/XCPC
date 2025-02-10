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
void solve(){
	int n,k;cin>>n>>k;
	vector<pair<int,int>>a(n+1);
	for(int i=0;i<=n;i++)cin>>a[i].first>>a[i].second;
	auto dis = [&](pair<int,int>x,pair<int,int>y)->double{
		return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
	};
	vector<double>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+dis(a[i],a[i-1]);
	vector<double>dp(n+1);
	vector<double>mi(n+1);
	deque<int>q;
	q.push_back(0);
	for(int i=1;i<=n;i++){
		dp[i]=mi[q.front()]+pre[i];
		mi[i]=dp[i]+dis(a[i],a[0])+dis(a[i+1],a[0])-pre[i+1];
		while(!q.empty()&&mi[i]<mi[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		if(i-q.front()>=k)q.pop_front();
	}
	cout<<fixed<<setprecision(10)<<dp[n]+dis(a[n],a[0])<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}

