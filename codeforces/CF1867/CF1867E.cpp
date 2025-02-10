#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	int temp=n;
	int res=0;
	int now=1;
	while(temp>=k){
		cout<<"? "<<now<<endl;
		temp-=k;
		now+=k;
		int x;cin>>x;
		res^=x;
	}
	if(temp){
		now-=k;
		cout<<"? "<<now<<endl;
		int x;cin>>x;
		int len=temp/2;
		cout<<"? "<<now+len<<endl;
		cin>>x;
		res^=x;
		cout<<"? "<<n-k+1<<endl;
		cin>>x;
		res^=x;
	}
	cout<<"! "<<res<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
