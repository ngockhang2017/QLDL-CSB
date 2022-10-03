#ifndef CUUHO_H
#define CUUHO_H

#include <QMainWindow>

#include<QtSql/QSql>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QString>
#include<QMessageBox>
#include<QFileDialog>

#include"dialog_xuatfile.h"
#include <QAxObject>
#include<QFile>


namespace Ui {
class CuuHo;
}

class CuuHo : public QMainWindow
{
    Q_OBJECT

public:
    explicit CuuHo(QWidget *parent = nullptr);
    ~CuuHo();
    bool ok;
    QSqlDatabase db;
    int ID_DoubleCLick;

private slots:
    void on_pushButton_Cuuho_Tatca_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void SectionDoubleClick(int row, int column);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::CuuHo *ui;
    Dialog_XuatFile *mdialog_XuatFile;
};

#endif // CUUHO_H
