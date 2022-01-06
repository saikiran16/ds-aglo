package TestingGraphAPI;

import GraphAPI.BreadthFirstPaths;
import GraphAPI.ConnectedComponents;
import GraphAPI.DepthFirstPaths;
import GraphAPI.Graph;

public class TestingConnectedComponents {
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
        ConnectedComponents cc = new ConnectedComponents(G);
        int ids[] = cc.getIDArray() ;
        for(int i = 0 ; i < ids.length ; i++){
            System.out.println(i + "-->" + ids[i]);
        }
        System.out.println("Component number of vertex 7 : "+cc.getId(7));
        System.out.println("Total Components : "+cc.getCount());

    }
}
