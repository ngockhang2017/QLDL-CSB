#ifndef DIALOG_THEMTAIKHOAN_H
#define DIALOG_THEMTAIKHOAN_H

#include <QDialog>
#include<QtSql/QSql>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QString>
#include<QMessageBox>
#include<QFileDialog>

namespace Ui {
class Dialog_ThemTaikhoan;
}

class Dialog_ThemTaikhoan : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ThemTaikhoan(QWidget *parent = nullptr);
    ~Dialog_ThemTaikhoan();

    bool ok;
    QSqlDatabase db;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog_ThemTaikhoan *ui;
};

#endif // DIALOG_THEMTAIKHOAN_H
