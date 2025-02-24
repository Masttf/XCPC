#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	string s,t;
	string ans="";
	cin>>s>>t;
	int flag=0;
	for(int i=0;i<n;i++){
		if(t[i]=='A'||t[i]=='C'||t[i]=='M'){
			ans+=s[i];
			flag=1;
		}else{
			if(flag)ans+=' ';
			flag=0;
		}
	}
	int sz=ans.size();
	if(ans[sz-1]==' ')sz--;
	for(int i=0;i<sz;i++){
		cout<<ans[i];
	}
	return 0;
}
