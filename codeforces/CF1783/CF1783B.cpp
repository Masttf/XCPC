//1,n方-1,2,n方-2这样迭代即可
//首先最大的数字是n方-1
//所以不同最多应该就是1到n方减1
//只考虑左边即链首先最大数的出现情况只能是1和n方，考虑第二大n方-1，只能是n方-2填2得到规律一大一小
#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int res[maxn][maxn];
bool vis[maxn*maxn];
void solve(){
	memset(vis,0,sizeof(vis));
	int n;cin>>n;
	int target=n*n-1,flag=1,fu=1;
	for(int i=1;i<=n;i++){
		if(flag){
			for(int j=1;j<=n;j++){
				if(i==1&&j==1){
					res[i][j]=1;
					vis[1]=1;
					continue;
				}
				if(j==1){
					res[i][j]=res[i-1][j]+fu*target;
					vis[res[i][j]]=1;
					fu=-fu;
					target--;
					continue;
				}
				int temp=res[i][j-1]+fu*target;
				if(vis[temp]){
					res[i][j]=res[i][j-1]-fu*target;
				}else res[i][j]=temp;
				vis[res[i][j]]=1;
				fu=-fu;
				target--;
			}
			flag=0;
		}else{
			for(int j=n;j>=1;j--){
				if(j==n){
					res[i][j]=res[i-1][j]+fu*target;
					vis[res[i][j]]=1;
					fu=-fu;
					target--;
					continue;
				}
				int temp=res[i][j+1]+fu*target;
				if(vis[temp]){
					res[i][j]=res[i][j+1]-fu*target;
				}else res[i][j]=temp;
				vis[res[i][j]]=1;
				fu=-fu;
				target--;
			}
			flag=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<res[i][j]<<' ';
		}
		cout<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
