#include"iostream"
#include"queue"
using namespace std;
typedef struct{
	int *base;
	int *top;
	int stackSize;
}SqStack;
void initStack(SqStack &stack,int n){
	stack.base=new int[n];
	stack.stackSize=n;
	stack.top=stack.base;
}
void push(SqStack &stack,int item){
	*stack.top=item;
	stack.top++;
}
void pop(SqStack &stack){
	stack.top--;
}
int getTop(SqStack &stack){
	return *(stack.top-1);
}
int main(){
	SqStack stack;
	int n,item;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initStack(stack,n);
		queue <int> que;
		for(int i=0;i<n;i++){
			cin>>item;
			que.push(item);	
		}
		while(!que.empty()){
			item=que.front();
			que.pop();
			if(item==-1){
				if(stack.top==stack.base){
					cout<<"POP ERROR"<<endl;
					break;
				}else{
					cout<<getTop(stack)<<endl;
				    pop(stack);	
				}
			}else{
				push(stack,item);
			}
		}
	}
	return 0;
}
