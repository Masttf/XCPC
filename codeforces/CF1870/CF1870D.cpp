#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>ans(n+5);
	map<int,int>m;
	for(int i=1;i<=n;i++)cin>>a[i],m[a[i]]=i;
	int k;cin>>k;
	int last=0;
	int cnt=0;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second<last)continue;
		if(last==0){
			if(k>=it->first){
				last=it->second;
				cnt=k/it->first;
				k-=it->first*cnt;
				ans[1]+=cnt;
				ans[it->second+1]-=cnt;
			}
		}else{
			if(k+a[last]>=it->first){
				int d=it->first-a[last];
				cnt=min(cnt,k/d);//k/d有可能比cnt大 cnt 1 d 1 k 2
				k-=d*cnt;
				ans[last+1]+=cnt;
				ans[it->second+1]-=cnt;
				last=it->second;
			}
		}
	}
	for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
