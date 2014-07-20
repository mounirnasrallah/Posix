#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h> 


int main (int argc, char* argv[])
{

  DIR *rep;

  if(argc==0){
   rep = opendir(".");
  }
  else{
    rep = opendir(argv[1]);
  }


  if (rep != NULL)
    {
      struct dirent *lecture;
 
      while ((lecture = readdir (rep)))
	{
	  struct stat st;
 
	  stat (lecture->d_name, &st);
	  {

            time_t t = st.st_mtime;
            struct tm tm = *localtime (&t);
            char s[32];
            strftime (s, sizeof s, "%d/%m/%Y %H:%M:%S", &tm);
 
            printf ("%-14s %s\n", lecture->d_name, s);
	  }
	}
      closedir (rep), rep = NULL;
    }

  else{
    
    if(errno==ENOENT){
      mkdir(argv[1],0777);
    }

    else{
      fprintf(stderr,"Error");
    }    
  }

  return 0;
} 
