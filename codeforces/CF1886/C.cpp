#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;cin>>s;
	int pos;cin>>pos;
	vector<int>res;
	int n=s.size();
	s=' '+s;
	for(int i=2;i<=n;i++){
		if(s[i-1]>s[i])res.push_back(i-1);
	}

	int ans=0;
	for(int i=0;i<n;i++){
		if(pos>(n-i)){
			pos-=n-i;
			ans=i+1;
		}else break;
	}
	vector<int>vis(n+1);
	int last=n;
	vector<int>pre(n+1),suf(n+1);
	pre[1]=1;
	for(int i=2;i<=n;i++){
		pre[i]=i-1;
	}

	suf[n]=n;
	for(int i=n-1;i>=1;i--){
		suf[i]=i+1;
	}

	for(int i=1,j=0;i<=ans;i++){
		if(j==res.size()){
			while(last>=1&&vis[last])last--;
			res.push_back(last);
		}
		int now=res[j];
		vis[now]=1;
		j++;
		if(pre[now]==now){
			if(suf[now]==now)continue;
			pre[suf[now]]=suf[now];
		}else{
			if(suf[now]==now){
				suf[pre[now]]=pre[now];
				continue;
			}
			pre[suf[now]]=pre[now];
			suf[pre[now]]=suf[now];
			if(s[suf[now]]<s[pre[now]])res[--j]=pre[now];
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i])cnt++;
		if(cnt==pos){
			cout<<s[i];
			return ;
		}
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