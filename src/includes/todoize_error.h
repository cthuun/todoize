#ifndef TODOIZE_ERROR_H_
# define TODOIZE_ERROR_H_

/**
 * \brief The error codes used in ToDoize
 */
typedef enum {
  TODOIZE_ERROR_NONE, /**< No error, everithing goes right */
  TODOIZE_ERROR_HELP, /**< Displaying help, not really an error */
  TODOIZE_ERROR_GETOPT, /**< An option passed to the program was not recognized */
  TODOIZE_ERROR_VERSION /**< Displaying the version, not an error */
} e_todoize_error;

#endif /* !TODOIZE_ERROR_H_ */
