package GraphAPI;

public class DiGraph extends Graph{
    public DiGraph(int v, int e) {
        super(v, e);
    }

    @Override
    public void addEdge(int from, int to) {
        adj[from].add(to) ;
    }

}
