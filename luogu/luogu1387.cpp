//二维数组前缀和加枚举
#include<iostream>
#include<algorithm>
using namespace std;
int ant[105][105];
int pre[105][105];
int main(){
	int n,m;
	cin>>n>>m;
	//拿到前缀和二维数组
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ant[i][j];
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+ant[i][j];
		}
	}
	int max_len=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ant[i][j]==1){
				for(int h=1;h<=min(n,m);h++){
					//超范围不要
					if(i+h>n||j+h>m)break;
					//出现0不要
					if((pre[i+h][j+h]-pre[i+h][j-1]-pre[i-1][j+h]+pre[i-1][j-1])!=(h+1)*(h+1))break;
					max_len=max(max_len,h+1);
				}
			}
		}
	}
	cout<<max_len;
	return 0;
}
