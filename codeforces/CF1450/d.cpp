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
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>ans(n+1);
	ans[1]=1;
	vector<int>cnt(n+1);
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
		if(cnt[a[i]]>=2)ans[1]=0;
	}
	auto check = [&](int x)->bool{
		//dbg(x);
		vector<int>ct(n+1);
		deque<int>q;
		for(int i=1;i<=x;i++){
			while(!q.empty()&&a[i]<q.back())q.pop_back();
			q.push_back(a[i]);
		}
		//dbg(q.front());
		ct[q.front()]++;
		if(q.front()>n-x+1)return false;
		for(int i=x+1,j=1;i<=n;i++,j++){
			while(!q.empty()&&a[i]<q.back())q.pop_back();
			q.push_back(a[i]);
			if(q.front()==a[j])q.pop_front();
			ct[q.front()]++;
			//dbg(q.front());
			if(ct[q.front()]==2||q.front()>n-x+1)return false;
		}
		return true;
	};
	int l=2,r=n;
	int p=n+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			p=mid;
			r=mid-1;
		}else l=mid+1;
	}
	for(int i=1;i<=n;i++){
		if(i<p)cout<<ans[i];
		else cout<<1;
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}