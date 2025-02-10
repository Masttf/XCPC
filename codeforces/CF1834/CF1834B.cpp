#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string  l,r;cin>>l>>r;
	int lenr=r.size();
	int lenl=l.size();
	for(int i=1;i<=lenr-lenl;i++)l="0"+l;
	int ans=0;
	int i=0;
	while(i<lenr&&r[i]==l[i])i++;
	ans+=r[i]-l[i];
	i++;
	for(;i<lenr;i++){
		ans+=9;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
