#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reserverelement.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void writeXMLFile();
    void readXMLFile();

private slots:
    void operationReserverFinished();
    void on_reserver_clicked();

private:
    Ui::MainWindow *ui;
    reserverElement *r = new reserverElement();
};
#endif // MAINWINDOW_H
