#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
void solve(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	vector<int>p0(n),p1(n);
	for(int i=n-1;i>=0;i--){
		if(s[i]=='1')continue;
		int j=i;
		while(j>=0&&s[j]==s[i]){
			p0[j]=i;
			j--;
		}
		i=j+1;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0')continue;
		int j=i;
		while(j<n&&s[j]==s[i]){
			p1[j]=i;
			j++;
		}
		i=j-1;
	}
	map<pair<int,int>,int>ans;
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		l--;
		r--;
		if(s[l]=='0')l=p0[l],l++;
		if(s[r]=='1')r=p1[r],r--;
		if(l<r)ans[{l,r}]++;
		else ans[{0,0}]++;
	}
	cout<<ans.size()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
