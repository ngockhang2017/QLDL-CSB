#ifndef UNGPHO_H
#define UNGPHO_H

#include <QMainWindow>

#include<QtSql/QSql>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QString>
#include<QMessageBox>

#include"dialog_xuatfile.h"
#include<QAxObject>
#include<QFile>
#include<QFileDialog>

namespace Ui {
class UngPho;
}

class UngPho : public QMainWindow
{
    Q_OBJECT

public:
    explicit UngPho(QWidget *parent = nullptr);
    ~UngPho();
    bool ok;
    QSqlDatabase db;
    int ID_DoubleCLick;


private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void SectionDoubleClick(int row, int column);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::UngPho *ui;
    Dialog_XuatFile *mdialog_XuatFile;
};

#endif // UNGPHO_H
