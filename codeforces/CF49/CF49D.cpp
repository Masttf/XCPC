//通过测试两种改变需要的次数选最少的
#include<iostream>
using namespace std;
int main(){
	int n;cin>>n;
	string s;
	cin>>s;
	int count1=0;
	int count2=0;
	for(int i=0;i<s.size();i++){
		if(i%2==0){
			if(s[i]=='1')
				count2++;
			else
				count1++;
		}else if(i%2!=0){
			if(s[i]=='0')
				count2++;
			else
				count1++;
		}
	}
	cout<<min(count1,count2);
	return 0;
}
