#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	map<int,int>m;
	int n;cin>>n;
	int x;
	for(int i=1;i<=n;i++)cin>>x,m[x]++;
	int cnt=0;
	int l1=0,l2=0;
	for(auto iter=m.begin();iter!=m.end();iter++){
		if(iter==m.begin()){
			l1=iter->first;
			l2=iter->second;
			cnt+=l2;
		}else{
			int now=iter->first;
			int n2=iter->second;
			if(now==l1+1){
				if(n2>l2)cnt+=n2-l2;
			}else cnt+=n2;
			l1=now,l2=n2;
		}
	}
	cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
