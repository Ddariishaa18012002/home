#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
        int fd[2];
        size_t size;
        char string[] = "Hello from pipe!\n";
        char resstring[17];

        if (pipe(fd)<0){
                 printf("Ne udalos sozdat pipe\n");
                 exit(-1);
        }
        size = write(fd[1], string, 17);
        if (size != 17) {
                  printf("Ne udalos zapysat 17 byte\n");
                  exit(-1);
        }
        size = read(fd[0], resstring, 17);
        if (size != 17) {
                  printf("Ne udalos prochitat 17 byte iz pipe\n");
                  exit(-1);
        }
        printf("Prochitannaya stroka: %s\n", resstring);
        if(close(fd[0])<0) {
                  printf("Ne udalos zakryt pipe dlya chtenya\n");
                  exit(-1);
        }
        if(close(fd[0])<0) {
                  printf("Ne udalos zakryt pipe dlya zapisi\n");
                  exit(-1);
        }
return 0;
}
