#inclde<stdio.h>


struct Graph{
	int nodes;
	int edges;
	int **adj;
};


struct Graph *adjMatrix(){
	int i,u,v;
	struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
	
	if(!G){
		printf("Memory error");	
		return NULL;
	}
	
	scanf("Number of Vertices: %d, Number of Edges :%d",&G->nodes,&G->edges);
	g->adj=malloc(sizeof(G->nodes * G->edges));
	
	for(u=0;u<G->nodes;u++)
		for(v=0;v<G->nodes;v++)
			G->adj[u][v]=0;
	for(i=0;i<G-edges;i++){
		scanf("Edges %d%d",%u,%v);
		G->adj[u][v]=1;
		g->adj[v][u]=1;

	}
	return G;
} 

int visited[G->nodes]; 

void DFS(struct Graph *G,int u){
	visited[u]=1;
	
	for(int v=0;v<G->nodes;v++){
		

	}



}



int main(){

	

	


return 0;
}


