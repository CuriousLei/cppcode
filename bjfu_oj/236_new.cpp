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
void operate(linkList L){
	linkList p=L->next,q,q0;
	while(p){
		q=p->next;
		q0=p;
		while(q){
			if(q->v==p->v||q->v==-p->v){
				q0->next=q->next;
				delete q;
				q=q0->next;
			}else{
				q=q->next;
				q0=q0->next;
			}
		}
		p=p->next;
	}
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
	linkList L,p,w;
	int n;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initNode(L);
		w=L;
		for(int i=0;i<n;i++){
			initNode(p);
			cin>>p->v;
			w->next=p;
			w=p;
		}
		
		operate(L);
		output(L);
	}
	return 0;
}
