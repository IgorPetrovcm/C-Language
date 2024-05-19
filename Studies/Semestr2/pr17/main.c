# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <stdio.h>
# include <string.h>

# define X 0
# define Y 0
# define WIDTH 400
# define HEIGHT 300
# define BORDER 10
# define TITLE "example1"
# define ICON_TITLE "example1"
# define CLASS "example_class1"

int SetWindowManagerHints(
    Display* display,
    char* class, 
    char** argv,
    int argc,
    Window window,
    int x,
    int y,
    unsigned int window_width,
    unsigned int window_height,
    unsigned int window_width_min,
    unsigned int window_height_min,
    char* window_title,
    char* window_pictogram_title,
    Pixmap pixmap
)
{
    XTextProperty window_name, pictogram_name;

    if ( !XStringListToTextProperty (&window_title, 1, &window_name) ||
            !XStringListToTextProperty (&window_pictogram_title, 1, &pictogram_name) )
            {
                printf("Low memory.");
                return -1;
            }

    XSizeHints size_hints;

    size_hints.flags = PPosition | PSize | PMinSize;
    size_hints.min_height = window_height_min;
    size_hints.min_width = window_width_min; 

    XWMHints wm_hints;

    wm_hints.flags = InputHint | StateHint | IconPixmapHint;
    wm_hints.input = True;
    wm_hints.initial_state = NormalState;
    wm_hints.icon_pixmap = pixmap;

    XClassHint class_hints;

    class_hints.res_name = window_title;
    class_hints.res_class = class;

    XSetWMProperties(
        display,
        window,
        &window_name,
        &pictogram_name,
        argv,
        argc,
        &size_hints,
        &wm_hints,
        &class_hints
    );
}

int main(int argc, char** argv)
{
    Display* display;

    if ( (display = XOpenDisplay( NULL )) == NULL){
        printf("Cannot connect to X-Server");
        return -1;
    } 

    int screen_number = DefaultScreen (display);

    Window window = XCreateSimpleWindow(
        display, 
        RootWindow( display, screen_number),
        X,
        Y,
        WIDTH,
        HEIGHT,
        BORDER,
        BlackPixel( display, screen_number ),
        WhitePixel( display, screen_number )
    );

    SetWindowManagerHints(
        display,
        CLASS,
        argv,
        argc,
        window,
        X,
        Y,
        WIDTH,
        HEIGHT,
        WIDTH - 100,
        HEIGHT - 80,
        TITLE,
        ICON_TITLE,
        0
    );

    XSelectInput (display, window, ExposureMask | KeyPressMask);

    XMapWindow(display, window);

    XEvent event_report;
    GC graphics_context;

    while (1)
    {
        XNextEvent( display, &event_report );

        switch ( event_report.type )
        {
            case Expose:
                if (event_report.xexpose.count != 0)
                    break;

                graphics_context = XCreateGC( display, window, 0, NULL);

                XSetForeground(display, graphics_context, BlackPixel(display, 0));

                XDrawString(display, window, graphics_context, 20, 50, 
                    "Hello, World", strlen("Hello, World") );

                XFreeGC(display, graphics_context);

                XFlush(display);

                break;
            
            case KeyPress:
                XCloseDisplay(display);
        }
    }
}