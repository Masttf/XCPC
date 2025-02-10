#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	s=' '+s;
	vector<int>l(k+1);
	vector<int>r(k+1);
	for(int i=1;i<=k;i++)cin>>l[i];
	for(int i=1;i<=k;i++)cin>>r[i];
	int q;cin>>q;
	vector<int>c(n+5);
	for(int i=1;i<=q;i++){
		int x;cin>>x;
		int p=upper_bound(l.begin()+1,l.end(),x)-l.begin()-1;
		int a=min(x,l[p]+r[p]-x);
		int b=max(x,l[p]+r[p]-x);
		c[a]++;
		c[b+1]--;
	}
	for(int i=1;i<=n;i++)c[i]+=c[i-1];
	for(int i=1;i<=k;i++){
		int len=(r[i]-l[i]+1)/2;
		for(int j=0;j<len;j++){
			if(c[j+l[i]]%2==1)swap(s[j+l[i]],s[r[i]-j]);
		}
	}
	for(int i=1;i<=n;i++)cout<<s[i];
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
