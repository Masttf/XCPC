//b
#include<bits/stdc++.h>
using namespace std;
bool vis[55];
int ans[55];
int main(){
	for(int i=1;i<=52;i++){
		ans[i]+=ans[i-1]+i;
	}
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		memset(vis,0,sizeof(vis));
		int m,s;
		cin>>m>>s;
		int sum=0;
		int x;
		int mx=1;
		int temp;
		for(int j=1;j<=m;j++){
			cin>>x;
			vis[x]=1;
			mx=max(mx,x);
			sum+=x;
		}
		temp=ans[mx]-sum;
		if(temp>s){
			cout<<"NO"<<'\n';
			continue;
		}
		while(temp<s){
			temp+=++mx;
		}
		if(temp==s)cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
	return 0;
}
