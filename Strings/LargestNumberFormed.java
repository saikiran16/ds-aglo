package Strings;

import java.util.*;

public class LargestNumberFormed {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter number of Elements");
        int n = input.nextInt();
        System.out.println("Enter the Array Elements");
        Integer arr[] = new Integer[n];
        for(int i = 0 ; i < n ; i++)
        {
            arr[i] = input.nextInt();
        }
        Comparator compare = new Comparator<Integer>() {
            @Override
            public int compare(Integer num1, Integer num2) {
                String s1 = String.valueOf(num1);
                String s2 = String.valueOf(num2);
                String s3 = s1+s2;
                String s4 = s2+s1;
                if(Integer.parseInt(s3) < Integer.parseInt(s4)){
                    return 1;
                }
                return -1;
            }
        };
        try{
            Arrays.sort(arr, compare);
        }
        catch(Exception e){}
        for(int i = 0 ; i < arr.length ; i++){
            System.out.print(arr[i]);
        }
        input.close();
    }

}
