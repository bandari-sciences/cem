#ifndef BS_GUI_MAIN_WINDOW_H 
#define BS_GUI_MAIN_WINDOW_H 


#include <gtk/gtk.h>

#include "bs_gui_application.h"

#define CEM_MAIN_WINDOW_TYPE (cem_main_window_get_type())

#define CEM_MAIN_WINDOW (G_TYPE_CHECK_INSTANCE_CAST ((obj), CEM_MAINWINDOW_TYPE, CemMainWindow))


typedef struct _CemMainWindow CemMainWindow;
typedef struct _CemMainWindowClass CemMainWindowClass;


GType cem_main_window_get_type(void);
CemMainWindow *cem_main_window_new(CemApplication *app);

void cem_main_window_open(CemMainWindow *win, GFile *file);











#endif

