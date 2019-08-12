#include"iostream"
#include"string"
using namespace std;
typedef struct node{
	node *left,*right;
	char v;
}*biTree;
void initNode(biTree &T){
	T=new node;
	T->left=NULL;
	T->right=NULL;
}
int k;
void createTree(biTree &T,string s){
	k++;
	if(s[k]=='0'){
		T=NULL;
	}else{
		initNode(T);
		T->v=s[k];
		createTree(T->left,s);
		createTree(T->right,s);
	}
}
//计算最大宽度 
void traverse(biTree T,int k,int list[]){
	if(T){
		list[k]++;
		traverse(T->left,k+1,list);
		traverse(T->right,k+1,list);
	}
}
int main(){
	biTree T;
	int *list;
	string s;
	while(1){
		cin>>s;
		if(s=="0"){
			break;
		}
		k=-1;
		T=NULL;
		createTree(T,s);
		list=new int[k];
		for(int i=0;i<k;i++){
			list[i]=0;
		}
		traverse(T,1,list);
		int max=0;
		for(int i=0;i<k;i++){
			if(list[i]>max){
				max=list[i];
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
