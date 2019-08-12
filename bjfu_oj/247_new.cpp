#include"iostream"
using namespace std;

typedef struct{
	int *base;
	int front;
	int rear;
	int tag;
}sqQueue;
int n;
void enqueue(sqQueue &Q,int v){
	if((Q.rear+1)%n!=Q.front||Q.tag==0){//注意入队判断是否为空这样写 
		Q.base[Q.rear]=v;
		Q.rear=(Q.rear+1)%n;
		if(Q.rear==Q.front){
			Q.tag=1;
		}
	}
}
void dlqueue(sqQueue &Q,int &v){
	if(Q.rear!=Q.front||Q.tag==1){
		v=Q.base[Q.front];
		Q.front=(Q.front+1)%n;
		if(Q.rear==Q.front){
			Q.tag=0;
		}
	}
}
int main(){
	sqQueue Q;
	int v;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		Q.base=new int[n];
		Q.rear=0;
		Q.front=0;
		Q.tag=0;
		for(int i=0;i<n;i++){
			cin>>v;
			enqueue(Q,v);
		}
		for(int i=0;i<n;i++){
			dlqueue(Q,v);
			cout<<v;
			if(i==n-1){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}
	return 0;
}
