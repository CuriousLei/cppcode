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
		w=p;
	}
}
linkList merge(linkList A,linkList B){
	linkList L,w,p,p0,w0;
	initNode(L);
	while(A->next||B->next){
		int max=0;
		p=A->next;
		p0=A;
		while(p){
			if(p->v>max){
				max=p->v;
				w=p;
				w0=p0;
			}
			p=p->next;
			p0=p0->next;
		}
		p=B->next;
		p0=B;
		while(p){
			if(p->v>max){
				max=p->v;
				w=p;
				w0=p0;
			}
			p=p->next;
			p0=p0->next;
		}
		w0->next=w->next;
		w->next=L->next;
		L->next=w;
	}
	return L;
}
int main(){
	linkList A,B,C;
	int n;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initNode(A);
		initNode(B);
		createList(A,n);
		createList(B,n);
		C=merge(A,B);
		linkList p=C;
		
		while(n!=0){
			p=p->next;
			n--;
		}
		cout<<p->v<<endl;
	}
	return 0;
}
