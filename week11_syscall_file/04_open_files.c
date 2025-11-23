#include <stdio.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("파일이 전달되지 않았습니다..!\n");
        return 0;
    }

    int how_many = argc - 1;
    
    for (int i = 1; i <= how_many; i++) {
        int fd = open(argv[i], O_RDONLY);

        if (fd == -1) {
            printf("해당 파일은 OPNE 불가능합니다!!\n");
            perror(argv[i]);
        }

        else {
            printf("%s 파일을 OPEN 하는데 성공하였습니다!!\n");
        }
        close(fd);
    }
    return 0;
}