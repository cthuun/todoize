#ifndef TODOIZE_DEBUG_H_
# define TODOIZE_DEBUG_H_
# include <config.h>

#ifdef DEBUG
# define TD_DEBUG(x, args...) fprintf(stderr, "%s - DBG: " x, PACKAGE_NAME, ## args)
#else /* !DEBUG */
# define TD_DEBUG(x, args...)
#endif /* DEBUG */

#define TD_WARN(x, args...) fprintf(stderr, "%s - WARN: " x, PACKAGE_NAME, ## args)
#define TD_ERR(x, args...) fprintf(stderr, "%s - ERR: " x, PACKAGE_NAME, ## args)

#endif /* !TODOIZE_DEBUG_H_*/
