#ifndef RESERVERELEMENT_H
#define RESERVERELEMENT_H

#include <QDialog>

namespace Ui {
class reserverElement;
}

class reserverElement : public QDialog
{
    Q_OBJECT

public:
    explicit reserverElement(QWidget *parent = nullptr);
    ~reserverElement();

signals:
    void buttonBoxAccepted();

private slots:
    void on_buttonBox_accepted();

    void on_nomInput_textChanged();

    void on_debutInput_textChanged();

    void on_finInput_textChanged();

private:
    Ui::reserverElement *ui;
    QString _nom = "";
    QString _debut ="";
    QString _fin ="";
};

#endif // RESERVERELEMENT_H
