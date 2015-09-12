/*
    Temperature Converter

    This is a program used to convert temperatures between Farenheit and Celcius.

    Compile command:
        gcc `pkg-config --cflags gtk+-3.0` -o temp_converter temp_converter.c `pkg-config --libs gtk+-3.0`

    License:
        MIT
*/

// Library imports
#include <gtk/gtk.h>

// Function declarations
int main(int argc, char **argv);
static void activate(GtkApplication *app, gpointer user_data);
//void f_to_c(GtkApplication *app, gpointer user_data);
//void f_to_c(GtkWidget *temp_entry, GtkWidget *output_temp_label);
void f_to_c(GtkWidget *f_to_c_button, GtkWidget *temp_entry);

// Main function
int main(int argc, char **argv) {
    GtkApplication *app;	// Pointer to the application
    int status;	// Return status of the application

    // Move to the next line of the terminal
    g_print("\n");

    // Create a new application
    app = gtk_application_new("io.github.excaliburzero.temp_converter", G_APPLICATION_FLAGS_NONE);

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
    /*
        Declare the widgets used in application
    */

    // Windows
    GtkWidget *window;	// The main window of the application

    // Boxes
    GtkWidget *main_box;    // The box which contains the main grid

    // Grids
    GtkWidget *main_grid;   // The grid that contains the various widgets in the window

    // Labels
    GtkWidget *enter_temp_label;    // The label that tells the user to enter a temperature
    GtkWidget *output_temp_label;   // The label that outputs to the user the converted temperature

    // Entry
    GtkWidget *temp_entry;  // The entry where the user enters the temperature they want to convert

    // Buttons
    GtkWidget *f_to_c_button; // Button to convert Farenheit to Celcius
    GtkWidget *c_to_f_button; // Button to convert Celcius to Farenheit

    /*
    	Create the main window of the application
    */

    // Create the main window of the application and store it in window
    window = gtk_application_window_new(app);

    // Set the title of the main window
    gtk_window_set_title(GTK_WINDOW(window), "Temperature Converter");

    // Set the default size of the window
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);

    /*
        Create the boxes and grids
    */

    // Create the main box and store it in main_box
    main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);

    // Create the main grid and store it in main_grid
    main_grid = gtk_grid_new();

    // Add the main box to the main window
    gtk_container_add(GTK_CONTAINER(window), main_box);

    // Add the main grid to the main box
    gtk_container_add(GTK_CONTAINER(main_box), main_grid);

    /*
        Create the labels and entries
    */

    // Create the label that tells the user to enter a temperature and store it in enter_temp_label
    enter_temp_label = gtk_label_new("Enter a temperature:");

    // Create the label that outputs to the user the converted temperature and store it in output_temp_label
    output_temp_label = gtk_label_new(NULL);

    // Create the entry where the user enters the temperature they want to convert and store it in temp_entry
    temp_entry = gtk_entry_new();

    // Add the label enter_temp_label to the grid
    gtk_grid_attach(GTK_GRID(main_grid), enter_temp_label, 0, 0, 1, 1);

    // Add the label output_temp_label to the grid
    gtk_grid_attach(GTK_GRID(main_grid), output_temp_label, 2, 0, 2, 1);

    // Add the entry temp_entry to the grid
    gtk_grid_attach(GTK_GRID(main_grid), temp_entry, 1, 0, 1, 1);

    /*
        Create the buttons
    */

    // Create the button that converts F to C and store it in f_to_c_button
    f_to_c_button = gtk_button_new_with_label("F to C");

    // Create the button that converts C to F and store it in c_to_f_button
    c_to_f_button = gtk_button_new_with_label("C to F");

    // Add the button f_to_c_button to the grid
    gtk_grid_attach(GTK_GRID(main_grid), f_to_c_button, 0, 1, 1, 1);

    // Add the button c_to_f_button to the grid
    gtk_grid_attach(GTK_GRID(main_grid), c_to_f_button, 1, 1, 1, 1);

    // Set the function to be run when the f_to_c_button is clicked
    g_signal_connect(f_to_c_button, "clicked", G_CALLBACK(f_to_c), temp_entry);

    /*
        Show the main window
    */

    gtk_widget_show_all(window);
}

// Function to convert the entered temperature from Farenheit to Celcius and display the output
void f_to_c(GtkWidget *f_to_c_button, GtkWidget *temp_entry) {
    gdouble entered_temp;   // The temperature that the user entered
    gdouble celcius_temp;   // The temperature converted to Celcius

    // Get the user entered temperature from the entry
    entered_temp = g_ascii_strtod(gtk_entry_get_text(GTK_ENTRY(temp_entry)), NULL);

    // Calculate the entered temperature in Celcius
    celcius_temp = (entered_temp - 32.0) * (5.0 / 9.0);

    // Output the temperature in Celcius
    g_print("%G\n", celcius_temp);
}
