#include"iostream"
using namespace std;
#define maxSize 100
typedef struct{
	int *list;
	int rear;
	int front;
}queue;
void initQueue(queue &Q){
	Q.list=new int[maxSize];
	Q.rear=0;
	Q.front=0;
}
void pushFront(queue &Q,int m){
	if((Q.front-1+maxSize)%maxSize!=Q.rear){
		Q.list[Q.front]=m;
		Q.front=(Q.front-1+maxSize)%maxSize;	
	}
}
int popRear(queue &Q){
	int m=Q.list[Q.rear];
	Q.rear=(Q.rear-1+maxSize)%maxSize;
	return m;
}
bool empty(queue Q){
	if(Q.rear==Q.front){
		return true;
	}
	return 0;
}
int main(){
	queue Q;
	int n,m;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initQueue(Q);
		for(int i=0;i<n;i++){
			cin>>m;
			pushFront(Q,m);
		}
		while(!empty(Q)){
			cout<<popRear(Q);
			if(Q.rear==Q.front){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}
	return 0;
}
