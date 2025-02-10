#include<iostream>
#include<cmath>
using namespace std;
void shemian(int x,int y,int len);
int res[1050][1050];
int main(){
	int n;cin>>n;
	int len=pow(2,n);
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			res[i][j]=1;
		}
	}
	shemian(0,0,len);
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			cout<<res[i][j];
			if(j==len-1)
				cout<<'\n';
			else
				cout<<' ';
		}
	}
	return 0;
}
void shemian(int x,int y,int len){
	if(len==1)
		return ;
	for(int i=x;i<x+len/2;i++){
		for(int j=y;j<y+len/2;j++){
			res[i][j]=0;
		}
	}
	shemian(x+len/2,y,len/2);
	shemian(x,y+len/2,len/2);
	shemian(x+len/2,y+len/2,len/2);
}
