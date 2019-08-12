#include"iostream"
using namespace std;
typedef struct node{
	node *next,*pre;
	int v;
}*linkList;
void initNode(linkList &L){
	L=new node;
	L->next=NULL;
	L->pre=NULL;
}
void createList(linkList &L,int n){
	linkList p,w=L;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->v;
		w->next=p;
		p->pre=w;
		w=p;
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
void sort(linkList L){
	linkList temp,q,e,head=L,end=NULL;
	while(head!=end&&head->next!=end){
		
		for(q=head->next,e=q->next;e!=end;q=q->next,e=e->next){
			if(q->v>e->v){
				q->pre->next=e;
				q->next=e->next;
				if(e->next){
					e->next->pre=q;	
				}
				e->pre=q->pre;
				q->pre=e;
				e->next=q;
				temp=e;
				e=q;
				q=temp;
			}
		}
		end=q;
		for(q=end,e=q->pre;e!=head;q=q->pre,e=e->pre){
			if(q->v<e->v){
				q->next->pre=e;
				q->pre=e->pre;
				e->pre->next=q;
				e->next=q->next;
				e->pre=q;
				q->next=e;
				temp=e;
				e=q;
				q=temp;
			}
		}
		head=q;
	}
}

int main(){
	linkList L;
	int n;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		initNode(L);
		createList(L,n);
		sort(L);
		output(L);
	}
	return 0;
}
