package Arrays;


class Solution {
    boolean seen[][] = null ;
    public int maxAreaOfIsland(int[][] grid) {
        
        int i , j ,max = 0 ;
        seen = new boolean[grid.length][grid[0].length] ;
        for(i = 0 ; i < grid.length ; i++){
            for(j = 0 ; j < grid[0].length ; j++){
                max = Math.max(max , getArea(grid , i , j , seen ) );
            }
        }
        return max ;
        
    }
    
    public int getArea(int[][] grid , int row , int col , boolean seen[][]){
        if(row >= grid.length || row < 0 || col >= grid[0].length || col < 0 || seen[row][col]) return 0;
        if(grid[row][col] == 0) return 0;
        
        seen[row][col] = true ;
        return 1 + getArea(grid , row-1 , col , seen) + getArea(grid , row+1 , col,seen) + getArea(grid , row , col-1 ,seen) 
            + getArea(grid , row , col+1,seen);
    }
} 


