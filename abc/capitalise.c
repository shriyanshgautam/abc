

#include <stdio.h>
#include <conio.h>
#define BACK 127
int getch(void);

int main(){
	int flag=1;
	char c='s';
	while(c!=EOF){
       c=getch();
       while(c==' ' || c== '\n' || c=='.' || c==',' || c==':' || c==';' || c=='\t' ||c=='\"'|| c=='-'||c=='\\' ||c=='/'||c=='(' ||c==')'
       				||c=='{'||c=='}'||c=='['||c==']'||c=='\''){
       	   printf("%c",c);
       	   flag=1;
       	   c=getch();
       }
       if(flag==1){
       	   if(c!=BACK){
       	   	c=toupper(c);
       	    printf("%c",c);
       	    flag=0;
       	   }else{
       	   	 printf("\b \b");
       	   	 flag=1;
       	   	 fflush(stdout);
       	   }
       }else{
       		if(c!=BACK){
       			printf("%c",c);
       		}else{
       		  printf("\b \b");
       		  flag=1;	
       		 
       		}
       		
       }

       
	}
	
	
	return 0;
    

}