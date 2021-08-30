#include <iostream>
#include <string>
using namespace std;
   bool  isPalindrome(int x) {
       auto s = to_string(x);
       for(int i = 0; i<s.length()/2;i++)
       {
           if(!(s[i]==s[s.length()-1-i]))
           return false;
       }
           return true;
    }

int main(void)
{
    cout<<isPalindrome(-101)<<endl;;
    return 0;
}