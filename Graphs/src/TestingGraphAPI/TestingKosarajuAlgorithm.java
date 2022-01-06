package TestingGraphAPI;

import GraphAPI.DiGraph;
import GraphAPI.KosarajuAlgorithm_For_StronglyConnectedComponents;


public class TestingKosarajuAlgorithm
{
    public static void main(String[] args) {
        DiGraph g = new DiGraph(7 ,8);
        /*G.addEdge(0,1);
        G.addEdge(1,2);
        G.addEdge(2,0);
        G.addEdge(2,3);
        G.addEdge(3,4);
        G.addEdge(4,5);
        G.addEdge(4,7);
        G.addEdge(5,6);
        G.addEdge(6,4);
        G.addEdge(6,7);*/

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(4, 1);
        g.addEdge(6, 4);
        g.addEdge(5, 6);
        g.addEdge(5, 2);
        g.addEdge(6, 0);

        KosarajuAlgorithm_For_StronglyConnectedComponents kosarajuAlgo =
                new KosarajuAlgorithm_For_StronglyConnectedComponents(g,g.vertices);




    }
}
