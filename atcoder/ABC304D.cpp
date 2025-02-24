#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
pair<int,int>s[maxn];
int a[maxn],b[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int w,h;cin>>w>>h;
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i].first>>s[i].second;
	int A;cin>>A;
	for(int i=1;i<=A;i++)cin>>a[i];
	int B;cin>>B;
	for(int i=1;i<=B;i++)cin>>b[i];
	A++;
	a[A]=w;
	B++;
	b[B]=h;
	map<pair<int,int>,int>res;
	for(int i=1;i<=n;i++){
		int x=upper_bound(a+1,a+1+A,s[i].first)-a;
		int y=upper_bound(b+1,b+1+B,s[i].second)-b;
		res[{a[x],b[y]}]++;
	}
	int mx=0,mi=0;
	if(res.size()!=A*B)mi=0;
	else mi=INT_MAX;
	for(auto it=res.begin();it!=res.end();it++){
		mx=max(it->second,mx);
		mi=min(mi,it->second);
	}
	cout<<mi<<' '<<mx<<'\n';
	return 0;
}
