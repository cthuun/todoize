#include <assert.h>
#include <todoize_options.h>
#include <todoize_error.h>
int main(void)
{
  char *opt_str[] = {"", "--help", "-p"};
  t_todoize_options opt;
  assert(todoize_getopt(3, opt_str, &opt) == TODOIZE_ERROR_GETOPT);

  return 0;
}
