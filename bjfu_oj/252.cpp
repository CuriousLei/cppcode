#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int value;	
}*LNode;
void initNode(LNode &L){
	L=new node;
	L->next=NULL;
}
void createList(LNode L,int n){
	LNode p,e;
	e=L;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->value;
		e->next=p;
		e=p;
	}
}
int count(LNode p){
	if(p==NULL){
		return 0;
	}
	return 1+count(p->next);
}
int main(){
	LNode L;
	int n;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initNode(L);
		createList(L,n);
		cout<<count(L->next)<<endl;
	}
	return 0;
}
