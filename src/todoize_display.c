#include <todoize_display.h>

static void todoize_display_help(void)
{
  clear();
  printw("key       action\n");
  printw("[?|h]     display help (this)\n");
  printw("q         quit\n");
  refresh();
  getch();
}


/**
 * \brief Display the entries in the todolist.
 */
static void todoize_display_entries()
{
  clear();
  printw("Hello World !!!");  /* Print Hello World      */
  refresh();      /* Print it on to the real screen */
}

/**
 * \return #e_todoize_error
 * \brief test
 * This is the main function of the program.
 *
 */
int todoize_display_main(void)
{
  int key_pressed;
  initscr();      /* Start curses mode      */
  noecho(); /* Do not print on screen when getch() */
  todoize_display_entries();
  while (((key_pressed = getch()) != 'q'))      /* Wait for user input */
  {
    switch (key_pressed) {
      case 'h':
      case '?':
        todoize_display_help();
        break;
      default:
        break;
    }
    todoize_display_entries();
  }
  endwin();     /* End curses mode      */
  return TODOIZE_ERROR_NONE;
}
