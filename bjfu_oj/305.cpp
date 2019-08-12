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
	if(s[k]!='0'){
		initNode(T);
		T->v=s[k];
		createTree(T->left,s);
		createTree(T->right,s);
	}
}
bool cmp(biTree T1,biTree T2){
	if(T1&&T2){
		if(T1->v!=T2->v){
			return false;
		}
		if(cmp(T1->left,T2->left)&&cmp(T1->right,T2->right)){
			return true;
		}else{
			return false;
		}
	}else if(T1 || T2){
		return false;
	}else{
		return true;
	}
}
int main(){
	biTree T1,T2;
	string s1,s2;
	while(cin>>s1){
		if(s1=="0"){
			break;
		}
		cin>>s2;
		k=-1;
		createTree(T1,s1);
		k=-1;
		createTree(T2,s2);
		if(cmp(T1,T2)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
