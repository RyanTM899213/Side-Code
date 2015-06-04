GL_INCDIR = /usr/include/GL
GL_LIBDIR = /usr/lib

XLIBS=-L/usr/X11R6/lib -lXmu -lXext -lX11 -lXi
#The following is for Mesa-3.0
#GL_LIBS = -L$(GL_LIBDIR) -lglut -lMesaGLU -lMesaGL -lm $(XLIBS)
#The following is for Mesa-3.2.1 and beyond
GL_LIBS = -L$(GL_LIBDIR) -lglut -lGLU -lGL -lm $(XLIBS)
LIBS=$(GL_LIBS)

#PROG= hello new_hello square planet mercury geartrain recursive_circle
PROG= robot

CFILES=$(PROG).c
OFILES=$(PROG).o

CC=gcc

CPPFLAGS=-I$(GL_INCDIR)
CFLAGS=-Wall -O -g
LDFLAGS=$(GL_LIBS)


all: $(PROG)

clean:
	-rm -f *.o $(PROG)

#$(PROG): $(OFILES)
#	$(CC) $(LDFLAGS) $(OFILES) -o $@ $(LIBS)
