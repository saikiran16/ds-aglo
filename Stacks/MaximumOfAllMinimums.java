/*
Given a an array an we have to find the Minimum of all the maximum  values that  are present in every window of size k
Ex : 5 4 6 7 2 2 2
k = 3
Windows = [5,4,6] , [4,6,7] , [6,7,2] , [7,2,2] , [2,2,2]
Maximum =   6         7        7          7          2
Minimum = 7
 */
/*
Algorithm : I am going to use a dequeue for this where i will try to maintain the First element in the dequeue as the Maximum Element
            1) Try to delete the invalid index i.e the indexes that not in current window
            2) If Dequeue is empty insert the index
            3 )If dequeue is not empty and current elements is greater remove the elements from the reae of dequeue and insert art its position
            4) Collect the First elements as maximum at end of each iteration and also when currentIteration > windowSize-1 .
                Because that is where ew will move to next window .
 Dry Run :
          we have 5 4 6 7 2 2 2
          Iteration 1 :  queue is empty .so insert 5
          Iteration 2 : now we have 4 to be insserted . but 4 is less than 5 so i will insert 4 . dq:  5 4
          Iteration 3 : now we have 6 . 6 is greater that 4 and 5 so i will remove until 6 finds its place
          so up to now dq has only 6 . This indicates that 6 is the Greater elements found till now
          Iteration 4 : now we have 7 . 7 > 6 so 6 will be removed and 7 will be inserted .  Since we have moved to next window 7 is greater elements we can collect that in an ArrayList
          Iteration 5 : now we have 2 ,7 < 2 so 2 will be inserted into dq.
          Iteration 6 : now we have 2  .2 >= 2 so 2 will be removed but 7 >= 2 so 2 will be inserted .
          Iteration 7 : now we have another 2 . we will insert it .
          But here come . We have moved to the last window and our dq's first elements is 7 but 7 is not in current window .
          So we have to remove the Elements that doesnt belongs to current window .

          Note : In code we will push indexes into dequeue instead of array Elements . It will be easy remove the elements that are invalid when
          we maintain the indexes .
           */


import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;

public class MaximumOfAllMinimums {

    ArrayList<Integer> calcuateMaximums(int[] arr , int n, int windowSize ){
        ArrayList<Integer> maximums = new ArrayList<>();
        Deque<Integer> dq = new LinkedList<Integer>();

        for(int i = 0 ; i < n ; i++){
            // Trying to remove the invalid indexes . That are not part of current window .
            while( i > windowSize-1 &&  !dq.isEmpty() && dq.peekFirst() <= i - windowSize  ) dq.removeFirst();

            // Trying to add new Elements
            if(dq.isEmpty()) dq.offerLast(i);
            while(!dq.isEmpty() && arr[dq.peekLast()] <= arr[i] ) {
                dq.removeLast();
            }
            dq.offerLast(i);
            if(i >= windowSize-1){
                System.out.println("Maximum of current window is : " + arr[dq.peekFirst()]);
                maximums.add(arr[dq.peekFirst()]);
            }

            System.out.println(dq);
        }

        return  maximums ;
    }

    public static void main(String[] args) {
        int arr[] = {5,4,6,7,2,2,2};
        int k = 3 ;
        MaximumOfAllMinimums obj = new MaximumOfAllMinimums();
        obj.calcuateMaximums(arr , arr.length , k);
    }
}
