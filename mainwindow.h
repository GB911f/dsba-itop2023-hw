#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "aboutDialog.h"
#include "myproxy.h"
#include "examplemodel.h"
#include "aboutdialog.h"
#include <QMainWindow>
#include <QDialog>
#include <QtGui>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Save_clicked();

    void showAboutDialog();

    void on_listView_clicked(const QModelIndex &index);

    void on_AboutpushButton_clicked();

private:
    void openFile();
    MyProxy* _proxy;
    Ui::MainWindow *ui;
    QString _currentFolder;
    ExampleModel* _model;
    AboutDialog* _aboutDialog;
};
#endif // MAINWINDOW_H
