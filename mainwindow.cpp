#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include "additemdialog.h"
#include <QMainWindow>
#include <QDialog>
#include <QtGui>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    _model = new ExampleModel();
    _proxy = new MyProxy(this);
    _proxy->setSourceModel(_model);

    ui->tableView->setSortingEnabled(true);
    ui->tableView->setModel(_proxy);
    ui->listView->setModel(_proxy);
    ui->listView->setModelColumn(0);
    QObject::connect(ui->actionFile, &QAction::triggered, this, &MainWindow::openFile);


}

void MainWindow::openFile()
{
    if (_currentFolder.isEmpty())
    {
        _currentFolder = ".";
    }
    QString fileName = QFileDialog::getOpenFileName(this, "Open data file", _currentFolder, "*.csv");

    _currentFolder = fileName;


    if (!_model->reloadDataFromFile(fileName))
    {
        QMessageBox::warning(this, "Error", "Cannot open file", QMessageBox::Ok);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_clicked()
{
    AddItemDialog dilog;
    if (dilog.exec())
    {
        QList<QVariant> dataRow = dilog.getDataRow();
        _model->appendRow(dataRow);
    }
}



void MainWindow::on_Remove_clicked()
{
    QModelIndex removeIndex = ui->tableView->currentIndex();

    int rowToRemove = removeIndex.row();
    if (!_model->removeRow(rowToRemove))
    {
        QMessageBox::warning(this, tr("Error"), tr("Incorrect index (doesn't exist)"), QMessageBox::Ok);
    }
}


void MainWindow::on_Save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"), tr("backup"),
                                                    tr("CSV files (*.csv);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Cannot open file"), file.errorString());
            qCritical() << file.errorString();
            return;
        } else {
            QTextStream out(&file);
            QModelIndex index;
            QString oneItem;
            for (int i = 0; i < _model->rowCount(); ++i) {
                for (int j = 0; j < _model->columnCount(); ++j) {
                    oneItem = _model->data(_model->index(i, j)).toString();
                    if (oneItem.contains(','))
                    {
                        out << '\"';
                        out << oneItem;
                        out << '\"';
                    }
                    else
                        out << oneItem;
                    if (j != _model->columnCount() - 1)
                        out << ",";
                }
                out << "\n";
            }
            file.close();
        }

    }
}

void MainWindow::showAboutDialog()
{
    _aboutDialog->show();
}




void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    int row = index.row();
    QModelIndex indexInModel = _proxy->index(row, 0);
    ui->label_9->setText(_proxy->data(indexInModel).toString());

    indexInModel = _proxy->index(row, 1);
    ui->label_10->setText(_proxy->data(indexInModel).toString());

    indexInModel = _proxy->index(row, 2);
    ui->label_11->setText(_proxy->data(indexInModel).toString());

    indexInModel = _proxy->index(row, 3);
    ui->label_12->setText(_proxy->data(indexInModel).toString());

    indexInModel = _proxy->index(row, 4);
    ui->label_13->setText(_proxy->data(indexInModel).toString());

    indexInModel = _proxy->index(row, 5);
    ui->label_14->setText(_proxy->data(indexInModel).toString());


}

void MainWindow::on_AboutpushButton_clicked()
{
    QDialog* aboutDialog = new QDialog(this);
    aboutDialog->setWindowTitle("About My App");

    QLabel* logoLabel = new QLabel(aboutDialog);



    QImage logoImage(128, 128, QImage::Format_RGB32);
    logoImage.fill(Qt::white);

    QPainter painter(&logoImage);
    painter.setPen(Qt::black);


    painter.drawEllipse(QPoint(64, 64), 50, 50);

    painter.drawEllipse(QPoint(64, 64), 40, 40);

    painter.drawEllipse(QPoint(64, 64), 30, 30);

    painter.drawEllipse(QPoint(64, 64), 20, 20);

    painter.drawEllipse(QPoint(64, 64), 10, 10);

    painter.drawPoint(QPoint(64, 64));

    painter.end();

    logoLabel->setPixmap(QPixmap::fromImage(logoImage));

    QLabel* studentLabel = new QLabel("Student №1646", aboutDialog);
    studentLabel->setAlignment(Qt::AlignHCenter);
    QVBoxLayout* layout = new QVBoxLayout(aboutDialog);
    layout->addWidget(logoLabel);
    layout->addWidget(studentLabel);

    aboutDialog->exec();
}





