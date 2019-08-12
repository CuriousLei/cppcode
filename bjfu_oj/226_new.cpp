#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int v;
}*linkList;
void initNode(linkList &L){
	L=new node;
	L->next=NULL;
}
void createList(linkList &L,int n){
	linkList p,w=L;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->v;
		w->next=p;
		w=w->next;
	}
}
linkList merge(linkList L1,linkList L2){
	linkList L,p,q,m,p0,q0,m0;
	initNode(L);
	while(L1->next||L2->next){
		int max=10000;
		p=L1->next;
		q=L2->next;
		p0=L1;
		q0=L2;
		while(p){
			if(p->v<max){
				m=p;
				m0=p0;
				max=p->v;
			}
			p=p->next;
			p0=p0->next;
		}	
		while(q){
			if(q->v<max){
				m=q;
				m0=q0;
				max=q->v;
			}
			q=q->next;
			q0=q0->next;
		}
		m0->next=m->next;
		m->next=L->next;
		L->next=m;
	}
	return L;
}
void output(linkList L){
	linkList p=L->next;
	while(p){
		cout<<p->v;
		p=p->next;
		if(p){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
}
int main(){
	linkList L1,L2,L3;
	int n,m;
	initNode(L1);
	initNode(L2);
	while(1){
		cin>>n>>m;
		if(n==0&&m==0){
			break;
		}
		createList(L1,n);
		createList(L2,m);
		L3=merge(L1,L2);	
		output(L3);
	}
	
	return 0;
}
