/*
    Hello World

    This is a quick program made to create a simple window that includes a
    button, which when pressed prints "Hello World" to the terminal.

    This program is roughly based off of the GTK+ tutorial located at:
        https://developer.gnome.org/gtk3/stable/gtk-getting-started.html

    Compile command:
        gcc `pkg-config --cflags gtk+-3.0` -o hello_world hello_world.c `pkg-config --libs gtk+-3.0`

    License:
        MIT
*/

// Library imports
#include <gtk/gtk.h>

// Function declarations
int main(int argc, char **argv);
static void activate(GtkApplication *app, gpointer user_data);
void print_hello(void);

// Main function
int main(int argc, char **argv) {
    GtkApplication *app;	// Pointer to the application
    int status;	// Return status of the application

    // Move to the next line of the terminal
    g_print("\n");

    // Create a new application
    app = gtk_application_new("io.github.excaliburzero", G_APPLICATION_FLAGS_NONE);

    // Define the function to be run once the application is run
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Run the application
    status = g_application_run(G_APPLICATION(app), argc, argv);

    // Once the application has finished, remove it from the memory
    g_object_unref(app);

    // Return the return status of the application
    return status;
}

// Function to activate the program and create the main window
static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;	// The main window of the application
    GtkWidget *hello_button_box;	// A box to contain the hello world button
    GtkWidget *hello_button;	// The hello world button

    /*
    	Create the main window of the application
    */

    // Create the main window of the application and store it in window
    window = gtk_application_window_new(app);

    // Set the title of the main window
    gtk_window_set_title(GTK_WINDOW(window), "Hello World Test");

    // Set the default size of the window
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);

    /*
    	Create the hello world button and box
    */

    // Create the hello world button box and store it in hello_button_box
    hello_button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);

    // Add the hello world button box to the main window
    gtk_container_add(GTK_CONTAINER(window), hello_button_box);

    // Create the hello world button and store it in hello_button
    hello_button = gtk_button_new_with_label("Hello World");

    // Set the function to be run when the helo world button in clicked
    g_signal_connect(hello_button, "clicked", G_CALLBACK(print_hello), NULL);

    // Add the hello world button to the main window
    gtk_container_add(GTK_CONTAINER(hello_button_box), hello_button);

    // Show the main window
    gtk_widget_show_all(window);
}

// Function to print "Hello World" to the terminal whenever the hello world
// button is pressed
void print_hello(void) {
    // Print "Hello World" to the terminal
    g_print("Hello World\n");
}
