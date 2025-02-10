#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		if(i%2==1)pre[i]+=a[i]-a[i-1];
	}

	int m;cin>>m;
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		int p2=upper_bound(a.begin()+1,a.end(),r)-a.begin()-1;
		int p1=lower_bound(a.begin()+1,a.end(),l)-a.begin();
		int res=pre[p2]-pre[p1];
		//cout<<res<<endl;
		if(p2%2==0)res+=r-a[p2];
		if(p1%2==1)res+=a[p1]-l;
		//cout<<p1<<' '<<p2<<endl;
		cout<<res<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}