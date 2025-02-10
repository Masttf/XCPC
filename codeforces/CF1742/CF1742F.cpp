#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[30],t[30];
void solve(){
	for(int i=0;i<30;i++)s[i]=0,t[i]=0;
	s[0]=1,t[0]=1;
	int q;cin>>q;
	char m1='a',m2='a';
	for(int i=1;i<=q;i++){
		int ty,k;
		string x;
		cin>>ty>>k>>x;
		if(ty==1){
			for(auto ch:x){
				s[ch-'a']+=k;
				m1=max(m1,ch);
			}
		}else{
			for(auto ch:x){
				t[ch-'a']+=k;
				m2=max(m2,ch);
			}
		}
		//判断s是不是比t小
		if(m2>'a')cout<<"YES\n";
		else{
			if(m1!='a'){
				cout<<"NO\n";
			}else{
				if(s[0]>=t[0])cout<<"NO\n";
				else cout<<"YES\n";
			}
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
