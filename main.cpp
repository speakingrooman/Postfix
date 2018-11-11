//Rooman Zahid
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int operation(int , int, char);
int pushStack(string);
int operatorCount(string);
void ExpressionCount();
void errorExpression(bool);
stack<int> s;
int validExpressions,invalidExpressions,totalExpressions,operators;
bool flag=true;
int main(){
    string x;
    int postFix,input;
    cout<<"please enter number of expression(s) to evaluate : "<<endl;
    cin>>input;
    cin.ignore(256, '\n');
    for (int i=0; i<input; i++) {
        cout<<"please enter expression(s) : ";
        getline(cin,x);
        postFix=pushStack(x);
        if(flag==false){
            errorExpression(flag);
            operatorCount(x);
            ExpressionCount();
        } else {
            cout<<x<<" = "<<postFix<<endl;
            operatorCount(x);
            ExpressionCount();
        }
        flag=true;
        while(!s.empty()){
            s.pop();
        }
    }
    return 0;
}

int operation(int n1, int n2,char op){
    switch (op) {
        case '+':
            return(n1+n2);
            break;
        case '-':
            return(n1-n2);
            break;
        case '*':
            return(n1*n2);
            break;
        case '/':
            return(n1/n2);
            break;
        case '%':
            return(n1%n2);
            break;
        default:
            break;
    }
    return 0;
}

int pushStack(string x){
    int lastItem,n1,n2,stackTop;
    for (int i=0; i<x.length(); i++) {
        if(isdigit(x[i])){
            s.push(x[i]-48);
            
        }
        else if (x[i]!=' ' &&!isdigit(x[i]) ){
            if(s.empty()||s.size()==1){
                return flag=false;
            }
            n2 = s.top();
            s.pop();
            n1 = s.top();
            s.pop();
            if((x[i]=='/' || x[i]=='%') && (n2==0)){
                return flag=false;
            }
            stackTop=operation(n1, n2, x[i]);
            s.push(stackTop);
        }
    }
    if(!s.empty()&&s.size()==1){
    lastItem=s.top();
    s.pop();
    return lastItem;
    }
    return flag=false;
}

int operatorCount(string x){
    for (int i=0; i<x.length(); i++) {
        switch (x[i]) {
            case '+':
                operators+=1;
                break;
            case '-':
                operators+=1;
                break;
            case '*':
                operators+=1;
                break;
            case '/':
                operators+=1;
                break;
            case '%':
                operators+=1;
                break;
            default:
                break;
        }
    }
    return operators;
}

void ExpressionCount(){
    if (!s.empty()) {
        cout<<"Expression invalid. Stack not empty"<<endl;
        if(operators!=s.size()+1){
            cout<<"Expression invalid. Not enough operators for given operands "<<endl;
        }
    }
    if (flag==true) {
        validExpressions+=1;
        totalExpressions+=1;
    }
    cout<<"Total valid expressions: " <<validExpressions <<endl<< "Total invalid expressions: "<<invalidExpressions<<endl<<"Total expressions evaluated: "<<totalExpressions<<endl<<endl;
}

void errorExpression(bool flag){
    if (flag==false){
        cout<<"Error invalid expression "<<endl;
        totalExpressions+=1;
        invalidExpressions+=1;
    }
}



/*
test cases
 
 
no numbers
1 number
2 numbers
+
2 + +
2/0
0/2
2%0
0%2
(2+3) * (5-1) =20 the postfix notation is 2 3 + 5 1 - *
2+(3*5) – 1 = 16 the postfix notation is 2 3 5 * + 1 -
*/
