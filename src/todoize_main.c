#include <stdio.h>

#include <config.h>
#include <todoize_options.h>

int main(int argc, char** argv)
{
    t_todoize_options todoize_options;
    fprintf(stdout, "Welcome to %s - %s\n", PACKAGE_NAME, PACKAGE_VERSION);
    if (todoize_getopt(argc, argv, &todoize_options))
    {
        fprintf(stderr, "Fail analyze options - please double check them (try \"%s -h\")\n", argv[0]);
    }
    return 0;
}
