#include "addnew.h"
#include "ui_addnew.h"

AddNew::AddNew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNew)
{
    ui->setupUi(this);
}

AddNew::~AddNew()
{
    delete ui;
}



void AddNew::on_AddButton_clicked()
{
    QString Name = ui->NameEdit_2->text();
    QString Platform = ui->PlatformEdit_3->text();
    int Year =  ui->YearspinBox->value();
    QString Genre = ui->GenreEdit_5->text();
    QString Publisher = ui->PublisherEdit_6->text();
    QString x=ui->GlobalEdit_7->text();
    double Global_Sales=x.toDouble();
    QList<QVariant> line;
    line.append(Name);
    line.append(Platform);
    line.append(Year);
    line.append(Genre);
    line.append(Publisher);
    line.append(Global_Sales);
    emit data(line);
    QDialog::accept();


}

