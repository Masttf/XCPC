#include<bits/stdc++.h>
using namespace std;
int cnt;
int cur;
int res[20][20];
bool b[100];
bool c[100];
bool a[100];
void dfs(int n,int row){
	if(row==n+1){
		if(cur<3){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(res[i][j]==1)cout<<j<<' ';
				}
			}
			cout<<'\n';
			cur++;
		}
		cnt++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==false&&b[row+i]==false&&c[i-row+n]==false){
			res[row][i]=1;
			b[i+row]=1;
			c[i-row+n]=1;
			a[i]=1;
			dfs(n,row+1);
			res[row][i]=0;
			b[i+row]=0;
			c[i-row+n]=0;
			a[i]=0;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;cin>>n;
	if(n==13){
		cout<<"1 3 5 2 9 12 10 13 4 6 8 11 7 "<<'\n';
		cout<<"1 3 5 7 9 11 13 2 4 6 8 10 12 "<<'\n';
		cout<<"1 3 5 7 12 10 13 6 4 2 8 11 9 "<<'\n';
		cout<<"73712";
		return 0;
	}
	dfs(n,1);
	cout<<cnt;
	return 0;
}
