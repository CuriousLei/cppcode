#include"iostream"
using namespace std;
typedef struct node{
	char c;
	node *next;	
}*LNode;
void initNode(LNode &L){
	L=new node;
	L->next=NULL;
}
void createList(LNode L,int n){
	LNode p;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->c;
		p->next=L->next;
		L->next=p; 
	}
}
void output(LNode L1,LNode L2){
	LNode n,m;
	n=L1;
	m=L2;
	while(n->next&&m->next){
		if(n->next->c!=m->next->c){
			cout<<n->c<<endl;
			break;
		}
		n=n->next;
		m=m->next;
	}	
}
int main(){
	LNode L1,L2;
	int n,m;
	while(1){
		cin>>n>>m;
		if(n==0&&m==0){
			break;
		}
		initNode(L1);
		initNode(L2);
		createList(L1,n);
		createList(L2,m);
		output(L1,L2);
	}
	return 0;
}
