#include <todoize_options.h>
#include <unistd.h>
#include <stdio.h>

static void todoize_options_init(t_todoize_options* todoize_options)
{
  todoize_options->display_help = 0;
}
int todoize_getopt(int argc, char** argv, t_todoize_options* todoize_options)
{
  int opt = 0;
  todoize_options_init(todoize_options);
  while ((opt = getopt(argc, argv, "h")) != -1)
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
