import java.util.*;

public class CitiesInSortedOrder{
    static void printVisited(boolean arr[]){
        for(int i = 0 ; i < arr.length ; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num_cities = input.nextInt() ;
        int connections = input.nextInt();
        ArrayList<ArrayList<Integer>> citiesAndTheirEdges = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> finalAns = new ArrayList<>();
        SortedSet<Integer> temp = new TreeSet<>();
        for(int i = 0 ; i < num_cities ; i++){
            citiesAndTheirEdges.add(new ArrayList<Integer>());
        }
       // System.out.println(citiesAndTheirEdges);
        for(int i = 0 ; i < connections ; i++){
            int from_city = input.nextInt() ;
            int to_city = input.nextInt() ;
            citiesAndTheirEdges.get(from_city-1).add(to_city);
            citiesAndTheirEdges.get(to_city-1).add(from_city);
        }
       // System.out.println("enter company");
        int company = input.nextInt() ;
        //System.out.println(citiesAndTheirEdges);
        Queue<Integer> q = new LinkedList<>();
        boolean visited[] = new boolean[num_cities] ;
        boolean enterdInToQueue[] = new boolean[num_cities] ;
        q.add(company) ;
        int size = 1;
        enterdInToQueue[company-1 ] = true;

        while(!q.isEmpty()){
            //System.out.println("queue : " + q);
            //System.out.println("visited : " );
            int nowVisitingCity = q.poll();

            if(visited[nowVisitingCity-1] == true)
                continue;

            visited[nowVisitingCity-1] = true ;
            //CitiesInSortedOrder.printVisited(visited);
            for(Integer cities : citiesAndTheirEdges.get(nowVisitingCity-1)){
                if(visited[cities-1] == false && enterdInToQueue[cities-1] == false)
                    temp.add(cities);
               if(visited[cities-1] == false && enterdInToQueue[cities-1] == false ) {
                   q.add(cities);
                   enterdInToQueue[cities-1] = true ;
               }
            }
            size-- ;
            if(size == 0){
                size = q.size();
                finalAns.addAll(temp);
                temp.clear();
              
            }
            

        }
        System.out.println(finalAns);

    }
}