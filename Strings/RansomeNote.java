package Strings;

/*
    Given a two strings A and B . We need to check wheather we can form the String A from the Letter of String B.
    We can assume all are Lowercase letters.
*/

import java.util.*;
class RansomeNote{
        public static void main(String[] args) {
           Scanner input = new Scanner(System.in);
           System.out.println("Enter Two Strings A and B");
           String A = input.nextLine();
           String B = input.nextLine();

           // Creating a hash for A and B
           int[] hash_A = new int[26];
           int[] hash_B = new int[26];
           int temp = 1;
           for(int i = 0 ; i < A.length(); i++){ hash_A[A.charAt(i)-'a']++;}
           for(int i = 0 ; i < B.length(); i++){ hash_B[B.charAt(i)-'a']++;}
           for(int i = 0 ; i < 26 ; i++){
                if(hash_A[i] <= hash_B[i])
                continue;
                else{
                    temp = 0;break;
                }
           }
           if(temp == 0){
               System.out.println("Not a Ransome Note");
           }
           else{
               System.out.println("Ransome Note");
           }
           input.close();
        }
}
