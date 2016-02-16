#ifndef BS_GUI_APPLICATION_H 
#define BS_GUI_APPLICATION_H 


#include <gtk/gtk.h>

struct _CemApplication
{
  GtkApplication parent;

};


struct _CemApplicationClass
{
  GtkApplicationClass parent_class;

};

#define  CEM_APPLICATION_TYPE (cem_application_get_type())
#define  CEM_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CEM_APPLICATION_TYPE, CemApplication))

typedef struct _CemApplication CemApplication;
typedef struct _CemApplicationClass CemApplicationClass;


GType cem_application_get_type(void);

CemApplication * cem_application_new(void);







#endif

