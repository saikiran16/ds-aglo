package GraphAPI;

public class Floyd_Warshell_Algorithm {
    // It need a adjanceny matrix
    int adjDistances[][] ;
    int vertices ;
    public Floyd_Warshell_Algorithm(int a[][], int v){
        this.adjDistances= a ;
        this.vertices = v ;
        floyd_warshell();
    }
    public void floyd_warshell(){
        for(int k = 0 ; k < vertices ; k++){
            for(int i = 0 ; i < this.vertices ; i++){
                if(i == k) continue; ;
                for(int j = 0 ; j < this.vertices ; j++){
                    if(j == k )continue;
                    if(adjDistances[i][k] == Integer.MAX_VALUE || adjDistances[k][j] == Integer.MAX_VALUE)
                        continue;
                    if(adjDistances[i][k] + adjDistances[k][j] < adjDistances[i][j])
                        adjDistances[i][j] = adjDistances[i][k] + adjDistances[k][j] ;

                }
            }
        }
        for(int i = 0 ; i < vertices ; i++){
            for(int j = 0 ; j < vertices ; j++){
                if(adjDistances[i][j] == Integer.MAX_VALUE)
                    System.out.print("\u221E"+ " ");
                else
                System.out.print(adjDistances[i][j] + " ");
            }
            System.out.println();
        }
    }
}
