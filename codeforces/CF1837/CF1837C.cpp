#include<bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
	string s;cin>>s;
	int ans=s.size(),p=INT_MAX;
	int cnt0=0,cnt1=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='0'){
			int j=i;
			while(j>=0&&(s[j]=='0'||s[j]=='?'))j--;
			cnt0++;
			j++;
			i=j;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			int j=i;
			while(j<s.size()&&(s[j]=='1'||s[j]=='?'))j++;
			cnt1++;
			j--;
			i=j;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			int cost=cnt0+cnt1;
			if(ans==-1||p>cost){
				ans=i;
				p=cost;
			}
			if(i!=0&&s[i-1]=='0')cnt0--;
		}else if(s[i]=='0'){
			if(i!=0&&s[i-1]=='1')cnt1--;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='?'){
			if(i==0)s[i]='0';
			else s[i]=s[i-1];
		}
		cout<<s[i];
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
