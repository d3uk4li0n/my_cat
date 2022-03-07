#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define CHUNK 1024

int main(int argc, char **argv){
    FILE *f;
    size_t bytes;
    char buf[CHUNK];
    if(argc == 1){
        printf("filename needed\n");
        return 0;
    }   

    for(int i=1;i<argc;i++){
        f = fopen(argv[i], "r");
        if(f){
            while((bytes = fread(buf, 1, sizeof(buf), f)) > 0){
                write(1, &buf, bytes);
            }
            fclose(f);
        }else{
            printf("error opening: %s\n", argv[i]);
            continue;
        }
    }
    return 0;
}
