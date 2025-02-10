#include<bits/stdc++.h>
#define int long long 
using namespace std;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	int ans=0;
	int l1=0;
	int l2=0;
	for(int i=0;i<n;i++){
		int j=i;
		while(j<n&&s[j]==s[i])j++;
		j--;
		if(s[i]=='<'){
			l2=max(l2,j-i+1);
		}else{
			l1=max(l1,j-i+1);
		}
		i=j;
	}
	cout<<max(l1,l2)+1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
