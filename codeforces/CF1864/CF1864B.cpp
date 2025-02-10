#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	if(k%2==0){
		sort(s.begin(),s.end());
		cout<<s<<'\n';
		return ;
	}else{
		string res1,res2;
		for(int i=0;i<n;i++){
			if(i%2==0)res1+=s[i];
			else res2+=s[i];
		}
		sort(res1.begin(),res1.end());
		sort(res2.begin(),res2.end());
		for(int i=0;i<n/2;i++)cout<<res1[i]<<res2[i];
		if(n%2==1)cout<<res1[n/2];
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
