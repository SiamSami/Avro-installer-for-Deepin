#include "avroinstaller.h"
#include <DApplication>
DWIDGET_USE_NAMESPACE
int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    AvroInstaller w;
    w.setWindowTitle("Avro installer for Deepin");
    w.setWindowIcon("/home/toor/test.png");
    w.show();

    return a.exec();
}
