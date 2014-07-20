#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

#define BUFFER_SIZE 100 

int check(char* path,char option_err){

  struct stat stat_info;
  
  if (stat(path, &stat_info) == -1){
    if(option_err==1){
    fprintf(stderr,"Error file not exist");
    exit(EXIT_FAILURE);
    }
    return 1;
  }

  if(S_ISDIR(stat_info.st_mode)){
    return 0;
  }
  else{
    return 1;
  }
}

int copy(char* _f1,char* _f2,char* _f3){

  char buffer_str1[BUFFER_SIZE];
  char buffer_str2[BUFFER_SIZE];

  int nbr_char;

  FILE* f1,*f2,*f3;

   f1  = fopen(_f1, "r");
   f2  = fopen(_f2, "r"); 
   f3  = fopen(_f3, "w"); 

   
   while(!feof(f1) && !feof(f2)){
     fscanf(f1,"%s ",buffer_str1);
     fscanf(f2,"%s ",buffer_str2);
     fprintf(f3,"%s %s ",buffer_str1,buffer_str2);
   }
   
   if(feof(f1) && !feof(f2)){
     while(!feof(f2)){
       nbr_char = fread(buffer_str2,sizeof(char),BUFFER_SIZE,f2);
       fwrite(buffer_str2,sizeof(char),nbr_char,f3);
     }
   }
   else {
     if(!feof(f1) && feof(f2)){
       while(!feof(f1)){
	 nbr_char = fread(buffer_str1,sizeof(char),BUFFER_SIZE,f1);
	 fwrite(buffer_str1,sizeof(char),nbr_char,f3);
       }
     }
   }
   
  fclose(f1); 
  fclose(f2);
  fclose(f3); 

}

int main(int argc, char* argv[]){
  
  if(argc>3)
    if((check(argv[1],1)==1) && (check(argv[2],1)==1))
      copy(argv[1],argv[2],argv[3]); 
    else
      fprintf(stderr,"Error arguments");
  else
    fprintf(stderr,"Error number of arguments");
  

  return EXIT_SUCCESS;
}
