#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

char   New[20];
char Letter;
 int systemResult,newElement,systemDefault;
 FILE *f,*s;

void change ()
 {	
  char character;
  char str[20];	 
  int ix = 0;                               // индекс символов строки
  while (New[ix])                           // пока не конец строки
  {	
    character = New[ix];
    if (New[ix]>58)
    New[ix]=(char)toupper(character);   // преобразовать строчную букву в прописную
    ix++;         						// инкремент индекса символов строки
//	printf("%s\n",New);                      
  }
 }

int ten () {      
		if (systemDefault==10){
		    newElement=atoi(New);	
		   itoa(newElement, New, systemResult);	
		}
		else {
			 itoa(newElement, New, systemResult);	
		}  
		if (Letter=='H' || Letter=='h' && Letter!='L' && Letter!='l'){
          change();               
		  }	
        return systemResult;
}

int noTen(){
	int degree;
	int Element;
    int numberElements=strlen(New);
    newElement=0;
  //  printf("%d\n",strlen(New)); 
	if (systemDefault<10) { 
	   Element=atoi(New);
       for (degree=0;degree!=numberElements;degree++) {
    	   newElement+=pow(systemDefault,degree)*(Element%10);
    	   Element/=10;
		   }		   	
	}
	else {
		Element=numberElements-1;
    for (degree=0;degree!=numberElements;degree++,Element--) {
    //    printf("1)%d\n",newElement);
    	newElement+=(pow(systemDefault,degree))*(waste(Element));	
		}		
	}
	itoa(newElement, New, 10);   
		   return 10;
}	
	int waste(int iter){
		
		if (New[iter]<=57){
			char Buf [15] = {New[iter]};
			int num=atoi(Buf);
			return num;
		}
		else {
			int iter1=0;
			while (1)   {	
			if (New[iter]<=90 ){
                return New[iter]-55;                
                     }
			else {
				return New[iter]-87;		
				}
			}
		}	 		
	}

void begin () {
	int systemNumber;
	while(systemNumber!=systemResult) {	
	    if (systemDefault==10 || systemNumber==10) {
            systemNumber=ten();	
	    }  
	    else 
	systemNumber=noTen();	
	}
//	printf(" Result: %s \n",New);   
//	printf("%d\n",strlen(New)); 
}

void save(char finame2[]){
	s=fopen(finame2,"a");
 //    	printf("save %s\n",New);
    fprintf(s," %s",New);
	fclose(s);  
    strcpy(New,"");
}

	void load (){	
	char finame[15],finame2[20];
    printf( "Enter the name of file: \n" );
    scanf( "%s", finame );
    printf( "Enter the name of file(2): \n" );
    scanf( "%s", finame2 );
	if ((f=fopen(finame, "r")) != NULL) {
	   fscanf(f,"%c%d%d",&Letter,&systemDefault,&systemResult);
	//	printf("%s %d %d \n",Letter,systemDefault,systemResult);
	while(fscanf(f,"%s",New)!= EOF )   {
//		printf("while %s \n",New);
		begin();
		save(finame2);
	    }
	}
	else {
	printf("Cannot open directory file.");		
	}
	fclose(f);
	 
}
int main() {
    load();	
    system("pause");
	return 0;

}
	
