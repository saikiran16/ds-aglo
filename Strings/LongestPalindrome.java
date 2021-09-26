/*
Let us follow DP approch 
We will create a dp matrix  . 
First we will marks all substrings of lengths of 1 as palindromes .
Next we will go and marks for substrings of length 2 . If first and last characters of substring are equal then they are palindrome.
Next for rest of the substrings with different lengths . 
Incase of length 4 We have to check weather if first and last chars are equal and the substring in between them is palindrome is or not . 
In this case the middle substring is of length 2 which is already calculated .
*/
package Strings;

class LongestPalindrome {

    String s ;
    int longest = 1 ;
    int dp[][];
    public LongestPalindrome(String s){
        this.s = s ;
        dp = new int[s.length()][s.length()];
        calculateLongestPalindrome();
    }

    void calculateLongestPalindrome(){
        // Marking all palindromes of length 1 as they are palindromes by default .
        for(int i = 0 ;  i <s.length() ; i++){
            dp[i][i] = 1 ;
        }
        // For length 2 . we have to check wheather first and last elements are equal or not .
        for(int i = 0 ;  i < s.length()-1 ; i++){
            System.out.println("checking " + i + " " + (i+1));
            if(s.charAt(i) == s.charAt(i+1)) {
                dp[i][i+1] = 1 ;
                System.out.println(s.charAt(i) + " " + s.charAt(i+1)); 
                longest = 2 ;
            }
            else dp[i][i+1] = 0;
        }
        // For length 3 Also we need to check the same as 2
        for(int i = 0 ;  i < s.length()-2 ; i++){
            if(s.charAt(i) == s.charAt(i+2)) {
                dp[i][i+2] = 1 ;
                longest = 3;
            }
            else dp[i][i+2] = 0;
        }
        // For the rest of the substringss of differnt lengths .
        for(int length = 4 ; length < s.length() ; length++ ){
            for(int i = 0 ; i < s.length() -length; i++){
                if( s.charAt(i) == s.charAt(i+length-1) &&   dp[i+1][i+length-2] == 1 ){
                    dp[i][length-1]=1;
                    longest = length;
                }
                else dp[i][length-1]=0;
            }
        }
        
       // printDPMatrix();
    }
     void printDPMatrix(){
        for(int i = 0 ; i < dp.length ; i++){
            for(int j = 0 ; j < dp.length ; j++){
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
    }
    
}