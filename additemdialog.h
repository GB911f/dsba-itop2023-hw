#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include "customwidget.h"


namespace Ui {
class AddItemDialog;
}

class AddItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDialog(QWidget *parent = nullptr);
    ~AddItemDialog();

    QList<QVariant> getDataRow();

private:
    Ui::AddItemDialog *ui;
};

#endif // ADDITEMDIALOG_H
