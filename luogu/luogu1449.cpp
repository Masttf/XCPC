#include<bits/stdc++.h>
using namespace std;
stack<int>d;
int main(){
	string s;
	cin>>s;
	int len=s.length();
	int sum=0;
	for(int i=0;i<len-1;i++){
		if(s[i]=='.'){
			d.push(sum);
			sum=0;
		}
		int temp;
		int temp2;
		if(s[i]>='0'&&s[i]<='9'){
			
			sum=sum*10+s[i]-'0';
		}
		else if(s[i]=='+'){
			temp=d.top();
			d.pop();
			temp2=d.top();
			d.pop();
			d.push(temp+temp2);
		}else if(s[i]=='-'){
			temp=d.top();
			d.pop();
			temp2=d.top();
			d.pop();
			d.push(temp2-temp);
		}else if(s[i]=='*'){
			temp=d.top();
			d.pop();
			temp2=d.top();
			d.pop();
			d.push(temp2*temp);
		}else if(s[i]=='/'){
			temp=d.top();
			d.pop();
			temp2=d.top();
			d.pop();
			int sum=temp2/temp;
			d.push(sum);
		}
	}
	cout<<d.top();
	return 0;
}
