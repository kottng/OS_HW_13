#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


int main(void) {
        int depth = 0;
        char *soruce_file = "a";
        char *dir = "dir1";
        FILE *file;
        char symlink_elem[3];
        mkdir(dir, 0700);
        file = fopen(soruce_file, "w");
        fclose(file);
        for (; depth < 1000; ++depth) {
                char elem1 = 'a' + depth;
                snprintf(symlink_elem, 3, "%c%c", elem1, elem1);
                symlink(soruce_file, symlink_elem);
                if (fopen(symlink_elem, "r") == NULL) {
                    printf("Достигнута глубина рекурсии: %d\n", depth);
                    break;
                }
                fclose(file);
                printf("Текущая глубина рекурсии: %d\n", depth);
        }
        for (int i = 0; i < depth; ++i) {
                char elem1 = 'a' + i;
                snprintf(symlink_elem, 3, "%c%c", elem1, elem1);
                unlink(symlink_elem);
        }
	unlink(soruce_file);
	rmdir(dir);
	return 0;
}
