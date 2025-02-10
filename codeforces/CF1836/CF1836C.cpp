#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,b,c,k;cin>>a>>b>>c>>k;
	if(max(a,b)>c||max(a,b)+1<c){
		cout<<-1<<'\n';
		return ;
	}
	int t1=1,t2=1,t3=1;
	int m1=9,m2=9,m3=9;
	for(int i=1;i<a;i++)t1*=10,m1=m1*10+9;
	for(int i=1;i<b;i++)t2*=10,m2=m2*10+9;
	for(int i=1;i<c;i++)t3*=10,m3=m3*10+9;
	int cnt=0;
	for(int i=t1;i<=m1;i++){
		int mx=m3-i;
		int mi=t3-i;
		mx=min(mx,m2);
		mi=max(mi,t2);
		if(mx<mi)continue;
		if(cnt+mx-mi+1>=k){
			int d=k-cnt;
			int res2=mi+d-1;
			cout<<i<<" + "<<res2<<" = "<<i+res2<<'\n';
			return ;
		}
		cnt+=mx-mi+1;
	}
	cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
