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
int maxValue(LNode p,LNode e){
	if(p==NULL){
		return e->value;
	}
	if(p->value>e->value){
		e=p;
	}
	maxValue(p->next,e);
}
int main(){
	int n;
	LNode L;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initNode(L);
		createList(L,n);
		cout<<maxValue(L->next,L->next)<<endl;
	}
	return 0;
}
