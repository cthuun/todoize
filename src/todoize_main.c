#include <stdio.h>

#include <config.h>
#include <todoize_options.h>
#include <todoize_error.h>

static inline void todoize_help_display(char* name)
{
  fprintf(stdout, "%s - %s\n", PACKAGE_NAME, PACKAGE_VERSION);
  fprintf(stdout, "--\n\n");
  fprintf(stdout, "--help\t-h\t\tDisplay help (this)\n");
}

int main(int argc, char** argv)
{
  t_todoize_options todoize_options;

  if (todoize_getopt(argc, argv, &todoize_options))
  {
    fprintf(stderr, "Fail analyze options - please double check them (try \"%s -h\")\n", argv[0]);
    return TODOIZE_ERROR_GETOPT;
  }
  if (todoize_options.display_help)
  {
    todoize_help_display(argv[0]);
    return TODOIZE_ERROR_HELP;
  }
  return todoize_display_main();
}
