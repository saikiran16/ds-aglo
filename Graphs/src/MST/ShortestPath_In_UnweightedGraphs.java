package MST;

import GraphAPI.Graph;

import java.util.LinkedList;
import java.util.Queue;

public class ShortestPath_In_UnweightedGraphs {
    Graph G ;
    int vertices ;
    public ShortestPath_In_UnweightedGraphs(Graph G, int vertices){
        this.G = G ;
        this.vertices = vertices;
    }
    public void bfs(Graph G , int v){
        boolean visited[]  = new boolean[this.vertices];
        int edgeTo[] = new int[this.vertices];
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        visited[v] = true ;
        while (! q.isEmpty()){
            int currentExploringVertex = q.poll();
            for(Integer w : G.adjacents(currentExploringVertex)){
                if(! visited[w]){
                    visited[w] = true;
                    q.add(w);
                    edgeTo[w] = v ;

                }
            }

        }
        for(int i : edgeTo){
            System.out.println(i);
        }
    }

}
