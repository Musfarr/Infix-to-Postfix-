#include <iostream>
#include <stack>

using namespace std;


int isoperator(char a){

    if (a ==')' ){return 4;}
    if (a =='(' ){return 4 ;}
    if (a == '%'){return 2;}
    if (a == '^'){return 3;}
    if (a == '/'){return 2;}
    if (a == '*'){return 2;}
    if (a == '-'){return 1;}
    if (a == '+'){return 1 ;}

    else{
    return 0;} 
}


string infixpostfix(stack <char> s , string infix){
string postfix;
for (int i = 0; i < sizeof(infix); i++)
{
    if (infix[i]== '('){
        s.push(infix[i]) ;
    }

    else if( infix[i] == ')'){
        while (s.top() != '(' && (!s.empty()))
        {
            char temp = s.top();
            postfix += temp;
            s.pop();
        }
        if (s.top() == '(')
        {
            s.pop();
        }
        
    }

    else if (isoperator(infix[i]!= 0))
    {
        if (s.empty())
        {
            s.push(infix[i]);
        }
        
        else (isoperator(infix[i]<= isoperator(s.top())));
        {
            char temp= s.top();
            postfix+= temp;
            s.pop();        
        }
        
    }
    
    else{

        postfix += infix[i];
    }


}
while (!s.empty())
{
    char temp = s.top();
    postfix+= temp;
    s.pop();
}

return postfix;
}        

int main(){

string infix;
string postfix;

stack <char> s;

cout<<"Enter infix String:"<<endl;
cin>> infix;

string f = infixpostfix(s,infix);

cout<<"Postfix:"<<f;


    return 0;
}