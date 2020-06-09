#include <QGuiApplication>
#include "MainWindow.h"

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    MainWindow window{QStringLiteral("qrc:/main.qml")};
    return app.exec();
}
