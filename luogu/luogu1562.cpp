#include<iostream>
using namespace std;
#define lowbit(x) ((x)&(-x))
int cnt;
char res[30][30];
int f[30];
int n;
void dfs(int use1,int use2,int use3,int row){
	if(row==n){
		cnt++;
		return;
	}
	int p=((1<<n)-1)&(~(use1|use2|use3|f[row]));
	while(p){
		dfs(use1+lowbit(p),(use2+lowbit(p))<<1,(use3+lowbit(p))>>1,row+1);
		p-=lowbit(p);
	}
	return ;
}
int main(){
	cin>>n;
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>res[i][j];
			if(res[i][j]=='.'){
				f[i]+=(1<<(n-j-1));//表示第几行已经第几个不能放
			}
		}
		getchar();
	}
	dfs(0,0,0,0);
	cout<<cnt;
	return 0;
}
