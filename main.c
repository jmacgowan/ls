#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc == 1){
        struct dirent *d;
        DIR *dir = opendir(".");
        if (!dir) {
            perror("Sorry no directory found!");
            exit(EXIT_FAILURE);
        }
        while (d = readdir(dir) != NULL)
        if(d->d_name[0] == ".") continue;
        {
            printf("%s/n", d->d_name);
        }
    printf("Done/n")
    }
}
