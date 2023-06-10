#include "additemdialog.h"
#include "ui_additemdialog.h"

AddItemDialog::AddItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemDialog)
{
    ui->setupUi(this);
}

AddItemDialog::~AddItemDialog()
{
    delete ui;
}

QList<QVariant> AddItemDialog::getDataRow()
{
    QList<QVariant> dataRow;
    dataRow.append(ui->NamelineEdit->text());
    dataRow.append(ui->PlatformlineEdit_2->text());
    dataRow.append(ui->YearlineEdit_3->text().toInt());
    dataRow.append(ui->GenrelineEdit_4->text());
    dataRow.append(ui->PublisherlineEdit_5->text());
    dataRow.append(ui->GloballineEdit_6->text().toDouble());

    return dataRow;
}
