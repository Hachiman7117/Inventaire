#include "reserverelement.h"
#include "ui_reserverelement.h"
#include <QDebug>

reserverElement::reserverElement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reserverElement)
{
    ui->setupUi(this);

}

reserverElement::~reserverElement()
{
    delete ui;
}

void reserverElement::on_buttonBox_accepted()
{
//    qDebug() << "Nom : " << _nom;
//    qDebug() << "Debut : " << _debut;
//    qDebug() << "Fin : " << _fin;
    qDebug()<<"New Element";
    emit buttonBoxAccepted();



}


void reserverElement::on_nomInput_textChanged()
{
    _nom = ui->nomInput->toPlainText();
}


void reserverElement::on_debutInput_textChanged()
{
        _debut = ui->debutInput->toPlainText();
}

void reserverElement::on_finInput_textChanged()
{
        _fin = ui->finInput->toPlainText();
}
