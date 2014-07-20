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

int search(char* _file,char* _word){

  char buffer[BUFFER_SIZE];

  int nb, pos;

  FILE* file;

   file  = fopen(_file, "r"); 

   
   while(!feof(file)){
     fscanf(file,"%s",buffer);
     if(strcmp(buffer,_word)==0){
       nb++;
       pos = ftell(file);
       printf("Occurence numéro %d à la position %d \n",nb,pos);
     }
   }
   
   printf("Nombre total d'occurences : %d",nb);
   fclose(file);     
}

int main(int argc, char* argv[]){
  
  if(argc>2)
    if((check(argv[1],1)==1))
      search(argv[1],argv[2]); 
    else
      fprintf(stderr,"Error arguments");
  else
    fprintf(stderr,"Error number of arguments");
  

  return EXIT_SUCCESS;
}
