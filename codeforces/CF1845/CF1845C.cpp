#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5;
int p[maxn][10];
void solve(){
	string s;cin>>s;
	int n;cin>>n;
	string l,r;cin>>l>>r;
	int len=s.size();
	for(int i=0;i<10;i++)p[len][i]=len;
	for(int i=len-1;i>=0;i--){
		for(int j=0;j<10;j++)p[i][j]=p[i+1][j];
		p[i][s[i]-'0']=i;
	}
	int ok=0;
	int tem=-1;
	for(int i=0;i<n;i++){
		int mx=0;
		for(int j=l[i]-'0';j<=r[i]-'0';j++){
			if(p[tem+1][j]==len)ok=1;
			else mx=max(mx,p[tem+1][j]);
		}
		tem=mx;
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
