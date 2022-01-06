package GraphAPI;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class CountNodesAtEachLevel {
    Graph G ;
    int vertices ;
    boolean visited[] ;
    public CountNodesAtEachLevel(Graph G ,int v){
        this.G = G ;
        this.vertices = v ;
        visited = new boolean[vertices];

    }
    public Iterable<Integer>countNodesAtLevelUsingBFS(){
        return bfs();
    }
    public Iterable<Integer>  bfs(){
        Queue<Integer> q = new LinkedList<Integer>();
        ArrayList<Integer> arr = new ArrayList<>();
        q.add(0);
        visited[0] = true;
        int  sizeOfQueue = 1   ;
        arr.add(sizeOfQueue);
        while (!q.isEmpty()){
            int current_node = q.poll() ;
            sizeOfQueue-- ;
            for(Integer w : G.adjacents(current_node)){
                if(!visited[w]){
                    visited[w] = true ;

                    q.add(w);
                }
            }
            if(sizeOfQueue == 0) {
                sizeOfQueue = q.size();
                if(!q.isEmpty())
                arr.add(sizeOfQueue);
            }
        }
        return arr ;
    }
}
