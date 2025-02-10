#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	string ans="";
	int cnt1=0;
	int cnt2=0;
	for(int i=n;i>=1;i--){
		if(s[i]=='b')cnt1++;
		else if(s[i]=='B')cnt2++;
		else{
			if(s[i]>='a'&&s[i]<='z'){
				if(cnt1)cnt1--;
				else ans+=s[i];
			}else{
				if(cnt2)cnt2--;
				else ans+=s[i];
			}
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}