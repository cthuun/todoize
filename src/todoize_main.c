#include <stdio.h>

#include <config.h>
#include <todoize_options.h>
#include <todoize_error.h>
#include <todoize_debug.h>
#include <todoize_display.h>

/**
 * \param[in] name The name of the binary.
 * \brief This function display the name and the version of the program
 */
static inline void todoize_version_display(const char* name)
{
  fprintf(stdout, "%s - %s\n", name, PACKAGE_VERSION);
}

/**
 * \param[in] name The name of the binary.
 * \brief Display the usage.
 */
static inline void todoize_help_display(const char* name)
{
  todoize_version_display(name);
  fprintf(stdout, "--\n\n");
  fprintf(stdout, "--help\t\t-h\t\tDisplay help (this)\n");
  fprintf(stdout, "--vesion\t-v\t\tDisplay information about the package\n");
#ifdef SQLITE3
  fprintf(stdout, "--sql3_db\t-b\t\tSet the path of the sql3lite database\n");
#endif /* SQLITE3 */
}

/**
 * \mainpage 
 * Welcome to the documentation of ToDoize, hope the project please you.
 */
/**
 * \param[in] argc The number of parameters.
 * \param[in] argv The array of parameters.
 * \return #e_todoize_error
 * \brief The entry point, initialize everything and start #todoize_display_main
 */
int main(int argc, char** argv)
{
  t_todoize_options todoize_options; /**< Here is the definition of
                                       the todoize_options struct,
                                       it should be passed all over
                                       the program to be able to determine
                                       the comportement of ToDoize */
  int ret = TODOIZE_ERROR_NONE; /**< By default everything goes right */

  /* We parse the command line and fill todoize_options */
  if (todoize_getopt(argc, argv, &todoize_options))
  {
    TD_ERR("Fail analyze options - please double check them (try \"%s -h\")\n", argv[0]);
    return TODOIZE_ERROR_GETOPT;
  }
#ifdef DEBUG
  /* If we are in debug mode we may want to see the options set. */
  todoize_options_dump(&todoize_options);
#endif /* DEBUG */
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

  todoize_display_init();
  ret = todoize_display_pre_main(); /* Dislay "Press ? to get help" during a short period */
  ret = todoize_display_main(); /* Run the program */
  todoize_options_close(todoize_options); /* Free the options */
  return ret;
}
