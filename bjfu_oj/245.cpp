#include"iostream"
#include"string"
using namespace std;
typedef struct{
	char *base;
	char *top;
	int len;	
}sqStack;
void initStack(sqStack &stack,int n){
	stack.base=new char[n];
	stack.top=stack.base;
	stack.len=n;
}
void push(sqStack &stack,char c){
	*(stack.top)=c;
	stack.top++;
}
bool pop(sqStack &stack){
	
	if(stack.top==stack.base){
		return false;
	}else{
		stack.top--;
		return true;
	}
}
bool empty(sqStack stack){
	if(stack.base==stack.top){
		return true;
	}else{
		return false;
	}
}
int main(){
	sqStack stack;
	string str;
	while(1){
		cin>>str;
		if(str=="0"){
			break;
		}
		initStack(stack,str.length());
		int i;
		for(i=0;i<str.length();i++){
			if(str[i]=='I'){
				push(stack,str[i]);
			}else{
				if(!pop(stack)){
					break;
				}
			}
		}
		if(i==str.length()&&empty(stack)){
			cout<<"TRUE"<<endl;
		}else{
			cout<<"FALSE"<<endl;
		}
	}
	return 0;
}
