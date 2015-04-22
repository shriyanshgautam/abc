#include <stdio.h>
#include <ctype.h>
#include <conio.h>

int getch(void);

int main(){
	int o=-1;
	int t=-1;
	int flag=0;
	int error=0;
	int number=0;
	int count;
	printf("\n\nTheoretical probability Calculator\n");
	printf("Enter a valid sum of faces of two dice : ");
	o=getch();
	while(o!='\n'){
		if(o>47 && o<58){
			printf("%c",o);
			error=0;
			if(flag==0){
				flag=1;
			    t=o;
			    o=getch();
			}else{
				//flag=1
				break;
			}
			

		}else{
			if(error==0){
				printf("\n %c \n Please Enter a valid number :",o);
				error=1;
			}
			
			flag=0;
			t=-1;
			o=getch();
		}
	}
	if(t>47 && t<58 && o!=10){
		//printf("Number %d%d\n",t-48,o-48 );
		number=((t-48)*10)+o-48;
	}else if(o==10){
		//printf("Number %d\n",t-48 );
		number=t-48;
	}

    int i;
    for(i=1;i<number && i<7;i++){
    	if(number-i>0 && number-i<7){
    		count++;
    	}
    }

    printf("\nProbability of %d is :%f\n", number,(float)count/36.0);
	


}