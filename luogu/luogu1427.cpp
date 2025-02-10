#include<bits/stdc++.h>
using namespace std;
int res[105];
int main(){
	int x;
	int cnt=0;
	while(1){
		scanf("%d",&x);
		if(x==0)break;
		res[++cnt]=x;
	}
	for(int i=cnt;i>=1;i--){
		printf("%d ",res[i]);
	}
}
