#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(){
	char instr[MAX];
	int j = 0;
        int counter = 0;
        int c;

        printf("wprowadz instrukcje: \n");
        while((c = getc(stdin)) != '\n'){
        	if(c != '\ '){ 
				instr[counter] = c;
				counter++;
			}
       	}
        
       	instr[counter] = '\0';
       	printf("\nInstrukcja to - ");
       	while(instr[j] != '\0'){
               putchar(instr[j]);
               j++;
        }
    	
        printf("\n liczba znakow: %d\n", counter);
        	
 	int state = 3;
	char *str;
	char diagram[MAX] = "q3";
	
	int i = 0;
	int true = 0;
	
	for(i; i < counter; i++){ 
	
		if(instr[i] != '1')
 	   {
 	   		if(instr[i] != '0'){
 	   			fprintf(stderr,  "niewlasciwy format danych wejsciowych: %c\n", instr[i]);
 	   			true = 1;
 	   		   }
		}	
   	}
   
   	if(true == 1)
		    return 1;
	
	for(i = 0; i < counter; i++){ 
		
		switch(state){
			case 0:
				if(instr[i] == '1'){
					state = 1;
					str = "->q1";
				}else{
         	state = 2;
          str = "->q2";
	      }
				break;
			case 1:
				if(instr[i] == '1'){
           state = 0;
           str = "->q0";
        }else{
           state = 3;
           str = "->q3";
        }
				break;
			case 2:
				if(instr[i] == '1'){
           state = 3;
           str = "->q3";
        }else{
           state = 0;
           str = "->q0";
        }
				break;
			case 3:
			   if(instr[i] == '0'){
            state = 1;
            str = "->q1";
         }
         else if(instr[i] == '1'){
            state = 2;
            str = "->q2";
         }
			   break;
  	   }

		strcat(diagram, str);
        printf("%s\n", diagram);	
	}
	
	if( state == 2)
		printf("\nciag zaakceptowany\n");
	else 
		printf("\nciag niezaakceptowany\n");
	return 0;
}
