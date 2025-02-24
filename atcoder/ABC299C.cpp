#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	int ans=-1;
	for(int i=0;i<n;i++){
		if(s[i]=='-'){
			int len=0;
			while(i!=n&&s[i+1]=='o')i++,len++;
			if(len)ans=max(ans,len);
		}
	}
	for(int i=n-1;i>=0;i--){
		if(s[i]=='-'){
			int len=0;
			while(i&&s[i-1]=='o')i--,len++;
			if(len)ans=max(ans,len);
		}
	}
	cout<<ans;
	return 0;
}
