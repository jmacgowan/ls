#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void _ls(const char *dir, int op_a, int op_l) {
    DIR *dh = opendir(dir);
    if (!dh) {
        perror("Cannot read directory!");
        exit(EXIT_FAILURE);
    }
    struct dirent *d;
    while ((d = readdir(dh)) != NULL) {
        if (!op_a && d->d_name[0] == '.') continue;
        printf("%s\n", d->d_name);
        if (op_l) printf("\n");
    }
    if (!op_l) printf("\n");
}

int main(int argc, char const *argv[]) {
    if (argc == 1) {
        _ls(".", 0 , 0);
    } else if (argc == 2) {
        if (argv[1][0] == '-') {
            int op_a = 0, op_l = 0;
            char *p = (char *) (argv[1] + 1);
            while (*p) {
                if (*p == 'a') op_a = 1;
                else if (*p == 'l') op_l = 1;
                else {
                    printf("No known option\n");
                    exit(EXIT_FAILURE);
                }
                p++;
            }
            _ls(".", op_a, op_l);
        } else {
            _ls(argv[1], 0, 0);
        }      
    } else if (argc == 3) {
        if (argv[1][0] != '-') {
            perror("Incorrect Usage");
            exit(EXIT_FAILURE);
        }
        int op_a = 0, op_l = 0;
        char *p = (char *) (argv[1] + 1);
        while (*p) {
            if (*p == 'a') op_a = 1;
            else if (*p == 'l') op_l = 1;
            else {
                printf("No known option\n");
                exit(EXIT_FAILURE);
            }
            p++;
        }
        _ls(argv[2], op_a, op_l);
    }
    return 0;
}
