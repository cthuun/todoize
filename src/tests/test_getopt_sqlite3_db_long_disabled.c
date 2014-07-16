#include <todoize_error.h>
#include <todoize_options.h>
#include <stdio.h>
#include <assert.h>
int main(void)
{
  char  db[] = "test";
  char* cmdline[] = {"", "--sqlite3_db", db};
  t_todoize_options options;
  assert(todoize_getopt(3, cmdline, &options) == TODOIZE_ERROR_GETOPT);
  return 0;
}
