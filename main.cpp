#include "clipboard_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClipboardWidget w;
    w.show();
    return a.exec();
}
