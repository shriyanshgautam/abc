#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MAX 1000

int numOfNodes;
int matrix[MAX][MAX];

struct queue{
	int top,front;
	int elements[MAX];
};

int insert(struct queue *q,int info){
	if(q->top<MAX){
	     if(q->top=-1){
		q->elements[++(q->top)];
		q->front=0;
		}else{
		  q->elements[++(q->top)];
		}
             
             return 1;
	}else{
		return -1;
	}

}

int front(struct queue *q){
	return q->elements[q->front];
}

int deleteFront(struct queue *q){
	if(q->top>=q->front){
		return q->elements[(q->front)++];
	}else{
		return -1;
	}
	if(q->top==q->front){
		q->top=-1;
		q->front=-1;
	}

}

int isempty(struct queue *q){

		if(q->front==q->top){
			return 1;
		}else{
			return 0;
		}	
}

void init(struct queue *q){
	q->top=-1;
	q->front=-1;
}

int checkAndConvert(char *str){
	  if(strcmp(str,"c")==0){
		return -1;
	}else if(atoi(str)>0){
		return atoi(str);
	   }else{
		return -2;
	   }
}


int bfs(int s,int numOfNodes,struct queue *q)
{
    int i;
    bool *visited = new bool[numOfNodes];
    for(i = 0; i < numOfNodes; i++)
        visited[i] = false;
 
    
    //list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    insert(q,s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    //list<int>::iterator i;
 
    while(isempty(q)!=1)
    {
        // Dequeue a vertex from queue and print it
        s = front(q);
        printf("%d ",s);
        deleteFront(q);
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it

	for(i=0;i<numOfNodes;i++){
		if(matrix[s][i]==1){
			if(!visited[i]){
				insert(q,matrix[s][i]);
			}
		}

	}
       /* for(i = matrix[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
	*/
    }
}



int main(){
	
   int i,j;
    struct queue q;
    init(&q);
    char s[100];
   
    
    while(1){
	printf("Enter number of nodes: ");
	 scanf("%s",s);
	 int result=checkAndConvert(s);
	printf("%d",result);
   	if(result>MAX){
		printf("Keep it in limit (10000)\n");
    	}else if(result<=0){
		printf("Not Valid!!\n");
        }else if(result>0){
		numOfNodes=result;
		break;
	}
    }


    //taking edges
    for(i=0;i<numOfNodes;i++){
        int flag=0;
	printf("Enter nodes connected to %d th node (c to terminate):",i+1);
	
		while(1){
			scanf("%s",s);
			int res=checkAndConvert(s);
                        printf("%d",res);
			if(res>numOfNodes){
				printf("node does not exists! Enter again:\n");
			}else if(res==-2){
				printf("invalid node! Enter again:\n");
			}else if(res>0){
				matrix[i][res-1]=1;	        
			}else if(res==-1){
				break;
				
			}
		}
	    
	
    }
	
	
	

	
	while(1){	printf("Enter the source");
			scanf("%s",s);
			int res=checkAndConvert(s);
                        printf("%d",res);
			if(res>numOfNodes){
				printf("node does not exists! Enter again:\n");
			}else if(res==-2){
				printf("invalid node! Enter again:\n");
			}else if(res>0){
				bfs(res,numOfNodes,&q);
				break;	        
			}
		}

    
    
     
   
    




return 0;

}
