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
linkList cutBack(linkList A,linkList B){
	linkList L,end,p,p0,q;
	initNode(L);
	end=L;
	p=A->next;
	p0=A;
	while(p){
		q=B->next;
		while(q){
			if(q->v==p->v){
				break;
			}
			q=q->next;
		}
		if(!q){
			p0->next=p->next;
			end->next=p;
			p->next=NULL;
			p=p0->next;
			end=end->next;
		}else{
			p=p->next;
			p0=p0->next;
		}
	}
	return L;
}
void output(linkList C){
	linkList p=C->next;
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
	linkList A,B,C;
	int n,m;
	initNode(A);
	initNode(B);
	while(1){
		cin>>n>>m;
		if(n==0&&m==0){
        	break;
        }
		createList(A,n);
		createList(B,m);
		C=cutBack(A,B);
		output(C);
		linkList p=C->next;
		int k=0;
		while(p){
			k++;
			p=p->next;
		}
		cout<<k<<endl;
	}
	return 0;
}
