#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int len=s.size();
	s=' '+s;
	int cnt=0;
	int last=0;
	int first=0;
	int ok=1;
	for(int i=1;i<=len;i++){
		if(s[i]=='+')cnt++;
		else if(s[i]=='-'){
			cnt--;
			if(last>cnt)last=cnt;
			if(first>cnt)first=0;
		}
		else{
			if(s[i]=='1'){
				if(first!=0)ok=0;
				last=cnt;
			}else{
				if(cnt<=1||last==cnt)ok=0;
				else{
					if(first==0)first=cnt;
				}
			}
		}
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
