#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int flag=0;
	string t1,t2;
	for(int i=1;i<=2*(n-1);i++){
		string temp;cin>>temp;
		if(temp.size()==n-1){
			if(flag==0)t1=temp,flag=1;
			else t2=temp;
		}
	}
	flag=1;
	for(int i=1;i<n-1;i++){
		if(t1[i]!=t2[i-1]){
			flag=0;
			break;
		}
	}
	string ans="";
	if(flag){
		ans=t1;
		ans+=t2[n-2];
	}else{
		ans=t2;
		ans+=t1[n-2];
	}
	flag=1;
	for(int i=0;i<n/2;i++){
		if(ans[i]!=ans[n-1-i]){
			flag=0;
			break;
		}
	}
	if(flag)cout<<"yes\n";
	else cout<<"no\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
