#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
string tarverse(int n);
int temp[10005];
vector<string>answer(15000);
int main(){
	int n;cin>>n;
	string s=tarverse(n);
	cout<<s<<'\n';
	return 0;
}
//定义返回宝箱上面的n个最少走多少步
//假设A,B,C三个柱子，如果n为3则先需要把两个盘移到B然后移C然后在把两个盘移到C
//string为正序，数组为倒序
string tarverse(int n){
	if(n==0)
		return "0";
	if(answer[n]>"0")
		return answer[n];
	//answer[n]=2*answer[n-1]+1
	answer[n-1]=tarverse(n-1);
	int len=answer[n-1].size();
	//string为正序
	for(int i=len-1,j=0;i>=0;i--,j++){
		int res=answer[n-1][i]-'0';
		if(i==len-1)
			temp[j]+=res*2+1;
		else
			temp[j]+=res*2;
		if(temp[j]>9)
		{
			if(j==len-1)
				len++;
			temp[j+1]++;
			temp[j]%=10;
		}
	}
	for(int i=len-1;i>=0;i--){
		answer[n]+=to_string(temp[i]);
	}
	memset(temp,0,sizeof(temp));
	return answer[n];
}
