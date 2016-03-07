#include <gtk/gtk.h>
#include "TextFileProcessor.h"

static void startTransform (GtkWidget *widget, gpointer   data) {
    TextFileProcessor* transformer = new TextFileProcessor("mongodb://127.0.0.1/ClimaPIEAES?","ClimaPIEAES","JAZMIN","../../data/Jazmin/20150201.txt");
    transformer->transformTextFile();
    g_print ("Info saved\n");
}

int main(int argc, char **argv) {
    GtkWidget *window;
    GtkWidget *button;


    gtk_init (&argc, &argv);
    /* create a new window, and set its title */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Weather Data Processor");

    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    /* Sets the border width of the window. */
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    /* Creates a new button with the label "Hello World". */
    button = gtk_button_new_with_label ("Transform and insert INFO");

     /* When the button receives the "clicked" signal, it will call the
      * function print_hello() passing it NULL as its argument.
      *
      * The print_hello() function is defined above.
      */
    g_signal_connect (button, "clicked", G_CALLBACK (startTransform), NULL);

    /* The g_signal_connect_swapped() function will connect the "clicked" signal
   * of the button to the gtk_widget_destroy() function; instead of calling it
   * using the button as its argument, it will swap it with the user data
   * argument. This will cause the window to be destroyed by calling
   * gtk_widget_destroy() on the window.
   */
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

    /* This packs the button into the window. A GtkWindow inherits from GtkBin,
   * which is a special container that can only have one child
   */
    gtk_container_add (GTK_CONTAINER (window), button);

    /* The final step is to display this newly created widget... */
    gtk_widget_show (button);
    gtk_widget_show (window);
    gtk_main ();

    return 0;
}
