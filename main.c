#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>


void _sl(const char *dir){
      struct dirent *d;
        DIR *dh = opendir(dir);
        if (!dh) {
            if (errno == ENDENT){
                perror("Directory doesn't exist");
            } else {
            perror("Cannot read directory!");
            }
            exit(EXIT_FAILURE);
        }
        while (d = readdir(dh) != NULL)
        if(d->d_name[0] == ".") continue;
        {
            printf("%s/n", d->d_name);
        }
    printf("Done/n");
    }

int main(int argc, char const *argv[])
{
    if (argc == 1){
        _ls(".");
    } else if (argc == 2)
    {
        if (argv[1][0] == '-'){
            int op_a = 0, op_l = 0;
            char *p = argv + 1;
        }
    }
    
}
