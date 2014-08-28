#include <todoize_options.h>
#include <todoize_error.h>
#include <todoize_debug.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#ifdef SQLITE3
# define OPT_ADD_SQLITE3(x) (x "b:")
#else
# define OPT_ADD_SQLITE3(x) (x)
#endif /* SQLITE3 */

void todoize_options_close(t_todoize_options todoize_options)
{
#ifdef SQLITE3
  if (todoize_options.sql3_db)
    free(todoize_options.sql3_db);
#endif /* SQLITE3 */
}
/**
 * \param[out] todoize_options The struct to be initialized with the default values.
 * \brief Initialize todoize_options with default value.
 * \return Nothing (void)
 */
static inline void todoize_options_init(t_todoize_options* todoize_options)
{
  todoize_options->display_help = 0;
  todoize_options->display_version = 0;

#ifdef SQLITE3
  todoize_options->sql3_db = NULL;
#endif /* SQLITE3 */
}

#ifdef DEBUG
void todoize_options_dump(t_todoize_options* todoize_options)
{
  TD_DEBUG("t_todoize_options todoize_options = {\n");
  TD_DEBUG("\tdisplay_help = %d\n", todoize_options->display_help);
  TD_DEBUG("\tdisplay_version = %d\n", todoize_options->display_version);
#ifdef SQLITE3
  TD_DEBUG("\tsql3_db = %s", todoize_options->sql3_db);
#endif /* SQLITE3 */
  TD_DEBUG("}\n");
}
#endif /* DEBUG */
/**
 * \param[in] argc The number of params given to the program.
 * \param[in] argv The array of the params given to the program.
 * \param[out] todoize_options The struct filled with information retrived from commandline.
 * \return #e_todoize_error
 * \brief Parse the command line and fill #t_todoize_options accordinately.
 */
int todoize_getopt(int argc, char** argv, t_todoize_options* todoize_options)
{
  int opt = 0;
  int options_index = 0;
  static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {"version", no_argument, 0, 'v'},
#ifdef SQLITE3
    {"sqlite3_db", 1, 0, 'b'},
#endif /* SQLITE3 */
    {0, 0, 0, 0}
  };
  char short_options[] = OPT_ADD_SQLITE3("hv");
  TD_DEBUG("argc: %d\n", argc);
  TD_DEBUG("getopt short_options: %s\n", short_options);

  todoize_options_init(todoize_options);

  while ((opt = getopt_long(argc, argv, short_options, long_options, &options_index)) != -1)
    switch (opt)
    {
      case 'h':
        todoize_options->display_help = 1;
        break;
      case 'v':
        todoize_options->display_version = 1;
        break;
#ifdef SQLITE3
      case 'b':
        todoize_options->sql3_db = strdup(optarg);
        break;
#endif /* SQLITE3 */
      default:
        return TODOIZE_ERROR_GETOPT;
        break;
    }
  return TODOIZE_ERROR_NONE;
}
