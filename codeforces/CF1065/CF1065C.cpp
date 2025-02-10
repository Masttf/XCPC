//差分加贪心
#include<iostream>
#include<algorithm>
using namespace std;
int deff[200005];
int main(){
	int n,k;
	cin>>n>>k;
	int max=0,min=INT_MAX;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		max=max>x?max:x;
		min=min>x?x:min;
		//差分拿到每层的个数
		deff[1]++;
		deff[x+1]--;
	}
	for(int i=1;i<=max+1;i++){
		deff[i]+=deff[i-1];//拿到每个高度的个数
	}
	int s=0;//储存容量
	int h=max;//当前的H为h-1；
	int cnt=0;
	while(h>min){
		if(s+deff[h]<=k){
			s+=deff[h];
		}
		else{
			cnt++;
			s=deff[h];
		}
		h--;
	}
	if(s>0){
		cnt++;
	}
	cout<<cnt;
	return 0;
}
