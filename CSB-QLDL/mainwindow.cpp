#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrl>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//    this->showFullScreen();
//Map loading
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/new/prefix1/map.qml")));
    ui->quickWidget->show();

//Connect to Databse MySql (db_csb)
  /*  QSqlDatabase db =  QSqlDatabase::addDatabase("QODBC", "my_conn");
    QString inpSqlServer = "127.0.0.1";
    QString dbName = "db_csb";
    QString connString = QString("Driver={MySQL ODBC 8.0 Unicode Driver};Server=%1;DATABASE=%2;Trusted_Connection=Yes;")
            .arg(inpSqlServer).arg(dbName); //the argument replace the %1 and %2
    db.setDatabaseName(connString);
    db.setUserName("root");
    db.setPassword("ngockhang@mta");
    db.setHostName("localhost");
    db.setPort(3306);
    ok = db.open();

    qDebug() << "MySQL connection status: " << db.open();
    qDebug() << "Error = " << db.lastError().text();*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mWindowCuuHo = new CuuHo();
    mWindowCuuHo->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    mWindowViPham = new ViPham();
    mWindowViPham->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    mWindowUngPho = new UngPho();
    mWindowUngPho->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    mWindowKhac = new Khac();
    mWindowKhac->show();
}
