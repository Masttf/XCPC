#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<string>a(n+1);
	for(int i=0;i<n;i++)cin>>a[i];
	string s;cin>>s;
	string temp="<3";
	for(int i=0;i<n;i++){
		temp+=a[i];
		temp+="<3";
	}
	int now=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(now==temp.size())break;
		if(s[i]==temp[now])now++;
	}
	if(now==temp.size())cout<<"yes";
	else cout<<"no";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}