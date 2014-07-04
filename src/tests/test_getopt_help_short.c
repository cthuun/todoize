#include <assert.h>
#include <todoize_options.h>
#include <todoize_error.h>
int main(void)
{
  {
    char *opt_str[] = {"", "-h"};
    t_todoize_options opt;
    assert(todoize_getopt(2, opt_str, &opt) == TODOIZE_ERROR_NONE);
  }

  return 0;
}
