package TestingGraphAPI;

import GraphAPI.CountNodesAtEachLevel;
import GraphAPI.Graph;

public class Testing_CountNodesAtEachLevel {
    public static void main(String[] args) {
        Graph G = new Graph(6,5);
        G.addEdge(0, 1);
        G.addEdge(0, 2);
        G.addEdge(1, 3);
        G.addEdge(2, 4);
        G.addEdge(2, 5);
        CountNodesAtEachLevel obj = new CountNodesAtEachLevel(G , G.vertices);
        System.out.println(obj.countNodesAtLevelUsingBFS());
    }
}
