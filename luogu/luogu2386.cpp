#include<iostream>
using namespace std;
int res[25][25];
int get_answer(int m,int n);
int main(){
	int t;cin>>t;
	while(t--){
		int n,m;
		cin>>m>>n;
		cout<<get_answer(m,n)<<'\n';
	}
	return 0;
}
//m是水果数，n是盘子
int get_answer(int m,int n){
	if(n==1){
		return 1;
	}
	if(m<=0)
		return 1;
	if(m<n)return get_answer(m,m);
	if(res[n][m])
		return res[n][m];
	//总情况数为空一个盘子加上全部盘子不空
	res[n][m]=get_answer(m,n-1)+get_answer(m-n,n);
	return res[n][m];
	
}
