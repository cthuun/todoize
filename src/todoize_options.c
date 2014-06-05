#include <todoize_options.h>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>

static inline void todoize_options_init(t_todoize_options* todoize_options)
{
  todoize_options->display_help = 0;
}

int todoize_getopt(int argc, char** argv, t_todoize_options* todoize_options)
{
  int opt = 0;
  unsigned int options_index = 0;
  static struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
  };

  todoize_options_init(todoize_options);

  while ((opt = getopt_long(argc, argv, "h", long_options, &options_index)) != -1)
    switch (opt)
    {
      case 'h':
        todoize_options->display_help = 1;
        break;
      default:
        return 1;
    }
  return 0;
}
