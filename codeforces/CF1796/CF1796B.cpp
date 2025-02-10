#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){//匹配
	string a,b;cin>>a>>b;//星号小于字母数
	if(a[0]==b[0]){
		cout<<"yes\n";
		cout<<a[0]<<'*'<<'\n';
	}else if(a[a.size()-1]==b[b.size()-1]){
		cout<<"yes\n";
		cout<<"*"<<a[a.size()-1]<<'\n';
	}else{
		int l=1,r=a.size()-1;
		for(int i=0;i<=r-1;i++){
			for(int j=0;j<b.size()-1;j++){
				if(a[i]==b[j]&&a[i+1]==b[j+1]){
					cout<<"yes\n";
					cout<<'*'<<a[i]<<a[i+1]<<'*'<<'\n';
					return ;
				}
			}
		}
		cout<<"no\n";
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
