/********************************
Anurag Rana
March 29, 2015
Adapted from - http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/

How to run -  $ gcc -std=c99 Prim2MST.c 

program to print MST and weight of second best MST
**********************************
*/


#include <stdio.h>
#include <limits.h>
#include <malloc.h>
 
// Number of vertices in the graph
//#define V 5
int V;
 
//  function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], int mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == 0 && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
// function to print the constructed MST stored in parent[]
int printMST(int parent[],  int **graph)
{
   //printf("Edge   Weight\n");
   for (int i = 1; i < V; i++){
   	  //ternary operator "?" to print smaller vertex index first 
      // i+1 and parent[i] + 1 : +1 is done because  vertx index should start from one and not from 0
      printf("%d %d %d\n", i<parent[i]?i+1:parent[i]+1, i<parent[i]?parent[i]+1:i+1, graph[i][parent[i]]); 
      
   }   
}
 
int printMST2(int parent[],  int graph[V][V])
{
   //printf("Edge   Weight\n");
   for (int i = 1; i < V; i++){
   	  //print smaller vertex index first
      // i+1 and parent[i] + 1 : +1 is done because  vertx index should start from one and not from 0
      printf("%d %d %d\n", i<parent[i]?i+1:parent[i]+1, i<parent[i]?parent[i]+1:i+1, graph[i][parent[i]]); 
      
   }   
} 
 
void printSecondMSTWeight(int parent1[],int **graph)
{

/*
Something like (pseudocode):

Build first MST
L = list of edges in the first mst, sorted by weight
second_best_cost = INF
for (i=0; i<L.size; i++) {
   try to build a mst without using edge L[i]
   if it's possible and its cost is < second_best_cost {
       second_mst = the new found mst
       second_best_cost = its cost
  }
}

*/
	
   
    int g[V][V]; //local copy of graph
	long secondCost = LONG_MAX;
	
	//build MST one by one by eliminating edges and calculate the weight sum
    //print minimum of such sum
    
	for (int i = 1; i < V; i++){
		//print smaller vertex index first
	    // i+1 and parent[i] + 1 : +1 is done because  vertx index should start from one and not from 0
    	//printf("%d %d %d\n", i<parent[i]?i+1:parent[i]+1, i<parent[i]?parent[i]+1:i+1, graph[i][parent[i]]); 
    	for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				g[i][j]=graph[i][j];
			}
		}
		//printf("\n removing edge %d %d",g[i][parent1[i]],g[parent1[i]][i]);
      	g[i][parent1[i]] = 0;
        g[parent1[i]][i] = 0;
		      
      	
      	
      	//building another mst **********************
      	
      	int parent[V]; // Array to store constructed MST
     	int key[V];   // Key values used to pick minimum weight edge in cut
    	int mstSet[V];  // To represent set of vertices not yet included in MST
 
    	 // Initialize all keys as INFINITE
     	for (int i = 0; i < V; i++)
       		key[i] = INT_MAX, mstSet[i] = 0,parent[i]=-1;
 
    	 // Always include first 1st vertex in MST.
     	key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     	parent[0] = -1; // First node is always root of MST 
 
    	 // The MST will have V vertices
    	 for (int count = 0; count < V-1; count++){
        	// Pick thd minimum key vertex from the set of vertices
        	// not yet included in MST
        	int u = minKey(key, mstSet);
 
        	// Add the picked vertex to the MST Set
        	mstSet[u] = 1;
 
        	// Update key value and parent index of the adjacent vertices of
        	// the picked vertex. Consider only those vertices which are not yet
        	// included in MST
        	for (int v = 0; v < V; v++)
		 		// graph[u][v] is non zero only for adjacent vertices of m
           		// mstSet[v] is false for vertices not yet included in MST
           		// Update the key only if graph[u][v] is smaller than key[v]
          		if (g[u][v] && mstSet[v] == 0 && g[u][v] <  key[v])
             		parent[v]  = u, key[v] = g[u][v];
     	   }
     	
     	int mstPossible = 1; // 0 means not possible
     	//if parent of any node is still -1 that means MST not possible without this edge, disconnected componenet.
     	for(int v=1;v<V;v++){
     		if(parent[v]==-1){
     			mstPossible = 0;
     			break;
     		}
     	}
     	
     	if(mstPossible==0) continue;
     	
     	//printMST2(parent,  g);
     	
     	//find edge sum of newly built MST
     	long sumEdge = 0 ;
     	for (int i = 1; i < V; i++)
          	sumEdge = sumEdge + (long)g[i][parent[i]]; 

        //printf("\n sum of this mst is %ld",sumEdge);
          	
        if(sumEdge < secondCost)
        	secondCost = sumEdge;
          	
        
      
   }  

	if(secondCost == LONG_MAX) //no 2nd mst possible at all.
		printf("-1");
	else
		printf("%ld",secondCost);
      	
      	
}




 
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int **graph)
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     int mstSet[V];  // To represent set of vertices not yet included in MST
 
     // Initialize all keys as INFINITE
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
     parent[0] = -1; // First node is always root of MST 
 
     // The MST will have V vertices
     for (int count = 0; count < V-1; count++)
     {
        // Pick thd minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = 1;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++)
 
           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     // print the constructed MST
     //printMST(parent,  graph);
     
     printSecondMSTWeight(parent, graph);
}
 
 
// driver program to test above function
int main()
{ 	
 	int iterations,countVertices,countEdges;
 	scanf("%d",&iterations);
 	
 	for(int i=0;i<iterations;i++){
 	
 		scanf("%d %d",&countVertices,&countEdges);
 		V= countVertices;
 		int *arr[countEdges];
    	for (int i=0; i<countEdges; i++)
         	arr[i] = (int *)malloc(countEdges * sizeof(int));
 	
 		//creating 2d adjacency matrix
 		for (int i = 0; i <  countEdges; i++)
     	 for (int j = 0; j < countEdges; j++)
        	arr[i][j] = 0;
 	
 		for(int i=0;i<countEdges;i++){
 			int a,b,c;
 			scanf("%d %d %d",&a,&b,&c);
 			//since question demands that vertice numbering should start from 1
 			//hence input is given accordingly and array created from index 0 hence a-1 and b-1
 			
 			arr[a-1][b-1] = c;
 			arr[b-1][a-1] = c;
 		}
 	
    	// Print the solution
    	primMST(arr);
 	}
    return 0;
}



/*
Bonus: Second MST

Use your previous code to compute the MST (let's call it T). 
Use T to efficiently compute the second MST S (the minimum cost spanning tree that is not T). 

Hint: T and S should differ in one edge only, you need to find that edge efficiently. 

Input:
First Line of the input will contain T representing the number of test cases.
First line of each test case will contain two space separated integers V and E representing Number of Vertices and Number of Edges respectively.
Next E lines will contain 3 space separate integers A, B, W which represents an edge between vertex A and B of weight W.
Vertices will be labeled starting from 1. For example if V=5, the set of vertices is {1,2,3,4,5}

Output
Print a single integer in a new line; the total weight of the second minimum weight spanning tree.
If there does not exist a second MST, output -1.

Constraints:
1 ≤ T ≤ 100
2 ≤ V ≤ 1000
1 ≤ E ≤ ((V*(V-1))/2)
1 ≤ A, B ≤ V
1 ≤ W ≤ 10^6
It is guaranteed that the graph will be connected and all edge weights would be distinct. 

Sample Input
2
4 5 
1 2 10
1 3 6
3 4 4
2 4 15
1 4 5
5 7
1 2 24
2 3 9
3 4 8
4 5 28
1 5 10
1 4 25
2 5 30

Sample Output
20
52

*/
