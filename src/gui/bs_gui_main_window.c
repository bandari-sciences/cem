#include "bs_gui_main_window.h"
#include "widgets/bs_gui_gl_area.h"

struct _CemMainWindow
{
  GtkApplicationWindow parent;
};

struct _CemMainWindowClass
{
  GtkApplicationWindowClass parent_class;


};

typedef struct _CemMainWindowPrivate CemMainWindowPrivate;

struct _CemMainWindowPrivate
{
  int i;
  GtkWidget * opengl_viewport;
};

G_DEFINE_TYPE_WITH_PRIVATE(CemMainWindow, cem_main_window, GTK_TYPE_APPLICATION_WINDOW);


static void
cem_main_window_init(CemMainWindow *win)
{
  GtkWidget *glArea;
  CemMainWindowPrivate *priv;

  gtk_widget_init_template (GTK_WIDGET (win));

  glArea = cem_gl_area_new();

  priv = cem_main_window_get_instance_private (win);

  gtk_container_add(GTK_CONTAINER(priv->opengl_viewport), glArea);

  gtk_widget_show_all(GTK_WIDGET(win));
}

static void
cem_main_window_dispose(GObject *object)
{

}

static void
cem_main_window_class_init(CemMainWindowClass *klass)
{
  G_OBJECT_CLASS(klass)->dispose = cem_main_window_dispose;

  gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(klass), "/org/bandari/cem/glade/main.glade");
  gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (klass), CemMainWindow, opengl_viewport);

}

CemMainWindow *cem_main_window_new(CemApplication *app)
{
  return g_object_new(CEM_MAIN_WINDOW_TYPE, "application", app, NULL);
}

void cem_main_window_open(CemMainWindow *win, GFile *file)
{

}
