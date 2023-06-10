#ifndef ADDNEW_H
#define ADDNEW_H

#include <QDialog>

namespace Ui {
class AddNew;
}

class AddNew : public QDialog
{
    Q_OBJECT

signals:
    void data(QList<QVariant> row);


public:
    explicit AddNew(QWidget *parent = nullptr);
    ~AddNew();

private slots:
    void on_AddButton_clicked();

private:
    Ui::AddNew *ui;
};

#endif // ADDNEW_H
