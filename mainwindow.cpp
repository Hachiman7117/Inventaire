#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reserverelement.h"
#include <QDebug>
#include <QtXml>
//#include <QtFile>


void MainWindow::readXMLFile(){
    QDomDocument studentsXML;
    QFile xmlFile("/home/davidson/xmlSample.xml");
    if (!xmlFile.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
    }
    studentsXML.setContent(&xmlFile);
    xmlFile.close();

    QDomElement root = studentsXML.documentElement();
    QDomElement node = root.firstChild().toElement();

    QString datas = "";

    while(node.isNull() == false)
    {
        qDebug() << node.tagName();
        if(node.tagName() == "student"){
            while(!node.isNull()){
                QString id = node.attribute("id","0");
                QString name = node.attribute("name","name");
                QString number = node.attribute("number","number");

                datas.append(id).append(" - ").append(name).append(" - ").append(number).append("\n");
                node = node.nextSibling().toElement();
            }
        }
        node = node.nextSibling().toElement();
    }
    //ui->txtLoadedXmlContent->setPlainText(datas);

    qDebug() << datas;
}

void MainWindow::writeXMLFile(){


    QDomDocument document;

    //make the root element
    QDomElement root = document.createElement("StudentList");
    //add it to document
    document.appendChild(root);

    QDomElement student = document.createElement("student");
    student.setAttribute("id", "1");
    student.setAttribute("name", "Burak");
    student.setAttribute("number", "1111");
    root.appendChild(student);

    student = document.createElement("student");
    student.setAttribute("id", "2");
    student.setAttribute("name", "Hamdi");
    student.setAttribute("number", "2222");
    root.appendChild(student);

    student = document.createElement("student");
    student.setAttribute("id", "3");
    student.setAttribute("name", "TUFAN");
    student.setAttribute("number", "33333");
    root.appendChild(student);

    student = document.createElement("student");
    student.setAttribute("id", "4");
    student.setAttribute("name", "Thecodeprogram");
    student.setAttribute("number", "4444");
    root.appendChild(student);


    QFile file( "/home/davidson/xmlSample.xml" );
    if(file.open(QFile::WriteOnly | QFile::Text)){
        QTextStream in(&file);
        in<<document.toString();
        file.flush();
        file.close();
        qDebug()<<"finished.";
    }
    else qDebug()<<"file open failed.";

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    writeXMLFile();

//    readXMLFile();

    connect(r, &reserverElement::buttonBoxAccepted, this, &MainWindow::operationReserverFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_reserver_clicked()
{
    r->show();

}

void MainWindow::operationReserverFinished(){
    qDebug() << "Operation Finished" << ui->tableWidget->rowCount() << ui->tableWidget->columnCount() ;
//    QTableWidgetItem *item ;
//    if(!item) {
//        item = new QTableWidgetItem();
//        ui->tableWidget->setItem(i          , j, item);
//    }
//    item->setText("1");
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            QTableWidgetItem *item = ui->tableWidget->item(i, j);
            if(!item) {
                item = new QTableWidgetItem();
                ui->tableWidget->setItem(i, j, item);
                item->setFlags(item->flags()   ^ Qt::ItemIsEditable);
            }

        }
    }
}

