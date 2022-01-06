package TestingGraphAPI;

import GraphAPI.Floyd_Warshell_Algorithm;

public class TestingFloydWarshellAlgorithm {
    public static void main(String[] args) {
        final Integer InFinite = Integer.MAX_VALUE ;
        int vertices = 6 ;
        int adjDistance[][] = {
                {0,1,4,InFinite , InFinite , InFinite} ,
                {InFinite ,0,4,2,7 ,InFinite},
                {InFinite , InFinite ,0,3,4,InFinite},
                {InFinite , InFinite , InFinite,0,InFinite , 4},
                {InFinite , InFinite , InFinite,3,0,InFinite},
                {InFinite , InFinite , InFinite,InFinite ,5,0}
        };
        Floyd_Warshell_Algorithm floydAlgo = new Floyd_Warshell_Algorithm(adjDistance , vertices);
        //floydAlgo.floyd_warshell();

    }
}
