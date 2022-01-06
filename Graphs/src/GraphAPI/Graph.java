package  GraphAPI;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Graph {
    public int vertices , edges ;
    ArrayList<Integer> adj[] ;
    public Graph(int v, int e){
        this.vertices=v;
        this.edges=e;
        adj = new ArrayList[vertices];
        for(int i = 0 ;i <this.vertices ; i++){
            adj[i] = new ArrayList<>();
        }
    }
    public void addEdge(int from, int to){
        adj[from].add(to) ;
        adj[to].add(from);
    }
    public Iterable<Integer> adjacents(int v){
        return adj[v] ;
    }
    public int getDegree(int v){
        return adj[v].size();
    }
 /*  void bfs(Graph G , int v){
        boolean visited[]  = new boolean[this.vertices];
        int edgeTo[] = new int[this.vertices];
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        visited[v] = true ;
        while (! q.isEmpty()){
            int currentExploringVertex = q.poll();
            for(Integer w : adjacents(currentExploringVertex)){
                if(! visited[w]){
                    visited[w] = true;
                    q.add(w);
                    edgeTo[w] = v ;

                }
            }

        }

    }*/
    public static void main(String[] args) {
        Graph G = new Graph(5 , 5) ;
        G.addEdge(0,2);
        G.addEdge(1,3);
        G.addEdge(1,4);
        G.addEdge(0,4);
        System.out.println(G.adjacents(0));
    }
}

