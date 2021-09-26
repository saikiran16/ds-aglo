package Arrays;

/*
To answer range Queries Like sum of all elements in an array from index 2 to 5 
We will use Square root decomoposition method where we wiil divide the enitre array into block
Usally Sqrt(n) blocks 
Ex : 1 2 3 4 5 6 7 8 9
Blocks : [1 2 3] , [4 5 6] , [7 8 9]
Then we will calcuate sum for each block
BlocksSum = [6 15 24]
Now we can answer queires in Sqrt(n) time : follow this 
SumRange(2 , 6) ====> arr[2] + BlocksSum[1] + arr[6] 


*/


class NumArray {
    int arr[] = null ;
    int blocks[]  ; 
    int blockSize ;
    int totalBlocks ;
    public NumArray(int[] nums) {
        arr = nums ;
        blockSize = (int)(Math.sqrt(nums.length));
        totalBlocks =(int) Math.ceil(nums.length / (double)blockSize) ;
        blocks = new int[totalBlocks];
        int j = 0 ,sum = 0 ;
        for(int i = 1 ; i <= nums.length  ; i++ ){
            sum = sum + arr[i-1] ;
            if(i%blockSize == 0) {
                blocks[j] = sum ; sum = 0 ;
                j++;
            }
            
        }
        if(sum != 0) blocks[j] = sum ;
       /* for(int i = 0 ; i < totalBlocks ; i++){
            System.out.println(blocks[i]);
        }*/
        
        
    }
    
    public void update(int index, int val) {
       // return 0;
        int old = arr[index] ;
        arr[index] = val ;
        int blockNumber = (index)/ blockSize ;
        blocks[blockNumber] = blocks[blockNumber] - old + arr[index] ;
        
    }
    
    public int sumRange(int left, int right) {
        int startingBlockNumber = (left  ) / blockSize ;
        int endingBlockNumber = (right  ) / blockSize ;
        int s = 0 ;
        int leftend  = startingBlockNumber * blockSize + blockSize - 1;
        for(int i = left ; i <= Math.min(right ,leftend ) ; i++){
            s = s + arr[i] ;
        }
        for(int i = startingBlockNumber+1 ; i < endingBlockNumber ; i++){
            s = s + blocks[i];
        }
        if(startingBlockNumber != endingBlockNumber){
           // int rightStart = Math.
            for(int i = endingBlockNumber * blockSize  ; i <= right ; i++){
                s = s + arr[i];
            }
            
        }
        return s;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */

 // To answers range queries
 /*
 ["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 */ 


 class Sqrt_Decomposition{
     public static void main(String[] args) {

        // Test here by adding More number to array 
         NumArray obj = new NumArray(new int[]{1 , 3 , 5});
         System.out.println(obj.sumRange(0, 2));
     }
 }