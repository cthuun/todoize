#include <stdio.h>

#include <config.h>

int main(void)
{
    fprintf(stdout, "Welcome to %s - %s\n", PACKAGE_NAME, PACKAGE_VERSION);
}
