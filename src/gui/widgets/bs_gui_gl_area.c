#include "bs_gui_gl_area.h"

#include<X11/Xlib.h>
#include<gdk/gdkx.h>
#include<GL/glx.h>
#include<GL/gl.h>
#include<GL/glu.h>


struct _CemGLAreaPrivate
{
  GdkWindow *drawing_window;
  Display *x_display;
  XVisualInfo *x_visual;
  XWindowAttributes x_attributes;
  GLXContext x_context;
  Window x_window;


};

typedef struct _CemGLAreaPrivate CemGLAreaPrivate;

G_DEFINE_TYPE_WITH_PRIVATE(CemGLArea, cem_gl_area, GTK_TYPE_DRAWING_AREA);


static void
cem_gl_area_configure(GtkWidget *area, gpointer data)
{
  GLint attributes[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};

  CemGLAreaPrivate *priv;

  gtk_widget_set_double_buffered(area, FALSE);

  priv = cem_gl_area_get_instance_private(area);

  priv->drawing_window = gtk_widget_get_window(GTK_WIDGET(area));

  priv->x_window = gdk_x11_window_get_xid(GDK_WINDOW(priv->drawing_window));

  priv->x_display = gdk_x11_get_default_xdisplay();

  priv->x_visual = glXChooseVisual(priv->x_display, 0, attributes);

  priv->x_context = glXCreateContext(priv->x_display, priv->x_visual, NULL, GL_TRUE);

  XGetWindowAttributes(priv->x_display, priv->x_window, &priv->x_attributes);

  glXMakeCurrent(priv->x_display, priv->x_window, priv->x_context);

  XMapWindow(priv->x_display, priv->x_window);

  glViewport(0, 0, priv->x_attributes.width, priv->x_attributes.height);

  glOrtho(-10, 10, -10, 10, -10, 10);

  glScalef(5.0, 5.0, 5.0);
}

static void
cem_gl_area_draw_callback(GtkWidget *area, gpointer data)
{
  CemGLAreaPrivate *priv;

  priv = cem_gl_area_get_instance_private(area);

  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glShadeModel(GL_FLAT);



  glPopMatrix();
  glXSwapBuffers(priv->x_display, priv->x_window);
}

static void
cem_gl_area_init(CemGLArea *area)
{
  gtk_widget_set_has_window(GTK_WIDGET(area), TRUE);

  g_signal_connect(area, "configure-event", G_CALLBACK(cem_gl_area_configure), NULL);

  g_signal_connect(area, "draw", G_CALLBACK(cem_gl_area_draw_callback), NULL);
  
}

static void
cem_gl_area_class_init(CemGLAreaClass *klass)
{

}



GtkWidget * 
cem_gl_area_new(void)
{
  return GTK_WIDGET(g_object_new(cem_gl_area_get_type(), NULL));
}
