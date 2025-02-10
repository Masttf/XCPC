#include<iostream>
#include<string>
using namespace std;
int res[10005];
int main(){
	int n;
	cin>>n;
	//an=2的n次方-1
	//零次方
	int temp=0;
	res[0]=1;
	int len=1;
	while(n--){
		for(int i=0;i<len;i++){
			res[i]=res[i]*2+temp;
			if(res[i]>9){
				temp=res[i]/10;
				res[i]%=10;
				if(i==len-1)
					len++;
			}
			else
				temp=0;
		}
	}
	if(res[0]>0){
		res[0]--;
	}
	else
		res[1]--;
	for(int i=len-1;i>=0;i--){
		cout<<res[i];
	}
}
