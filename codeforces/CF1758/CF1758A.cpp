#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		string temp=s;
		reverse(s.begin(),s.end());
		cout<<temp+s<<'\n';
	}
	return 0;
}
