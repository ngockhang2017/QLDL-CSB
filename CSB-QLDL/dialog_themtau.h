#ifndef DIALOG_THEMTAU_H
#define DIALOG_THEMTAU_H

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
class Dialog_ThemTau;
}

class Dialog_ThemTau : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ThemTau(QWidget *parent = nullptr);
    ~Dialog_ThemTau();
    bool ok;
    QSqlDatabase db;
    int ID_DoubleCLick;

    QString Sohieu_update, Tengoi_update, mmsi_update, Ghichu_update;
    void Update_tau();

private slots:
    void on_pushButton_luutau_clicked();

    void on_pushButton_capnhat_clicked();

    void on_pushButton_xoa_clicked();

    void on_pushButton_sua_clicked();

    void on_pushButton_themtau_clicked();

private:
    Ui::Dialog_ThemTau *ui;
};

#endif // DIALOG_THEMTAU_H
