package GraphAPI;

public class ConnectedComponents {
    Graph G ;
    private  boolean visited[] ;
    private  int id[] ;
    int count  ;
    public ConnectedComponents(Graph G){
        this.G = G ;
        id = new int[G.vertices];
        visited = new boolean[G.vertices];
        for(int i = 0 ; i < G.vertices ; i++){
            if(!visited[i]){
               dfs(G , i);
               count++;
            }
        }
    }
    void dfs(Graph G , int v){
        visited[v]=true;
        id[v] = count ;
        for(Integer w : G.adjacents(v)){
            if(!visited[w]){
                dfs(G , w);
            }
        }
    }
    public int getCount(){
        return count;
    }
    public int getId(int v){
        return id[v];
    }
    public int[] getIDArray(){
        return id ;
    }
}
