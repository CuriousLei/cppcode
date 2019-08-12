#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int v;
}*linkNode;
void initNode(linkNode &L){
	L=new node;
	L->next=NULL;
}
void selectSort(linkNode L){
	linkNode p,min,w,m0;
	w=L;
	while(w->next){
		min=w->next;
		m0=w;
		p=w->next;
		while(p->next){
			if(min->v>p->next->v){
				min=p->next;
				m0=p;
			}
			p=p->next;
		}
		m0->next=min->next;
		min->next=w->next;
		w->next=min;
		w=w->next;
	}
	
}
void output(linkNode L){
	linkNode p;
	p=L->next;
	while(p){
		cout<<p->v;
		p=p->next;
		if(p==NULL){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}
int main(){
	linkNode L,p,e;
	int n;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initNode(L);
		e=L;
		for(int i=0;i<n;i++){
			initNode(p);
			cin>>p->v;
			e->next=p;
			e=p;
		}
		selectSort(L);
		output(L);
	}
	return 0;
}
