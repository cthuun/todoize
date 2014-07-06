#include <todoize_options.h>
#include <todoize_error.h>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>

/**
 * \param[out] todoize_options The struct to be initialized with the default values.
 * \brief Initialize todoize_options with default value.
 * \return Nothing (void)
 */
static inline void todoize_options_init(t_todoize_options* todoize_options)
{
  todoize_options->display_help = 0;
  todoize_options->display_version = 0;
}

/**
 * \param[in] argc The number of params given to the program.
 * \param[in] argv The array of the params given to the program.
 * \param[out] todoize_options The struct filled with information retrived from commandline.
 * \brief Parse the command line and fill #t_todoize_options accordinately.
 */

int todoize_getopt(int argc, char** argv, t_todoize_options* todoize_options)
{
  int opt = 0;
  unsigned int options_index = 0;
  static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {"version", no_argument, 0, 'v'},
    {0, 0, 0, 0}
  };

  todoize_options_init(todoize_options);

  while ((opt = getopt_long(argc, argv, "hv", long_options, &options_index)) != -1)
    switch (opt)
    {
      case 'h':
        todoize_options->display_help = 1;
        break;
      case 'v':
        todoize_options->display_version = 1;
        break;
      default:

        return TODOIZE_ERROR_GETOPT;
    }
  return TODOIZE_ERROR_NONE;
}
