#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	string a;cin>>a;
	string b;cin>>b;
	a=' '+a;
	b=' '+b;
	int ok=0;
	vector ans(n+1,vector<char>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[i][j]='.';
		}
	}
	auto check = [&](int x,int y,char t)->bool{
		for(int i=1;i<=x;i++){
			if(ans[i][y]==t)return false;
		}
		return true;
	};
	auto dfs = [&](auto self,int x)->void{
		if(ok)return ;
		if(x==n+1){
			int flag=1;
			for(int i=1;i<=n;i++){
				if(!flag)break;
				for(int j=1;j<=n;j++){
					if(ans[i][j]!='.'){
						if(ans[i][j]!=a[i])flag=0;
						break;
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(!flag)break;
				for(int i=1;i<=n;i++){
					if(ans[i][j]!='.'){
						if(ans[i][j]!=b[j])flag=0;
						break;
					}
				}
			}
			if(flag){
				ok=1;
				cout<<"Yes\n";
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++)cout<<ans[i][j];
					cout<<'\n';
				}
			}
			return ;
		}
		for(int i=1;i<=n;i++){
			if(!check(x,i,'A'))continue;
			ans[x][i]='A';
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				if(!check(x,j,'B'))continue;
				ans[x][j]='B';
				for(int k=1;k<=n;k++){
					if(i==k||j==k)continue;
					if(!check(x,k,'C'))continue;
					ans[x][k]='C';
					self(self,x+1);
					ans[x][k]='.';
				}
				ans[x][j]='.';
			}
			ans[x][i]='.';
		}
		return ;
	};

	dfs(dfs,1);
	if(!ok){
		cout<<"No\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}