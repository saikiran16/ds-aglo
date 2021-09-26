import java.util.Arrays;
import java.util.Stack;

public class LargestRectangularAreaInHistogram {
    Stack<Integer> stack ;
    int[] nextSmallerELes;
    int[] prevoiusSmallerEles ;
    int arr[];
    LargestRectangularAreaInHistogram(int arr[] , int n){
        stack = new Stack<>();
        nextSmallerELes = new int[n];
        prevoiusSmallerEles = new int[n];
        Arrays.fill(nextSmallerELes ,-1);
        Arrays.fill(prevoiusSmallerEles,-1);
        this.arr = arr ;
    }
    void calcualteNextSmallerElementsAsIndexes(){
        stack.push(0);
        for(int i = 1; i < arr.length ; i++){
           while(!stack.isEmpty() && arr[stack.peek()] > arr[i]){
               nextSmallerELes[stack.pop()] = i;
           }
           stack.push(i);
        }
        for(int i : nextSmallerELes) System.out.print(i+ " ");
        System.out.println();
    }
    void calculatePreviousSmallerElementsAsIndexes(){
        stack.push(arr.length-1);
        for(int i = arr.length-2 ; i >= 0 ; i--){
            while(!stack.isEmpty() && arr[stack.peek()] > arr[i]){
                prevoiusSmallerEles[stack.pop()] = i;
            }
            stack.push(i);
        }
        for(int i : prevoiusSmallerEles) System.out.print(i+ " ");
    }

    public static void main(String[] args) {
        int arr[] = {6,2,5,4,5,1,6};
        LargestRectangularAreaInHistogram obj = new LargestRectangularAreaInHistogram(arr , arr.length);
        obj.calcualteNextSmallerElementsAsIndexes();
        obj.calculatePreviousSmallerElementsAsIndexes();
        int max_area = 0;
        for(int i = 0 ; i < arr.length ; i++){
            // For every bar calcuating the toal are of rectangle that can be formed by including itself .
            // we must consider the lowest bar to the left of it and also to thr right of it
            // So we calcuated the Previous and next smallest elements for every elements
            int currentRectanglearea  , length  = arr[i] , width =  1 ;
            if(obj.prevoiusSmallerEles[i] != -1){
                width= width + (i - obj.prevoiusSmallerEles[i] - 1 );
            }
            else width = width + (i);
            if(obj.nextSmallerELes[i]!= -1){
                width = width + (obj.nextSmallerELes[i] - i - 1);
            }
            else width = width + arr.length - 1 - i ;
           currentRectanglearea = length * width ;
            max_area = Math.max(currentRectanglearea , max_area);
        }
        System.out.println(max_area);

    }

}
