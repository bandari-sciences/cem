#include <gtk/gtk.h>

#include "bs_gui_application.h"

int
main(int argc, char *argv[])
{
  return g_application_run(G_APPLICATION (cem_application_new()),
  argc, argv);
}
