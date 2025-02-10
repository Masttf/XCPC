#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	map<int,int>m;
	for(int i=1;i<=n;i++){
		a[i]-=abs(i-2);
		m[a[i]]++;
	}
	int ans=0;
	int res=0;
	for(int i=2;i<=n-1;i++){
		m[a[i]]--;
		if(m[a[i]]==0)m.erase(a[i]);
		auto it=m.end();
		it--;
		int j=0;
		int temp=0;
		while(j<2){
			temp+=it->first*min(2-j,it->second);
			j+=it->second;
			it--;
		}
		m[a[i]]++;
		ans=max(ans,temp+a[i]+3*res);
		res++;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
