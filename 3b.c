#include<stdio.h> 
#include<string.h> 
int main() 
{ 
 
 FILE *fp = fopen("CDInput.txt", "r") ; 
 
 if ( fp == NULL ) 
 { 
 printf( "File failed to open." ) ; 
 } 
 else 
 { 
 
 printf("The file is now opened.\n") ; 
 char str[50]; 
 
 int zhi=1; 
 
 while( fgets ( str, 50, fp ) != NULL ) 
 { 
 printf( "\n\nFor Line %d: %s\n\n" , zhi, str ) ; 
 zhi++; 
 int i, l; 
 l = strlen(str); 
 
 for(i=0; i<l; i++) 
 { 
 char c = str[i]; 
 if(c == '+' || c =='-' || c =='/' || c 
=='*' || c =='%' || c =='=' || c == '&'|| c == '>' || c == '<' || 
c=='!' || c==':') 
 { 
 char d = str[i+1]; 
 if(d=='=' || c == '+' && d=='+' || 
c == '-' && d=='-') 
 { 
 printf("An operator is %c%c\n",c,d); 
 i++; 
 } 
 else 
 printf("An operator is %c \n",c); 
 } 
 else if(c == ';' || c == ',') 
 printf("%c is a DELIMETER\n",c); 
 else if(c == '(' || c == ')' || c == '{' 
|| c == '}' || c == '[' || c == ']' ) 
 printf("%c is a BRACKET\n",c); 
 else if(c=='"') 
 { 
 char a[100]="";// 100 is minimum 

 strncat(a, &c, 1); 
 
 int j=i+1; 
 char d = str[j]; 
 
 while(j<l && d!='"') 
 { 
 strncat(a, &d, 1); 
 j++; 
 d=str[j]; 
 } 
 
 if(d=='"') 
 { 
 strncat(a, &d, 1); 
 printf(" A constant is %s\n",a); 
 } 
 else 
 break; 
 i=j; 
 } 
 else if(c>='A' && c<='Z' || c>='a' && 
c<='z') 
 { 
 
 char a[10]=""; 
 strncat(a, &c, 1); 
 
 int j=i+1; 
 char d = str[j]; 
 
 while(d>='A' && d<='Z' || d>='a' && 
d<='z') 
 { 
 strncat(a, &d, 1); 
 j++; 
 d=str[j]; 
 } 
 
 if(strcmp(a,"printf") == 0 || 
strcmp(a,"scanf") == 0 || strcmp(a,"for") == 0 || strcmp(a,"while") == 
0 || strcmp(a,"do") == 0 || strcmp(a,"if") == 0 || strcmp(a,"else") == 
0 || strcmp(a,"int") == 0 || strcmp(a,"float") == 0 || 
strcmp(a,"double") == 0 || strcmp(a,"char") == 0 || strcmp(a,"long") == 
0 || strcmp(a,"short") == 0 || strcmp(a,"void") == 0 || 
strcmp(a,"return") == 0 || strcmp(a,"switch") == 0 || strcmp(a,"case") 
== 0 ) 
 printf(" A keyword is %s\n",a); 
 else 
 printf(" A variable is %s\n",a); 
 i=j-1; 
 } 
 else if(c>='0' && c<='9') 
 { 
 char a[10]=""; 
 strncat(a, &c, 1); 
 
 int j=i+1; 
 char d = str[j]; 
 
 while(d>='0' && d<='9') 
 { 
 strncat(a, &d, 1); 
 j++; 
 d=str[j]; 
 } 
 
 printf(" A constant is %s\n",a); 
 i=j-1; 
 } 
 } 
 } 
 
 // Closing the file using fclose() 
 fclose(fp) ; 
 
 printf("\n\nData successfully read from file\n"); 
 printf("The file is now closed.") ; 
 } 
 
 return 0; 
}
