package TestingGraphAPI;

import GraphAPI.Graph;
import GraphAPI.K_Cores_UNDirected;

public class TestingK_Cores_UnDirected {
    public static void main(String[] args) {
        Graph G = new Graph(9 , 17);
        int k = 3;
        G.addEdge(0, 1);
        G.addEdge(0, 2);
        G.addEdge(1, 2);
        G.addEdge(1, 5);
        G.addEdge(2, 3);
        G.addEdge(2, 4);
        G.addEdge(2, 5);
        G.addEdge(2, 6);
        G.addEdge(3, 4);
        G.addEdge(3, 6);
        G.addEdge(3, 7);
        G.addEdge(4, 6);
        G.addEdge(4, 7);
        G.addEdge(5, 6);
        G.addEdge(5, 8);
        G.addEdge(6, 7);
        G.addEdge(6, 8);
        K_Cores_UNDirected find_K_Cores = new K_Cores_UNDirected(G , G.vertices);
        find_K_Cores.printKCores(k);
    }
}
