#include<iostream>
#include<vector>
#include<string>
using namespace std;
char res[3005][3005];
int main(){
	for(int i=0;i<3005;i++){
		for(int j=0;j<3005;j++){
			res[i][j]=' ';
		}
	}
	//倒着
	res[0][0]=res[1][1]='/';
	res[0][1]=res[0][2]='_';
	res[0][3]=res[1][2]='\\';
	int n,len=4,k=1;
	cin>>n;
	while(k<n){
		//遍历n=1；
		for(int i=0;i<len/2;i++){
			for(int j=0;j<len;j++){
				//res[i+len/2][j+len/2]以坐标来看为复制到头上，res[i][j+len]复制到旁边
				res[i+len/2][j+len/2]=res[i][j+len]=res[i][j];
			}
		}
		len*=2;
		k++;
	}
	for(int i=len/2-1;i>=0;i--){
		for(int j=0;j<len;j++){
			cout<<res[i][j];
		}
		cout<<'\n';
	}
	return 0;
}
