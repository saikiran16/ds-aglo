package GraphAPI;

import java.util.ArrayList;
import java.util.Collection;

public class K_Cores_UNDirected {
    Graph G;
    int vertices;
    boolean[] visited;
    int degrees[];
    int min_degree = Integer.MAX_VALUE;
    int min_degree_vertex;
    public K_Cores_UNDirected(Graph G, int v) {
        this.G = G;
        this.vertices = v;
        visited = new boolean[vertices];
        degrees = new int[vertices];
        for (int i = 0; i < vertices; i++) {
            degrees[i] = G.getDegree(i);
            if (min_degree > degrees[i]) {
                min_degree = degrees[i];
                min_degree_vertex = i;
            }
        }

    }
    public void printKCores(int k){
        for(int i = 0 ; i < vertices ; i++){
            if(!visited[i]){
                dfs(i,k);
            }
        }
        for(int i = 0 ; i < vertices ; i++){
            if(degrees[i] >= k) {System.out.print(i + " ");
                System.out.println(G.adjacents(i));}
        }
    }
    public void dfs(int v , int k){
        visited[v] = true ;
        for(Integer w : G.adjacents(v)){
            if(degrees[v] < k) degrees[w]-- ;
            if(!visited[w]) dfs(w , k);
        }
    }
}
