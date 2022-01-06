package GraphAPI;
import java.lang.StringBuffer;
import java.util.ArrayList;
import java.util.Stack;
/*
* Step 1 : Apply DFS . Meanwhile push the nodes to stack that completed their recursion calls .
* Step 2 : Create new Reversed Graph
* Step 3 : Apply DFS for all elements in stack
*
* */
public class KosarajuAlgorithm_For_StronglyConnectedComponents {
    Graph DG  , reversedDiGraph ;
    ArrayList<ArrayList<Integer>> stronglyConnectedComponents  ;
    int vertices , k = 0 ;
    public boolean visited[] ;
    Stack<Integer> st ;
    public KosarajuAlgorithm_For_StronglyConnectedComponents(Graph DG, int v){
        this.DG = DG ;
        this.vertices = v ;
        visited = new boolean[this.vertices];
        stronglyConnectedComponents = new ArrayList<ArrayList<Integer>>();
        st = new Stack<>() ;
        // Perform DFS and Push each node when they return
        for(int i = 0 ; i < vertices ; i++){
            if(!visited[i]) dfs(DG , i );
        }
        //System.out.println(st);

        // Reverse the DiGraph
        reverseTheGraph();
        visited = new boolean[DG.vertices] ;

        // Do DFS for Reversed Graph by taking each element in Stack

        while (!st.isEmpty()){
            Integer current_node = st.pop();
            if(!visited[current_node]) {
                stronglyConnectedComponents.add(new ArrayList<>());
                DFS_Again(current_node, k++);
            }

        }
        System.out.println(stronglyConnectedComponents);

    }
    public void dfs(Graph DG , int s){
        visited[s] = true ;
        for(Integer w : DG.adjacents(s)){
            if(!visited[w])
                dfs(DG , w);

        }
        st.push(s);
    }
    public void reverseTheGraph(){
        reversedDiGraph = new DiGraph(vertices , DG.edges);
        for(int from = 0 ; from < vertices ; from++){
            for(Integer to: DG.adjacents(from)){
                reversedDiGraph.addEdge(to , from);
            }
        }
    }

    public  void DFS_Again(int s , int k ){
        visited[s] = true ;
        stronglyConnectedComponents.get(k).add(s);
        for(Integer w : reversedDiGraph.adjacents(s)){
            if(! visited[w])
            DFS_Again(w , k);
        }

    }


}
