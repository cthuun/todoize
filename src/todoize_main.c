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

/**
 * \mainpage 
 * Welcome to the documentation of ToDoize, hope the project please you.
 */
/**
 * \param[in] argc
 * \param[in] argv
 * \return #todoize_error
 * \brief
 */
int main(int argc, char** argv)
{
  t_todoize_options todoize_options; /**< Here is the definition of
                                       the todoize_options struct,
                                       it should be passed all over
                                       the program to be able to determine
                                       the comportement of ToDoize */
  int ret = TODOIZE_ERROR_NONE;

  /* We parse the command line and fill todoize_options */
  if (todoize_getopt(argc, argv, &todoize_options))
  {
    TD_ERR("Fail analyze options - please double check them (try \"%s -h\")\n", argv[0]);
    return TODOIZE_ERROR_GETOPT;
  }
  /* Display help and return */
  if (todoize_options.display_help)
  {
    todoize_help_display(argv[0]);
    return TODOIZE_ERROR_HELP;
  }
  /* Display version and return */
  if (todoize_options.display_version)
  {
    todoize_version_display(argv[0]);
    return TODOIZE_ERROR_VERSION;
  }
  /* TODO: parse a conf file if a path is provided */
  /*
   * if (todoize_options.conf_file != NULL)
   * todoize_conf_file_parse(todoize_options);
   */

  ret = todoize_display_main();
  todoize_options_close(todoize_options);
  return ret;
}
