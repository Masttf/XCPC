#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1[30],c2[30];
void solve(){
	for(int i=0;i<30;i++)c1[i]=0,c2[i]=0;
	int n,k;cin>>n>>k;
	string s;cin>>s;
	string t;cin>>t;
	for(int i=0;i<n;i++){
		c1[s[i]-'a']++;
		c2[t[i]-'a']++;
	}
	int f=1;
	for(int i=0;i<30;i++){
		if(c1[i]!=c2[i])f=0;
	}
	if(!f)cout<<"no\n";
	else{
		for(int i=0;i<n;i++){
			if(i-k<0&&i+k>=n){
				if(s[i]!=t[i])f=0;
			}
		}
		if(f)cout<<"yes\n";
		else cout<<"no\n";
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
