#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++)cin>>a[i],p.push_back(a[i]);

	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};

	vector<int>l(n+1);
	vector<int>r(n+1);
	for(int i=1;i<=n;i++){
		a[i]=get(a[i]);
		if(!l[a[i]])l[a[i]]=i;
		r[a[i]]=max(r[a[i]],i);
	}
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(r[a[i]]==i){
			ans+=cnt;
		}
		if(l[a[i]]==i)cnt++;
		if(l[a[i]]==r[a[i]])ans++;
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