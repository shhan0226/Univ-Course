#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Replace
{
  public:
    char *result, *str, *string;       //vairable declare
    int count, len, start, i, j;
    char* putString();                 //funtion declare
    void getString(char *s);
    

};

void Replace::getString(char *s)       //mem-funtion initialization
{
  string = s;
  count = 0;
  start = 0;
  len = strlen(string);
  result = new char(len);
  str = result;

}


char* Replace::putString()
{

  for(i =0; string[i] != '\0'; i++){   //loop until end of stirng
    if(string[i] != string[i+1]){      //i-th and i+1th are different

     if(count < 2){                    //if counter less than 2
      for(j = start; j <= i; j++){     //assignment j to start location , until i
       *str = string[j];               //input string from s
        str++;                         //stirng pointer +1
      }
      start = i+1;                     //reallocation start location 
      count = 0;                       //initialization counter
     }
     else{                             //when counter grater tane 2
      *str = 48;                       //input '0' to stirng
      str++;                           //string pointer +1
      count = 0;                       //initialization counter
      start = i+1;                     //reallocatin start location
     }
    }

   else{                               //ith and i+1th are the same
     count++;
    }
  }

  *str = '\0';                         //input '\0' to string

  return result;                       //return result stirng

}



int main(){
  char s[] = "000000000000000000";     //string initialization
  char *s2;
  int s_len;                           //string length                       
  int i, j, k, l , m, n;           
  char str[6][4] ;                     //declaration char 3 * 6
  char buf[4];                         //declaration buffer 
  char string[19];                     //declaration string = char 3 * 6
  int count =1;                        //string counter initialization
  Replace rep;


  for(i=0; i<6; i++){                  //keyboard input character
    cout <<"input string no." << i << " : "<< endl;
    scanf("%s",&buf[0]);
    str[i][0] = buf[0];
    str[i][1] = buf[1];
    str[i][2] = buf[2];
  }

  printf("--OK! Let's go---------\n");

  for(i=0; i<6; i++){                   //arrary sequence
    for(j=0; j<6; j++){
      if( i != j ){
        for(k=0; k<6; k++){
         if( (k != j) && (k != i) ){
           for(l=0; l<6; l++){
             if( (l != k) && (l != j) && (l != i) ){
               for(m=0; m<6; m++){
                 if( (m != l) && (m != k) && (m != j) && (m != i) ){
                   for(n=0; n<6; n++)
                     if( (n != m) && (n != l) && (n != k) && (n != j) &&(n !=i ) ){

                       string[0]= str[i][0];              //input value to string
                       string[1] = str[i][1];
                       string[2]= str[i][2];
                       string[3] = str[j][0];
                       string[4]= str[j][1];
                       string[5] = str[j][2];
                       string[6] = str[k][0];
                       string[7] = str[k][1];
                       string[8] = str[k][2];
                       string[9] = str[l][0];
                       string[10] = str[l][1];
                       string[11] = str[l][2];
                       string[12] = str[m][0];
                       string[13] = str[m][1];
                       string[14] = str[m][2];
                       string[15] = str[n][0];
                       string[16] = str[n][1];
                       string[17] = str[n][2];
                       string[18] ='\0';

                       cout << count << " : " << string;  //print stirng
                       count++;                           //string counter +1
                       strcpy(s, string);                 //copy string to s 
                       s_len = strlen(s);                 //input string length

                       while(s_len){              //repeat replace untill length
                         rep.getString(s);
                         s2 = rep.putString();    //replace '000.'.=>0 /'111..'=>0
                         strcpy(s, s2);           //copy s2 to s
                         s_len--;                 //stirng length -1  
                       }
                         
                       (s2 != NULL) ? printf(" result: %s\n", s2) : fputs("Replace String Error...\n", stderr);
                                                  //pritnt normal stirng or print error
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
