#include<bits/stdc++.h>
#define int long long
using namespace std;
bool vis[30];
int js(int n){
	return (1+n)*n/2;
}
int ans,n,k;
string a,b;
void dfs(vector<char>choice,int now,int cnt){
	if(cnt>k)return ;
	if(cnt==k){
		int res=0;
		for(int i=0;i<n;i++){
			if(a[i]==b[i]||vis[a[i]-'a']){
				int len=0;
				while(i<n&&(a[i]==b[i]||vis[a[i]-'a']))len++,i++;
				res+=js(len);
			}
		}
		ans=max(ans,res);
		return ;
	}
	for(int i=now;i<choice.size();i++){
		vis[choice[i]-'a']=1;
		dfs(choice,i+1,cnt+1);
		vis[choice[i]-'a']=0;
	}
	return ;
}
void solve(){
	for(int i=0;i<30;i++)vis[i]=0;
	cin>>n>>k;//可以枚举k种选择
	cin>>a>>b;
	ans=js(k);
	vector<char>c;
	for(auto x:a){
		if(!vis[x-'a']){
			c.push_back(x);
			vis[x-'a']=1;
		}
	}
	if(c.size()<=k)cout<<js(n)<<'\n';
	else{
		for(int i=0;i<30;i++)vis[i]=0;
		dfs(c,0,0);
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
