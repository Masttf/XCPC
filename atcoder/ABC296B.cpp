#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[10];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(int i=0;i<8;i++)cin>>s[i];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(s[i][j]=='*')cout<<(char)(j+'a')<<(char)(7-i+'1');
		}
	}
	return 0;
}

