#ifndef BS_CEM_GL_H 
#define BS_CEM_GL_H 


#include <gtk/gtk.h>

G_BEGIN_DECLS

#define CEM_GL_AREA_TYPE      (cem_gl_area_get_type())
#define CEM_GL_AREA           (G_TYPE_CHECK_INSTANCE_CAST((obj), CEM_GL_AREA_TYPE, CemGLArea))
#define CEM_GL_AREA_CLASS     (G_TYPE_CHECK_CLASS_CAST((klass), CEM_GL_AREA_TYPE, CemGLAreaClass))

typedef struct _CemGLArea CemGLArea;
typedef struct _CemGLAreaClass CemGLAreaClass;

struct _CemGLArea
{
  GtkDrawingArea parent;

};

struct _CemGLAreaClass
{
  GtkDrawingAreaClass parent_class;


};


GType cem_gl_area_get_type(void) G_GNUC_CONST;
GtkWidget * cem_gl_area_new(void);








#endif

