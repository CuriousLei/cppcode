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
void operate(linkNode L,int n){
	linkNode p=L->next,p0=L;
	while(1){
		for(int i=0;i<n-1;i++){
			p=p->next;
			p0=p0->next;
			if(p==L){
				p=p->next;
				p0=p0->next;
			}
		}
		p0->next=p->next;
		cout<<p->v;
		delete p;
		p=p0->next;
		if(p==L&&p0==L){
			cout<<endl;
			break;
		}else{
			cout<<" ";
		}
	}
}
int main(){
	int m,n,i;
	linkNode L,p,w;
	while(1){
		cin>>m>>n;
		if(m==0&&n==0){
			break;
		}
		initNode(L);
		L->v=0;
		w=L;
		for(i=0;i<m;i++){
			initNode(p);
			p->v=i+1;
			w->next=p;
			w=w->next;
			p->next=L;
		}
		operate(L,n);
	}
	return 0;
}
