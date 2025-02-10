#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
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
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	auto get = [&]()->int{
		int res=INT_MAX;
		deque<int>q;
		for(int i=1;i<=n;i++){
			while(!q.empty()&&a[i]<q.back()){
				q.pop_back();
			}
			q.push_back(a[i]);
		}
		if(q.size()==n)return 0;
		for(int i=1;i<=n;i++){
			if(q.front()==a[i])q.pop_front();
			while(!q.empty()&&a[i]<q.back()){
				q.pop_back();
			}
			q.push_back(a[i]);
			if(q.size()==n){
				res=min(res,n-i);
			}
			//dbg(q.size());
		}
		return res;
	};
	auto get2 = [&]()->int{
		int res=INT_MAX;
		deque<int>q;
		for(int i=1;i<=n;i++){
			while(!q.empty()&&a[i]>q.back()){
				q.pop_back();
			}
			q.push_back(a[i]);
		}
		if(q.size()==n)return 0;
		for(int i=1;i<=n;i++){
			if(q.front()==a[i])q.pop_front();
			while(!q.empty()&&a[i]>q.back()){
				q.pop_back();
			}
			q.push_back(a[i]);
			if(q.size()==n){
				res=min(res,n-i);
			}
			//dbg(q.size());
		}
		return res;
	};
	int ans=get();
	
	//dbg("yes");
	ans=min(ans,get2()+1);
	for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
	ans=min(ans,get()+1);
	ans=min(ans,get2()+2);
	if(ans==INT_MAX)cout<<-1<<'\n';
	else cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}