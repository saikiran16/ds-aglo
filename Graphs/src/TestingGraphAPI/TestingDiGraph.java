package TestingGraphAPI;

import GraphAPI.DiGraph;
import GraphAPI.Graph;

public class TestingDiGraph {
    public static void main(String[] args) {
        DiGraph DG = new DiGraph(13 , 22) ;
        DG.addEdge(4,2);
        DG.addEdge(2,3);
        DG.addEdge(3,2);
        DG.addEdge(6,0);
        DG.addEdge(0,1);
        DG.addEdge(2,0);
        DG.addEdge(11,12);
        DG.addEdge(12,9);
        DG.addEdge(9,10);
        DG.addEdge(9,11);
        DG.addEdge(7,9);
        DG.addEdge(10,12);
        DG.addEdge(11,4);
        DG.addEdge(4,3);
        DG.addEdge(3,5);
        DG.addEdge(6,8);
        DG.addEdge(8,6);
        DG.addEdge(0,5);
        System.out.println(DG.adjacents(0));
    }
}
