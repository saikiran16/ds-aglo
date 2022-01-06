package GraphAPI;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BreadthFirstPaths {
    public Iterable<Integer> bfs(Graph G, int v){
        boolean visited[]  = new boolean[G.vertices];
        int edgeTo[] = new int[G.vertices];
        Queue<Integer> q = new LinkedList<>();
        ArrayList<Integer> paths = new ArrayList<>();
        q.add(v);
        visited[v] = true ;
        while (! q.isEmpty()){
            int currentExploringVertex = q.poll();
            paths.add(currentExploringVertex);
            for(Integer w : G.adjacents(currentExploringVertex)){
                if(! visited[w]){
                    visited[w] = true;
                    q.add(w);
                    edgeTo[w] = v ;

                }
            }

        }
        return paths ;

    }


}
