#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
struct node{
	int first,second;
	bool operator <(const node&y)const{
		if(first!=y.first)return first<y.first;
		else return second>y.second;
	}
}a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int j=i;
		int cnt=0;
		while(j<=n&&a[j].first==a[i].first){
			if(cnt<a[i].first)ans+=a[j].second,cnt++;
			j++;
		}
		i=j-1;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
