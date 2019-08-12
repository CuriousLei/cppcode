#include"iostream"
#include"string"
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
	LNode p,w;
	w=L1;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->c;
		w->next=p;
		w=p;
	}
	w=L2;
	for(int i=0;i<m;i++){
		initNode(p);
		cin>>p->c;
		w->next=p;
		w=p;
	}
}
void merge(LNode L1,LNode L2){
	LNode m,m0,n,n0,p,p0,L3;
	initNode(L3);
	m=L1->next;
	m0=L1;
	n=L2->next;
	n0=L2;
	while(m){
		p=L3->next;
		p0=L3;
		while(p){
			if(p->c>m->c){
				m0->next=m->next;
				p0->next=m;
				m->next=p;
				m=m0->next;
				break;
			}else if(p->c==m->c){
				m0->next=m->next;
				delete m;
				m=m0->next;
				break;
			}
			p=p->next;
			p0=p0->next;
		}
		if(p==NULL){
			m0->next=m->next;
			p0->next=m;
			m->next=NULL;
			m=m0->next;
		}
	}
	while(n){
		p=L3->next;
		p0=L3;
		while(p){
			if(p->c>n->c){
				n0->next=n->next;
				p0->next=n;
				n->next=p;
				n=n0->next;
				break;
			}else if(p->c==n->c){
				n0->next=n->next;
				delete n;
				n=n0->next;
				break;
			}
			p=p->next;
			p0=p0->next;
		}
		if(p==NULL){
			n0->next=n->next;
			p0->next=n;
			n->next=NULL;
			n=n0->next;
		}
	}
	p=L3->next;
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
int main(){
	LNode L1,L2;
	int n,m;
	initNode(L1);
	initNode(L2);
	cin>>n>>m;
	while(n!=0 || m!=0){
		createList(m,n,L1,L2);
		merge(L1,L2);
		cin>>n>>m;
	}
	return 0;
}
