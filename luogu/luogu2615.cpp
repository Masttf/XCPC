#include<bits/stdc++.h>
using namespace std;
int res[45][45];
int main(){
	int n;cin>>n;
	res[1][(n+1)>>1]=1;
	int cnt=2;
	int temp1=1;//记录行
	int temp2=(n+1)>>1;//记录列
	while(cnt<=n*n){
		if(temp1==1&&temp2!=n){
			res[n][temp2+1]=cnt;
			temp1=n;
			temp2++;
		}else if(temp2==n&&temp1!=1){
			res[temp1-1][1]=cnt;
			temp1--;
			temp2=1;
		}else if(temp1==1&&temp2==n){
			res[temp1+1][temp2]=cnt;
			temp1++;
		}else if(temp1!=1&&temp2!=n){
			if(res[temp1-1][temp2+1]==0){
				res[temp1-1][temp2+1]=cnt;
				temp1--;
				temp2++;
			}else{
				res[temp1+1][temp2]=cnt;
				temp1++;
			}
		}
		cnt++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<res[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
