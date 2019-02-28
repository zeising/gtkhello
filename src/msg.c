#include <gtk/gtk.h>

#include "config.h"
#include "msg.h"

void
print_msg(GtkWidget *widget, gpointer data)
{
#if defined(WANT_HELLO)
	g_print ("Hello World\n");
#elif defined(WANT_GOODBYE)
	g_print ("Goodbye World\n");
#else
	g_print ("\n");
#endif
}
