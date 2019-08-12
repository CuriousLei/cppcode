#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int value;
}*LNode;
void push(LNode &rear,int n){
	LNode p;
	for(int i=0;i<n;i++){
		p=new node;
		cin>>p->value;
		p->next=rear->next;
		rear->next=p;
		rear=p;	
	}
}
void pop(LNode &rear,int m){
	LNode p;
	while(m!=0){
		p=rear->next->next;
		rear->next->next=p->next;
		cout<<p->value<<" ";
		if(p==rear){
			rear=p->next;
		}
		delete p;
		m--;
	}
}
int main(){
	LNode rear;
	int n,m;
	while(1){
		cin>>n>>m;
		if(n==0&&m==0){
			break;
		}
		rear=new node;
		rear->next=rear;
		push(rear,n);
		pop(rear,m);
		if(rear==rear->next){
			cout<<"0"<<endl;
		}else{
			cout<<"1"<<endl;
		}
	}
	return 0;
}
