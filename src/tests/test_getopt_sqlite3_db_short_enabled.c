#include <todoize_error.h>
#include <todoize_options.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main(void)
{
  char  db[] = "test";
  char* cmdline[] = {"", "-b", db};
  t_todoize_options options;
  assert(todoize_getopt(3, cmdline, &options) == TODOIZE_ERROR_NONE);
  assert(strcmp(db, options.sql3_db) == 0);
  todoize_options_close(options);
  return 0;
}
