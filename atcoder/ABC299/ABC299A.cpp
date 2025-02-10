#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	string s;cin>>s;
	int p1=-1,p2=-1,k=-1;
	for(int i=0;i<n;i++){
		if(s[i]=='|'){
			if(p1==-1)p1=i;
			else p2=i;
		}
		if(s[i]=='*')k=i;
	}
	if(p1<k&&k<p2)cout<<"in";
	else cout<<"out";
	return 0;
}
