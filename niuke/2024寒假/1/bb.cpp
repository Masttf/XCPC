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
	int n;cin>>n;
	if(n==0){
		cout<<3<<'\n';
		return ;
	}
	vector<int>res1;
	vector<int>res2;
	vector<pair<int,int>>res(n+1);
	for(int i=1;i<=n;i++){
		int r,x;cin>>r>>x;
		if(r==1)res1.push_back(x);
		else res2.push_back(x);
		res[i]={r,x};
	}
	sort(res1.begin(),res1.end());
	res1.erase(unique(res1.begin(),res1.end()),res1.end());
	sort(res2.begin(),res2.end());
	res2.erase(unique(res2.begin(),res2.end()),res2.end());

	int ans1=2,ans2=2;
	for(auto x:res1){
		int pd=lower_bound(res2.begin(),res2.end(),x-1)-res2.begin();
		if(pd==res2.size()){
			if(x<0)ans1=min(ans1,1ll);
			else ans2=min(ans2,1ll);
			continue;
		}
		int d=res2[pd];
		if(d>=x-1&&d<=x+1){
			if(x<0)ans1=0;
			else ans2=0;
		}else{
			if(x<0)ans1=min(ans1,1ll);
			else ans2=min(ans2,1ll);
		}
	}
	int aans=3;
	for(auto x:res2){
		if(x==0){
			int pd1=lower_bound(res1.begin(),res1.end(),x-1)-res1.begin();
			int pd2=lower_bound(res1.begin(),res1.end(),x+1)-res1.begin();
			int cnt=2;
			if(pd1!=res1.size()&&res1[pd1]==x-1)cnt--,ans1=0;
			else ans1=min(ans1,1ll);
			if(pd2!=res1.size()&&res1[pd2]==x+1)cnt--,ans2=0;
			else ans2=min(ans2,1ll);
			aans=min(aans,cnt);
			continue;
		}
		int pd=lower_bound(res1.begin(),res1.end(),x-1)-res1.begin();
		if(pd==res1.size()){
			if(x<0)ans1=min(ans1,1ll);
			else ans2=min(ans2,1ll);
			continue;
		}
		int d=res1[pd];
		if(d>=x-1&&d<=x+1){
			if(x<0)ans1=0;
			else ans2=0;
		}else{
			if(x<0)ans1=min(ans1,1ll);
			else ans2=min(ans2,1ll);
		}
	}
	int ct=0;
	for(int i=1;i<=n;i++){
		if(res[i].first==1){
			if(res[i].second==-1||res[i].second==1)ct++;
		}else{
			if(res[i].second==0)ct++;
		}
	}
	aans=min(aans,3-ct);
	//dbg(ans1,ans2);
	cout<<min(aans,ans1+ans2)<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--){
		solve();
		//dbg(t);
	}
	return 0;
}