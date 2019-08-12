#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int c;	
}*LNode;
void initNode(LNode &L){
	L=new node;
	L->next=NULL;
}
void reverse(LNode L){
	LNode p,e;

	e=L->next;
	while(e->next){
		p=e->next;
		e->next=p->next;
		p->next=L->next;
		L->next=p;	
	}
	p=L->next;
	while(p){
		cout<<p->c;
		p=p->next;
		if(p==NULL){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}
int main(){
	LNode L,p,e;
	int n;
	cin>>n;
	while(n!=0){
		initNode(L);
		e=L;
		for(int i=0;i<n;i++){
			initNode(p);
			cin>>p->c;
			e->next=p;
			e=p;
		}
		reverse(L);
		cin>>n;
	}
	
	
	return 0;
}
