package GraphAPI;

public class DirectedDFS {

    public boolean[] visited = null ;
    public DirectedDFS(DiGraph DG , int s){
        visited = new boolean[DG.vertices];
        dfs(DG ,s);
    }
    public void dfs(DiGraph DG , int v){
        visited[v] = true ;
        for(Integer w : DG.adjacents(v)){
            if(! visited[w])
            dfs(DG , w);
        }
    }
}
