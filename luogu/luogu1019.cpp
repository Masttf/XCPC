#include<bits/stdc++.h>
using namespace std;
string res[25];
int vis[25];
int ans,n;
void dfs(string x,int len){
	ans=max(ans,len);
	for(int i=1;i<=n;i++){
		int l=1,la=x.size(),lb=res[i].size();
		while(l<min(la,lb)){
			if(x.substr(la-l)==res[i].substr(0,l)&&vis[i]<2){
				vis[i]++;
				dfs(res[i],len+lb-l);
				vis[i]--;
				break;
			}
			l++;
		}
	}
	return ;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	char t;cin>>t;
	for(int i=1;i<=n;i++){
		if(res[i][0]==t){
			vis[i]++;
			dfs(res[i],res[i].size());
			vis[i]--;
		}
	}
	cout<<ans;
	return 0;
}
