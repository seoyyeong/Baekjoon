#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int i = 0;
    char* p;
    char  prev = ')';
    
    p = const_cast<char*>(s.c_str());
    while(*p!='\0')
    {
       if(*p == '(')
       {
           i++;
       }
        else
        {
            i--;
            if(i<0)
            {
                return false;
            }
        }
        p++;
    }
    
    if(i == 0)
    {
        return true;
    }
    return false;
        
    
}