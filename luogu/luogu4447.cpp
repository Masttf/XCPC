//题意即遍历ai时将ai插到符合组，这个组的人数最少
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int lis[100005],number[100005],cnt;//lis存储组，number记录该组人数，cnt表示当前有多少组
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){//遍历所有的ai
		int mx=INT_MAX;//得到符合组长度最小
		bool find=0;//判断是否找到符合的组
		int res=0;//记录找到组的位置
		for(int j=1;j<=cnt;j++){
			if(lis[j]==a[i]-1&&number[j]<mx){
				mx=number[j];
				res=j;
				find=1;
			}
		}
		if(find){//找到
			lis[res]=a[i];
			number[res]++;
		}else{//没找到再开一个小组
			lis[++cnt]=a[i];
			number[cnt]=1;
		}
		
	}
	int mn=INT_MAX;
	for(int i=1;i<=cnt;i++){
		mn=min(mn,number[i]);
	}
	cout<<mn;
	return 0;
}
