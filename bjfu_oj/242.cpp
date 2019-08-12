#include"iostream"
#include"string"
#include"stack"
using namespace std;
int main(){
	string s;
	stack <char> stack;
	int i,n;
	while(1){
		cin>>s;
		if(s=="0"){
			break;
		}
		n=s.length();
		for(i=0;i<n/2;i++){
			stack.push(s[i]);
		}
		if(n%2!=0){
			i++;
		}
		for(;i<n;i++){
			if(s[i]!=stack.top()){
				break;
			}
			stack.pop();
		}
		if(i==n){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
