#include <stdio.h>
#include <string.h>
 
int main()
{
    char s[1000];  
    int i;
    printf("Enter  the string : ");
    gets(s);
    for(i=0;i<strlen(s);i++)  
    {
      if(s[i]=='a'|| s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O' ||s[i]=='U'){
		    printf(" %c is vowel\n" ,s[i]);}
      else{
       printf(" %c is consonants\n" ,s[i]);
      }
 	}
    return 0;
}
