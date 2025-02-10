#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	map<int,int>pre,cnt;
	pre[-1]=0;
	cnt[0]++;
	for(int i=0;i<s.size();i++){
		pre[i]=pre[i-1]^(1LL<<(s[i]-'0'));
		cnt[pre[i]]++;
	}
	int ans=0;
	for(int i=s.size()-1;i>=0;i--){
		ans+=cnt[pre[i]]-1;//要去掉自己
		cnt[pre[i]]--;
	}
	cout<<ans;
	return 0;
}
