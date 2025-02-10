#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int res;
	map<int,int>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>res;
		for(int i=2;i<=res/2;i++){
			if(res%i==0){
				while(res%i==0){
					res/=i;
					sum++;
					m[i]++;
				}
			}
		}
		if(res>1)m[res]++,sum++;
	}
	if(sum<=1)cout<<0<<'\n';
	else if(sum==2&&m.size()==1)cout<<1<<'\n';
	else if(sum==2)cout<<0<<'\n';
	else{
		int ans=0;
		for(auto it=m.begin();it!=m.end();it++){
			if(it->second>=2){
				int d=it->second/2;
				ans+=d;
				sum-=d*2;
			}
		}
		ans+=sum/3;
//		sum%=3;
//		if(sum==1||sum==2)ans--;
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
