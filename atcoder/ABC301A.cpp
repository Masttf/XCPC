#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	int c1=0,c2=0;
	for(int i=0;i<n;i++){
		if(s[i]=='T')c1++;
		else c2++;
	}
	if(c1>c2)cout<<"T";
	else if(c1<c2)cout<<"A";
	else{
		if(s[n-1]=='T')cout<<"A";
		else cout<<"T";
	}
	return 0;
}
