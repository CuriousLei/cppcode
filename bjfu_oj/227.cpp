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
void createList(int m,int n,LNode L1,LNode L2){
	LNode p,e;
	e=L1;
	for(int i=0;i<m;i++){
		initNode(p);
		cin>>p->c;
		e->next=p;
		e=p;
	}
	e=L2;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->c;
		e->next=p;
		e=p;
	}
}
void getRe(LNode L1,LNode L2){
	LNode p,p0,q;
	p=L1->next;
	p0=L1;
	while(p){
		q=L2->next;
		while(q){
			if(q->c==p->c){
				break;
			}
			q=q->next;
		}
		if(q==NULL){
			p0->next=p->next;
			delete p;
			p=p0->next;
			continue;
		}
		p=p->next;
		p0=p0->next;
	}
	p=L1->next;
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
	LNode L1,L2;
	int n,m;
	initNode(L1);
	initNode(L2);
	cin>>m>>n;
	while(n!=0||m!=0){
		createList(m,n,L1,L2);
		getRe(L1,L2);
		cin>>m>>n;	
	}
	return 0;
}
