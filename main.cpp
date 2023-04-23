#include "taquin.h"

#include <QApplication>
#include<QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    if (QLocale::system().name() == "fr_FR") {
        translator.load(QDir::currentPath()+"/traduction.qm");
    }
    a.installTranslator(&translator);
    taquin w;
    w.show();
    return a.exec();
}

