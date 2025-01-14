#include <iostream>
using namespace std;
int main()
{
   char ch;
   cout << "Enter a charecter of your choice:";
   cin >> ch;

   for (int i = 'a'; i <= 'z'; i++)
   {
      if (i == ch)
      {
         printf("The Provided Charecter %c is an LowerCase Charecter.", ch);
      }
   }
   for (int i = 'A'; i <= 'Z'; i++)
   {
      if (i == ch)
      {
         printf("The Provided Charecter %c is an UpperCase Charecter.", ch);
      }
   }
   for (int i = '0'; i <= '9'; i++)
   {
      if (i == ch)
      {
         printf("The Provided Charecter %c is an Numerical Charecter.", ch);
      }
   }
   return 0;
}