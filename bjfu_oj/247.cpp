#include"iostream"
using namespace std;
#define maxSize 100
typedef struct{
	int *list;
	int rear;
	int front;
	int tag;//以tag== 0和tag == 1来区别在队头指针(front)和队尾指针(rear)相等时，队列状态为“空”还是“满”
}queue;
void initQueue(queue &Q){
	Q.list=new int(maxSize);
	Q.rear=0;
	Q.front=0;
	Q.tag=0;
}
void push(queue &Q,int m){
	Q.list[Q.rear]=m;
	Q.rear=(Q.rear+1)%maxSize;
	Q.tag=1;
}
int pop(queue &Q){
	int m;
	m=Q.list[Q.front];
	Q.front=(Q.front+1)%maxSize;
	Q.tag=0;
	return m;
}
bool empty(queue Q){
	if(Q.rear==Q.front&&Q.tag==0){
		return true;
	}
	return false;
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
			push(Q,m);
		}
		while(!empty(Q)){
			cout<<pop(Q);
			if(Q.rear>Q.front){
				cout<<" ";
			}else{
				cout<<endl;
			}
		}
	}
	return 0;
}
