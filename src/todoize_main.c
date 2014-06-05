#include <stdio.h>

#include <config.h>
#include <todoize_options.h>
#include <todoize_error.h>

int main(int argc, char** argv)
{
  t_todoize_options todoize_options;
  fprintf(stdout, "Welcome to %s - %s\n", PACKAGE_NAME, PACKAGE_VERSION);
  if (todoize_getopt(argc, argv, &todoize_options))
  {
    fprintf(stderr, "Fail analyze options - please double check them (try \"%s -h\")\n", argv[0]);
    return TODOIZE_ERROR_GETOPT;
  }
  if (todoize_options.display_help)
  {
    return TODOIZE_ERROR_HELP;
  }
  return TODOIZE_ERROR_NONE;
}
