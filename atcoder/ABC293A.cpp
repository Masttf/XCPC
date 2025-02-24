#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	int len=s.size();
	for(int i=0;i<len/2;i++){
		swap(s[2*(i+1)-2],s[2*(i+1)-1]);
	}
	cout<<s;
	return 0;
}
