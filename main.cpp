/*
 * Authors:
 *   Meysam Hamel
 *   Eric Miramontes
 * Assignment:
 *   A5 Stopwatch
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
