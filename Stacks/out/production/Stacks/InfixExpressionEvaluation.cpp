using namespace std;
#include<bits/stdc++.h>
int computeArthimetic(int op1 , int op2 , char operation){
    if(operation == '+') return op1 + op2 ;
    if(operation == '-' )return op1+op2;
    if(operation == '*') return op1*op2 ;
    return op2/op1 ;
}
int precedence(char operator_){
    if(operator_ == '*' ) return 1 ;
    if(operator_ == '/')  return 2 ;
    return 3 ;
}
int evaluateInfixExpression(string s){
    stack<int> operands_stack ;
    stack<char > operators_stack ; 
    for(char ch : s){
        if(ch ==' ') {continue ; }
        cout << ch << endl;
        if(ch == '(') {operators_stack.push(ch) ;}
        else if (ch >= 48 && ch <= 57 ){
            operands_stack.push(ch - '0' );
           // cout << "pushed " <<  ch << endl;
        }
        else if(ch == ')'){
           // cout << "poping unit -- (" <<endl;
            while( operators_stack.top() != '(' ){
                int op1 = operands_stack.top() ;
                operands_stack.pop();
                int op2 = operands_stack.top() ;
                operands_stack.pop() ;
                char operator_  = operators_stack.top();
                operators_stack.pop();
                int res = computeArthimetic(op1 , op2 , operator_);
                operands_stack.push(res);
               // cout << "poped " << op1 << " " << " poped " << op2 <<  " " << " operator " << operator_ << " pushed " << res << endl ;
            } 
            operators_stack.pop();
        }
        // It might be +,-,*,/
        else{
              while(!operators_stack.empty()   && operators_stack.top() != ')'
              && precedence(ch) > precedence(operators_stack.top())){
                  char operator_ = operators_stack.top() ; operators_stack.pop() ;
                  int op1 = operands_stack.top() ; operands_stack.pop() ;
                  int op2 = operands_stack.top() ; operands_stack.pop() ;
                  int res = computeArthimetic(op1 , op2 , operator_);
                  operands_stack.push(res);
                 // cout << "poped " << op1 << "  " << " poped " << op2 <<  " " << " operator " << operator_ << "pushed " << res << endl ;
           
              }
             // cout << "pushed " << ch <<endl;
              operators_stack.push(ch) ;
        }

    }
    while(!operators_stack.empty()){
        char operator_ = operators_stack.top() ; operators_stack.pop() ;
        int op1 = operands_stack.top() ; operands_stack.pop() ;
        int op2 = operands_stack.top() ; operands_stack.pop() ;
        int res = computeArthimetic(op1 , op2 , operator_);
        operands_stack.push(res);
    }
    return operands_stack.top();
}
int main(){
    string s  = "1 + (2 * 3 / 2*2)" ;
    cout << s << endl;
    cout << evaluateInfixExpression( s );
    
}