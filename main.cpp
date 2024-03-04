#include <QApplication>
#include "loginwindow.h" // Include your main window header

class MyApp : public QApplication {
public:
    MyApp(int &argc, char **argv) : QApplication(argc, argv) {}

    int exec()  {
        // Create your main window instance
        LoginWindow w;
        w.show(); // Show the main window

        // Enter the event loop
        return QApplication::exec();
    }
};

int main(int argc, char *argv[]) {
    MyApp a(argc, argv); // Initialize your custom QApplication subclass

    // Run the application
    return a.exec();
}
