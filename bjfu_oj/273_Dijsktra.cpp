#include"iostream"
#include"stack"
using namespace std;
#define maxInt 32767
typedef struct{
	char vexs[100];
	int arcs[100][100];
	int vexnum,arcnum;
}AMGraph;
int locateVex(AMGraph G,char v){
	for(int i=0;i<G.vexnum;i++){
		if(G.vexs[i]==v){
			return i;
		}
	}
}
void createGraph(AMGraph &G,int n,int m){
	char v1,v2;
	int w,i,j;
	G.vexnum=n;
	G.arcnum=m;
	for(i=0;i<n;i++){
		cin>>G.vexs[i];
		for(j=0;j<n;j++){
			G.arcs[i][j]=maxInt;
		}
	}
	for(int k=0;k<m;k++){
		cin>>v1>>v2>>w;
		i=locateVex(G,v1);
		j=locateVex(G,v2);
		G.arcs[i][j]=w;
		G.arcs[j][i]=w;
	}	
}
void DIJ(AMGraph G,int v0,int vk){
	int n=G.vexnum;
	bool *S;
	int *D,*Path,v,w;
	S=new bool[n];//已求出的最短路径的终点集合 
	D=new int[n];//最短路径长度集合 
	Path=new int [n];//存储每个结点的前置 
	for(v=0;v<n;v++){
		S[v]=false;
		D[v]=G.arcs[v0][v];
		if(D[v]<maxInt){
			Path[v]=v0;
		}else{
			Path[v]=-1;
		}
	}
	for(int i=1;i<n;i++){
		int min =maxInt;
		for(w=0;w<n;w++){
			if(!S[w]&&D[w]<min){
				v=w;min=D[w];
			}
		}
		S[v]=true;
		for(w=0;w<n;w++){
			if(!S[w]&&(D[v]+G.arcs[v][w])<D[w]){
				D[w]=D[v]+G.arcs[v][w];
				Path[w]=v;
			}
		}
	}
	stack <char> stack;
	v=vk;stack.push(v);
	while(v!=v0){
		v=Path[v];
		stack.push(v);
	}
	cout<<D[vk]<<endl;
	while(!stack.empty()){
		cout<<G.vexs[stack.top()];
		stack.pop();
		if(stack.empty()){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
	
}
int main(){
	AMGraph G;
	char v0,vk;
	int n,m;
	while(1){
		cin>>n>>m;
		if(n==0&&m==0){
			break;
		}
		createGraph(G,n,m);
		cin>>v0>>vk;
		DIJ(G,locateVex(G,v0),locateVex(G,vk));
	}
	return 0;
}
