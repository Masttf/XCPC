#include<bits/stdc++.h>
#define int long long//逆向思维
using namespace std;
int cnt[30];
void solve(){
	for(int i=0;i<30;i++)cnt[i]=0;
	string s;cin>>s;//为什么这就是最小呢
	int ans=s.size();
	int m=0;
	for(int i=0;i<ans;i++){
		if(cnt[s[i]-'a']){//为什么把两个数中间的删掉会是最优的
			m+=2;//我要删的最少说明我剩下的偶数对是最长的因此只要找出最长的偶数对最长
			for(int j=0;j<30;j++)cnt[j]=0;//而这个只要一开始一直取就行，因为删掉中间的贡献也就1对，不删掉中间的贡献多一对，还往后跑了
		}else cnt[s[i]-'a']=1;
	}
	cout<<ans-m<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
