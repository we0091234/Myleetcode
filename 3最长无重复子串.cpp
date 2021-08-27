#include <iostream>
#include <string>
#include <string.h>
using namespace std;
  int lengthOfLongestSubstring(string s)
   {
       int index1 = 0;
       int flag =0;
       int maxLength = 0;
       const char * sr=s.c_str();
       int i = 0;
       for( i = 0; i<strlen(sr); i++)
       {
           for(int j = index1; j<i;j++)
           {
                 if(sr[j]==sr[i])
                 {
                     flag = 1;
                     break;
                 }
           }
           if (flag)
           {
              maxLength = max(maxLength,i-index1);
              index1=index1+1;
              i = i-1;
              flag = 0;
           }
       }
       if(i == strlen(sr) && flag==0)
       {
           maxLength = max(maxLength,i-index1);
       }
    
       return maxLength;
    }

int main(int argc, char ** argv)
{
    cout<<lengthOfLongestSubstring("a")<<endl;
    return 0;
}