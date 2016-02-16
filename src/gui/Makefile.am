bin_PROGRAMS=cem_gui

cem_gui_SOURCES=bs_gui_application.c \
                bs_gui_main_window.c \
		bs_glade_resource.c  \
		widgets/bs_gui_gl_area.c \
		bs_gui.c


cem_gui_CFLAGS=${GTK3_CFLAGS} ${GL_CFLAGS} ${X11_CFLAGS}


cem_gui_LDADD=${GTK3_LIBS} ${GL_LIBS} ${X11_LIBS}
