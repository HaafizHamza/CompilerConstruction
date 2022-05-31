#include<iostream>
#include<ctype.h>
using namespace std;

bool is_alpha(char ch);
bool is_letter(char ch);
bool is_digit(char ch);
bool is_plus(char ch);
bool is_minus(char ch);
bool is_div(char ch);
bool is_mul(char ch);
bool is_equal(char ch);
bool is_greater(char ch);
bool is_less(char ch);
bool is_colon(char ch);
bool is_qmark(char ch);
void lexical(string str);

int main(){
    string input;
    cout<<"Enter a string"<<endl;
    getline(cin,input);
    cout<<"Tokens are =======>"<<endl;
    lexical(input);
    return 0;
}

bool is_letter(char ch){
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
        return true;
    else
    return false;
}
bool is_digit(char ch){
    if(ch>='0' && ch<='9')
    return true;
    else
    return false;
}
bool is_plus(char ch){
    if (ch=='+')
    return true;
    else
    return false;
}
bool is_minus(char ch){
    if (ch=='-')
    return true;
    else
    return false;
}
bool is_div(char ch){
    if (ch=='/')
    return true;
    else
    return false;
}
bool is_mul(char ch){
    if (ch=='*')
    return true;
    else
    return false;
}
bool is_equal(char ch){
    if (ch=='=')
    return true;
    else
    return false;
}
bool is_greater(char ch){
    if (ch=='>')
    return true;
    else
    return false;
}
/* bool is_gequal(char ch){
    if (ch=='=')
    return true;
    else
    return false;
} */bool is_less(char ch){
    if (ch=='<')
    return true;
    else
    return false;
}/* bool is_lequal(char ch){
    if (ch=='<=')
    return true;
    else
    return false;
} */
bool is_alpha(char ch){
    if (ch=='@')
    return true;
    else
    return false;
}
bool is_colon(char ch){
    if (ch==':')
    return true;
    else
    return false;
}
bool is_qmark(char ch){
    if (ch=='?')
    return true;
    else
    return false;
}
void lexical(string str){
    int state=0;
    int i;
    char c='\0';
    string lexem;
    while(str[i]!='\0'){
        int flag=1;
        c=str[i];
        switch(state)
        {
            case 0:
                   if(is_alpha(c))
                   {
                       state=1;
                   }
                   else if(is_plus(c)){
                       state=0;
                       lexem=c;
                       cout<<"Token ====> <"<<"Addition,  "<<lexem<<" >"<<endl;
                       lexem="";
                       flag=0;
                   }
                   else if(is_minus(c)){
                       state=0;
                       lexem=c;
                       cout<<"Token ====> <"<<"Subtract,  "<<lexem<<" >"<<endl;
                       lexem="";
                       flag=0;
                   }
                   else if(is_div(c)){
                       state=0;
                       lexem=c;
                       cout<<"Token ====> <"<<"Divide,  "<<lexem<<" >"<<endl;
                       lexem="";
                       flag=0;
                   }
                   else if(is_mul(c)){
                       state=0;
                       lexem=c;
                       cout<<"Token ====> <"<<"Multilication,  "<<lexem<<" >"<<endl;
                       lexem="";
                       flag=0;
                   }
                   else if(is_letter(c)){
                       state=9;
                       flag=0;
                       lexem=lexem+c;
                   }
                   else if(is_less(c)){
                       state=11;
                       
                   }
                   else if(isspace(c))
                   {
                       state=0;
                       flag=0;
                   }
                   else if(is_greater(c)){
                       state=14;
                    
                   }
                   else if(is_equal(c)){
                       state=18;
                       
                   }
                   else if(is_digit(c)){
                       state=17;
                       lexem=lexem+c;
                       
                       cout<<"Token====> <Constant, "<<lexem<<" >"<<endl;
                       flag=0; 
                   }
                   else if(is_colon(c)){
                       state=0;
                       lexem=c;
                       cout<<"Token ====> <"<<"Idendation,  "<<lexem<<" >"<<endl;
                       lexem="";

                        }
                   else if(is_qmark(c)){
                       state=21;
                       }
                   else
                   {
                       cout<<"Invalid Token"<<endl;
                       
                   }

                   break;
                   case 1:
                   if(is_digit(c)||is_letter(c))
                   {
                       state=2;

                   }
                   
                   break;
                   case 2:
                   if(is_alpha(c))
                   {
                       state=0;
                       lexem=lexem+c;
                       cout<<"Token ====> <"<<"Identifier,  "<<lexem<<" >"<<endl;
                       lexem="";
                       flag=0;
                   }
                   else if(is_digit(c)||is_letter(c))
                   {
                       

                   }
                   else
                   {
                       cout<<"Invalid character Please follow the identifier rules"<<endl;
                       exit(0);
                   }

                   break;
                   case 9:
                         if(is_letter(c))
                         {   
                             flag=0;
                              lexem=lexem+c;
                             if(lexem =="num"||lexem=="though"||lexem=="single"||lexem=="bool"||lexem=="switch"||lexem=="cord"||lexem=="main"||lexem=="box")
                             {
                                 state=0;
                                 cout<<"Token ====> <"<<"Keyword,  "<<lexem<<" >"<<endl;
                                 lexem="";
                                 
                             }
                        
                         }
                   break;
                   case 11:
                          if(is_equal(c))
                          {
                              state=0;
                              lexem=lexem+c;
                              cout<<"Token ====> <"<<"Lequal,  "<<lexem<<" >"<<endl;
                              lexem="";
                           }
                          else
                          {
                              state=0;
                              cout<<"Token ====> <"<<"Less,  "<<lexem<<endl;
                              lexem="";
                              continue;
                          }
                          
                          break;
                    case 14:
                         if(is_equal(c))
                         {
                              state=0;
                              cout<<"Token ====> <"<<"Lequal,  "<<lexem<<endl;
                             lexem="";
                          }
                          else
                          {
                              state=0;
                               cout<<"Token ====> <"<<"Less,  "<<lexem<<endl;
                               lexem="";
                             continue;
                          }
                          
                          break;
                          case 17:
                        
                          if(is_digit(c)){

                          }
                          else if(isspace(c)||is_colon(c)){
                              state=0;
                              lexem=lexem+c;
                               cout<<"Token ====> <"<<"Constant,  "<<lexem<<" >"<<endl;
                               lexem="";
                               continue;
                          }
                          else{
                              state=0;
                              cout<<"contstant terminator are : and space"<<endl;

                          }
                          
                          break;
                          case 18:
                          if(is_equal(c))
                          {
                               state=0;
                               lexem=lexem+c;
                               cout<<"Token ====> <"<<"equal,  "<<lexem<<endl;
                               lexem="";
                               flag=0;
                          }
                          else
                          {
                             state=0;
                               cout<<"Token ====> <"<<"Equal,  "<<lexem<<">"<<endl;
                               lexem="";
                               
                             continue;
                          }
                          break;     
                      default:
                      cout<<"C++ semantic logical error"<<endl;    
        }
     if(flag==1)   
        lexem=lexem+c;
        i++;
    }

}

