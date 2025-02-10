#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
pair<char,int>a[maxn];
int js(int x){
	int cnt=0;
	while(x){
		cnt++;
		x/=2;
	}
	return cnt;
}
void solve(){
	string s;cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		a[i+1].first=s[i];
		a[i+1].second=i+1;
	}
	sort(a+1,a+1+len);
	int ans=INT_MAX;
	int res=0;
	for(int i=1;i<=len;i++){
		if(i==1)res=js(a[i].second-1);
		else{
			if(a[i].first==a[i-1].first){
				res=max(res,js(a[i].second-a[i-1].second-1));
			}else{
				res=max(res,js(len-a[i-1].second));
				ans=min(ans,res);
				res=js(a[i].second-1);
			}
		}
		if(i==len){
			if(a[i].first==a[i-1].first){
				res=max(res,js(len-a[i].second));
				ans=min(ans,res);
			}else{
				res=max(js(a[i].second-1),js(len-a[i].second));
				ans=min(ans,res);
			}
		}
	}
	if(ans==INT_MAX)cout<<0<<'\n';
	else cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
