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
void createList(int n,int m,LNode L1,LNode L2){
	LNode p,e;
	e=L1;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->c;
		e->next=p;
		e=p;
	}
	e=L2;
	for(int i=0;i<m;i++){
		initNode(p);
		cin>>p->c;
		e->next=p;
		e=p;
	}
	
}
void getList(LNode L){
	LNode p;
	p=L->next;
	while(p){
		cout<<p->c;
		p=p->next;
		if(p){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
}
LNode merge(LNode L1,LNode L2){
	LNode L3,n,m,p,p0;
	initNode(L3);
	n=L1->next;
	m=L2->next;
	while(n){
		p0=L3;
		p=p0->next;
		while(p){
			if(n->c>=p->c){
				L1->next=n->next;
				p0->next=n;
				n->next=p;
				n=L1->next;
				break;
			}
			p=p->next;
			p0=p0->next;
		}
		if(p==NULL){
			p0->next=n;
			L1->next=n->next;
			n->next=NULL;
			n=L1->next;
		}
	}
	while(m){
		p0=L3;
		p=p0->next;
		while(p){
			if(m->c>=p->c){
				L2->next=m->next;
				p0->next=m;
				m->next=p;
				m=L2->next;
				break;
			}
			p=p->next;
			p0=p0->next;
		}
		if(p==NULL){
			p0->next=m;
			L2->next=m->next;
			m->next=NULL;
			m=L2->next;
		}
	}
	return L3;
}

int main(){
	LNode L1,L2,L3;
	int n,m;
	initNode(L1);
	initNode(L2);
	cin>>n>>m;
	while(n!=0||m!=0){
		createList(n,m,L1,L2);
		L3=merge(L1,L2);
		getList(L3);
		cin>>n>>m;
	}
	return 0;
}
