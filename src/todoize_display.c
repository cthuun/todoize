#include <ncurses.h>
#include <todoize_error.h>

int todoize_display_main(void)
{
  initscr();      /* Start curses mode      */
  printw("Hello World !!!");  /* Print Hello World      */
  refresh();      /* Print it on to the real screen */
  getch();      /* Wait for user input */
  endwin();     /* End curses mode      */
  return TODOIZE_ERROR_NONE;
}
