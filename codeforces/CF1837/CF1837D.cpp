#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+5;
int color[maxn];
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int c1=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(')c1++;
	}
	if(c1*2!=n){
		cout<<-1<<'\n';
		return ;
	}
	string temp=s;
	for(int i=0;i<n;i++){
		if(temp[i]=='(')temp[i]=')';
		else temp[i]='(';
	}
	int f1=1;
	int f2=1;
	int k=0;
	for(int i=0;i<n;i++){
		if(s[i]=='(')k++;
		else k--;
		if(k<0)f1=0;
	}
	k=0;
	for(int i=0;i<n;i++){
		if(temp[i]=='(')k++;
		else k--;
		if(k<0)f2=0;
	}
	if(f1||f2){
		cout<<1<<'\n';
		for(int i=1;i<=n;i++)cout<<1<<' ';
		cout<<'\n';
		return ;
	}
	cout<<2<<'\n';
	k=0;
	int cnt=0;
	for(int i=0;i<n;i++)color[i]=1;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			if(cnt>0){
				cnt--;
				color[i]=2;
			}else k++;
		}
		else{
			if(k>0){
				k--;
			}else{
				cnt++;
				color[i]=2;
			}
		}
	}
	for(int i=0;i<n;i++)cout<<color[i]<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
