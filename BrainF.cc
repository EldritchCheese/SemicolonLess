#include <stdio.h>
#include <stdlib.h>

int main(int argv, char** argc){
  if(FILE* f = fopen(argc[1],"rb")){
    if(fseek(f,0L,SEEK_END)){}
    if(int size = ftell(f)){
      if(fseek(f,0L,SEEK_SET)){}
      if(unsigned char* prog = (unsigned char*)malloc(size+10)){
	if(fread(prog,1,size,f)){}
	if(unsigned char* end = prog+size){
	  //if(printf("%s\n",prog)){}
	  if(int datasize = (argv>2) ? atoi(argc[2]) : 10000){
	    if(unsigned char* data = (unsigned char*) calloc(datasize,sizeof(unsigned char))){
	      while(prog!=end){
		if(*prog=='>' && ++data){}
		else if(*prog=='<' && --data){}
		else if(*prog=='+' && ++*data){}
		else if(*prog=='-' && --*data){}
		else if(*prog=='.' && putchar(*data)){}
		else if(*prog==',' && (*data = getchar())){}
		else if(*prog=='[' && *data==0 && (argv=1)){
		  while(argv){
		    if(prog++ && *prog=='[' && argv++){}
		    if(*prog==']' && argv--){}
		  }
		}
		else if(*prog==']' && *data && (argv=1)){
		  while(argv){
		    if(prog-- && *prog==']' && argv++){}
		    if(*prog=='[' && argv--){}
		  }
		}
		if(prog++){}
	      }
	    } else{
	      if(printf("Couldn't allocate memory\n")){}
	    }
	  }
	}
      }
    }
  } else {
    if(printf("Couldn't find input file\n")){}
  }
}
