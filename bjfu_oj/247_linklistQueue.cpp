#include"iostream"
using namespace std;
#define maxSize 10
typedef struct node{
	node *next;
	int v;
}*QNode;
typedef struct{
	QNode rear;
	QNode front;
}queue;
void initNode(QNode &Q){
	Q=new node;
	Q->next=NULL;
}
//入队不需要判断是否满
void enqueue(queue &Q,int v){
	QNode p;
	initNode(p);
	p->v=v;
	Q.rear->next=p;
	Q.rear=p;
}
//出队需要判断是否为空
bool dlqueue(queue &Q,int &v){
	if(Q.rear!=Q.front){
		QNode p;
		v=Q.front->next->v;
		p=Q.front->next;
		Q.front->next=p->next;
		if(Q.rear==p){
			Q.rear=Q.front;
		}
		delete p;
		return true;
	}else{
		return false;
	}
} 
int main(){
	queue Q;
	int n,v;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initNode(Q.front);//链队列需要头结点 
		Q.rear=Q.front;
		for(int i=0;i<n;i++){
			cin>>v;
			enqueue(Q,v);
		}
		while(dlqueue(Q,v)){
			cout<<v;
			if(Q.front!=Q.rear){
				cout<<" ";
			}else{
				cout<<endl;
			}
		}
	}
	return 0;
}
