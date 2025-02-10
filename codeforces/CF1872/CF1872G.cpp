#include<bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>res;
	int ok=0;
	int sum=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		sum*=a[i];
		if(sum>1000000000)ok=1;
		if(a[i]>1)res.push_back(i);
	}
	if(sum==1||res.size()==1){
		cout<<1<<' '<<1<<'\n';
		return ;
	}
	if(ok)cout<<res[0]<<' '<<res.back()<<'\n';
	else{
		vector<int>s(n+1);
		vector<int>mul(n+1);
		mul[0]=1;
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
			mul[i]=mul[i-1]*a[i];
		}
		int ans=s[n];
		int l=1,r=1;
		int len=res.size();
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				int val=s[n]-s[res[j]]+s[res[i]-1]+mul[res[j]]/mul[res[i]-1];
				if(ans<val){
					ans=val;
					l=res[i];
					r=res[j];
				}
			}
		}
		cout<<l<<' '<<r<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
