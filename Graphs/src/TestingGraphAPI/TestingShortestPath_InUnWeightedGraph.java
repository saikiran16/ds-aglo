package TestingGraphAPI;

import GraphAPI.Graph;
import MST.ShortestPath_In_UnweightedGraphs;

public class TestingShortestPath_InUnWeightedGraph {

    public static void main(String[] args) {
        Graph G  = new Graph(5,5);
        G.addEdge(1-1,2-1);
        G.addEdge(1-1,3-1);
        G.addEdge(2-1,4-1);
        G.addEdge(1-1,4-1);
        G.addEdge(2-1,5-1);
        ShortestPath_In_UnweightedGraphs obj = new ShortestPath_In_UnweightedGraphs(G , G.vertices);
        obj.bfs(G ,0);
    }
}
