#include "bs_gui_application.h"
#include "bs_gui_main_window.h"

G_DEFINE_TYPE(CemApplication, cem_application, GTK_TYPE_APPLICATION);

static void
cem_application_quit_activated(GSimpleAction *action, GVariant *parameter, gpointer app)
{
  g_application_quit(G_APPLICATION(app));
}


static GActionEntry app_entries[]=
{
  {"quit", cem_application_quit_activated, NULL, NULL, NULL}
};

static void
cem_application_init(CemApplication *app)
{


}


static void
cem_application_startup(GApplication * app)
{
  GtkBuilder *builder;
  GMenuModel *app_menu;

  const gchar *quit_accels[2] ={"<Ctrl >Q", NULL};


  G_APPLICATION_CLASS(cem_application_parent_class)->startup(app);

  g_action_map_add_action_entries (G_ACTION_MAP(app),
    app_entries, G_N_ELEMENTS(app_entries), app);


  gtk_application_set_accels_for_action(GTK_APPLICATION(app), "app.quit", quit_accels);

  builder = gtk_builder_new_from_resource("/org/bandari/cem/glade/cem_menu.glade");

//  app_menu = G_MENU_MODEL (gtk_builder_get_object(builder, "appmenu"));

//  gtk_application_set_app_menu(GTK_APPLICATION(app), app_menu);

  g_object_unref(builder);
}

static void 
cem_application_activate(GApplication *app)
{
  CemMainWindow *win;

  win = cem_main_window_new(CEM_APPLICATION(app));

  gtk_window_present(GTK_WINDOW(win));


}


static void
cem_application_open(GApplication *app, GFile **files, gint n_files, const gchar *hint)
{


}

static void
cem_application_class_init(CemApplicationClass *klass)
{
  G_APPLICATION_CLASS(klass)->startup = cem_application_startup;
  G_APPLICATION_CLASS(klass)->activate = cem_application_activate;
  G_APPLICATION_CLASS(klass)->open = cem_application_open;
}

CemApplication * cem_application_new(void)
{
  return g_object_new(CEM_APPLICATION_TYPE, "application-id",
  "org.bandari.cem", "flags", G_APPLICATION_HANDLES_OPEN,
  NULL);

}
