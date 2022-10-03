#ifndef KHAC_H
#define KHAC_H

#include <QMainWindow>
#include<QtSql/QSql>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QString>
#include<QMessageBox>
#include<QFileDialog>
#include "dialog_themtaikhoan.h"
#include "dialog_suaxoa.h"
#include "dialog_themtau.h"


namespace Ui {
class Khac;
}

class Khac : public QMainWindow
{
    Q_OBJECT

public:
    explicit Khac(QWidget *parent = nullptr);
    ~Khac();
    bool ok;
    QSqlDatabase db;
    int ID_DoubleCLick;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void SectionDoubleClick(int row, int column);
    void SectionDoubleClick_2(int row, int column);

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Khac *ui;
    Dialog_ThemTaikhoan *mdialog_themtaikhoan;
    Dialog_SuaXoa *mdialog_suaxoa;
    Dialog_ThemTau *mdialog_themtau;
};

#endif // KHAC_H
