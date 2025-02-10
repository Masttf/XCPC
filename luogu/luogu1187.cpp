#include<bits/stdc++.h>
using namespace std;
char ans[1005][1005];
int res[1005][1005];
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>ans[i][j];
			res[i][j]=ans[i][j]-'0';
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(res[i][j]==0){
				continue;
			}
			int temp=res[i][j]*6-(res[i][j]-1)*2;
			//上
			if(res[i][j]>=res[i+1][j]){
				temp-=res[i+1][j];
			}else{
				temp-=res[i][j];
			}
			//下
			if(res[i][j]>=res[i-1][j]){
				temp-=res[i-1][j];
			}else{
				temp-=res[i][j];
			}
			//左
			if(res[i][j]>=res[i][j-1]){
				temp-=res[i][j-1];
			}else{
				temp-=res[i][j];
			}
			//右
			if(res[i][j]>=res[i][j+1]){
				temp-=res[i][j+1];
			}else{
				temp-=res[i][j];
			}
			sum+=temp;
		}
	}
	cout<<sum;
	return 0;
}
