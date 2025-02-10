#include<iostream>
using namespace std;
//数组返回符合n的个数
int F[1005];
//定义函数返回也是符合n的个数
int f(int n){
	//base case
	if(n==1)
		return 1;
	//备忘录
	if(F[n])return F[n];
	int ans=1;
	for(int i=1;i<=n/2;i++){
		ans+=f(i);
	}
	F[n]=ans;
	return F[n];
}
int main(){
	int n;
	cin>>n;
	F[0]=1;
	cout<<f(n)<<'\n';
	
}
