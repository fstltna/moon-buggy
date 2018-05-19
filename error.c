/* error.c - functions to signal error conditions
 *
 * Copyright 1999  Jochen Voss  */

static const  char  rcsid[] = "$Id: error.c 4839 2003-04-13 16:50:02Z voss $";

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <unistd.h>

#include "moon-buggy.h"


void
fatal (const char *format, ...)
/* Signal a fatal error and quit immediately.  The arguments have the
 * same meaning, as in the function `printf'.
 * The message should start with a capital letter.  */
{
  va_list  ap;

  prepare_for_exit ();
  
  va_start (ap, format);
  fflush (NULL);
  fputs ("Fatal error: ", stderr);
  vfprintf (stderr, format, ap);
  fputc ('\n', stderr);
  va_end (ap);

  exit (EXIT_FAILURE);
}
