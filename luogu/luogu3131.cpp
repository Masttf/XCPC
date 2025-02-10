//拿到前缀和数组，能被7整除的区间，即找到两个%7余数相同的前缀和；
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> pre(7);
int ant[100000];
int main(){
	int n;cin>>n;
	int x;
	int distacnce=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		ant[i]=(ant[i-1]+x)%7;
		pre[ant[i]].push_back(i);
		if(ant[i]==0){
			distacnce=max(distacnce,i);
		}
	}
	for(int i=0;i<7;i++){
		int len=pre[i].size();
		if(len>=2){
			distacnce=max(distacnce,pre[i][len-1]-pre[i][0]);
		}
	}
	cout<<distacnce;
	return 0;
}
