#include <stdio.h>

#include <config.h>
#include <todoize_options.h>
#include <todoize_error.h>
#include <todoize_debug.h>

static inline void todoize_version_display(char* name)
{
  fprintf(stdout, "%s - %s\n", PACKAGE_NAME, PACKAGE_VERSION);
}

static inline void todoize_help_display(char* name)
{
  fprintf(stdout, "%s - %s\n", PACKAGE_NAME, PACKAGE_VERSION);
  fprintf(stdout, "--\n\n");
  fprintf(stdout, "--help\t\t-h\t\tDisplay help (this)\n");
  fprintf(stdout, "--vesion\t-v\t\tDisplay information about the package\n");
}

int main(int argc, char** argv)
{
  t_todoize_options todoize_options;

  if (todoize_getopt(argc, argv, &todoize_options))
  {
    TD_ERR("Fail analyze options - please double check them (try \"%s -h\")\n", argv[0]);
    return TODOIZE_ERROR_GETOPT;
  }
  if (todoize_options.display_help)
  {
    todoize_help_display(argv[0]);
    return TODOIZE_ERROR_HELP;
  }
  if (todoize_options.display_version)
  {
    todoize_version_display(argv[0]);
    return TODOIZE_ERROR_VERSION;
  }
  return todoize_display_main();
}
