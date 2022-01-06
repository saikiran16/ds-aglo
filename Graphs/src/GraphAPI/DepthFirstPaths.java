package GraphAPI;

import java.util.ArrayList;
import java.util.Stack;

public class DepthFirstPaths {
    Graph G ;
    private boolean visited[]  ;
    private int edgeTo[];
    private  int s ;
    public DepthFirstPaths(Graph G , int s){
        this.G = G ;
        this.s = s ;
        visited = new boolean[G.vertices];
        edgeTo = new int[G.vertices];
        dfs(G , s);
    }
    public void dfs(Graph G , int v)
    {
        visited[v] = true ;
        for(int w : G.adjacents(v)){
            if(!visited[w]){
                dfs(G , w);
                edgeTo[w] = v ;
            }
        }

    }
    public boolean hasPathTo(int v){
        boolean result = false;
        result = visited[v];
        return  result ;
    }
    public Iterable<Integer> pathTo(int v){
        if(!hasPathTo(v)) return  null ;
        Stack<Integer> path = new Stack<>();

        for(int x = v ; x != s ; x = edgeTo[x]){
            path.push(x);
        }
        return path;
    }

    public void displayEdgeToArray(){
        for(int i = 0 ; i < G.vertices ; i++){
            System.out.println(i + " --> " + edgeTo[i]);
        }
    }
}
