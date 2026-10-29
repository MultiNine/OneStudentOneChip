#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <sys/wait.h>

int main(void)
{
    glob_t files = {0};

    int rc = glob("*_tests", 0, NULL, &files);

    if (rc != 0) {
        fprintf(stderr, "Failed to find tests.\n");
        globfree(&files);
        return 1;
    }

    for(size_t i = 0; i < files.gl_pathc; i++) {
        char cmd[512];

        snprintf(cmd, sizeof(cmd),
                "./%s 2>> tests.log",
                files.gl_pathv[i]);

        int status = system(cmd);

        if(status != -1 && WIFEXITED(status)
           && WEXITSTATUS(status) == 0) {
            printf("%s PASS\n", files.gl_pathv[i]);
        } else {
            printf("%s FAILED\n", files.gl_pathv[i]);
            globfree(&files);
            return 1;
        }
    }

    globfree(&files);
    return 0;
}
