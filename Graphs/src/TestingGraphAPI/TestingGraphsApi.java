package TestingGraphAPI;
import GraphAPI.*;

public class TestingGraphsApi {
    public static void main(String[] args) {
        Graph G = new Graph(13 , 13) ;
        G.addEdge(0,5);
        G.addEdge(4,3);
        G.addEdge(0,1);
        G.addEdge(9,12);
        G.addEdge(6,4);
        G.addEdge(5,4);
        G.addEdge(0,2);
        G.addEdge(11,12);
        G.addEdge(9,10);
        G.addEdge(0,6);
        G.addEdge(7,8);
        G.addEdge(9,11);
        G.addEdge(5,3);
        BreadthFirstPaths BFSUtil = new BreadthFirstPaths();
        DepthFirstPaths DFSUtil = new DepthFirstPaths(G,0);
        System.out.println(BFSUtil.bfs(G,0));
        DFSUtil.displayEdgeToArray();
        System.out.println(DFSUtil.pathTo(4));
    }
}
