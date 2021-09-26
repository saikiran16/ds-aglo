package Stacks ;

import java.util.*;


public class NextGreaterFrequencyElement {
    /* Approach : We will store the frequencies in a hashmap and we will take a stack and start Finding the Next Greater Freuencies
    * by Same approch as Next Greater Element problem .
    * */
    static int[] generateNextGreaterFrequencyElements(int arr[] , int n){
        int finalAns[] = new int[n];
        Map<Integer ,Integer> frequencyMap = new HashMap<>();
        Stack<Integer> stack = new Stack<Integer>();
        for(int i = 0 ; i < arr.length ; i++){
            if(frequencyMap.containsKey(arr[i])){
                frequencyMap.replace(arr[i] , frequencyMap.get(arr[i])+1);
            }
            else{
                frequencyMap.put(arr[i] , 1);
            }
        }
        System.out.println(frequencyMap);
        Arrays.fill(finalAns , -1);
        stack.push(0);
        for(int i  =  1 ; i < arr.length ; i++){
            while(!stack.isEmpty() && frequencyMap.get(arr[i]) > frequencyMap.get(arr[stack.peek()])){
                int poped_index = stack.pop();
                finalAns[poped_index] = arr[i];
            }
            stack.push(i);
        }
        return finalAns;
    }

    // Main Method for Testing
    public static void main(String[] args) {
        int arr[] = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
        for(int i : generateNextGreaterFrequencyElements(arr , arr.length)){
            System.out.print(i + " ");
        }
    }
}
