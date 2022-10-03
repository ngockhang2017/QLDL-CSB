#ifndef DIALOG_SUAXOA_H
#define DIALOG_SUAXOA_H

#include <QDialog>
#include <QRadioButton>
#include<QDebug>

#include<QtSql/QSql>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QString>
#include<QMessageBox>
#include<QFileDialog>

namespace Ui {
class Dialog_SuaXoa;
}

class Dialog_SuaXoa : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_SuaXoa(QWidget *parent = nullptr);
    ~Dialog_SuaXoa();

    bool ok;
    QSqlDatabase db;
    int ID_DoubleCLick;

    QString TenND_Update;
    QString TenDN_Update;
    QString MK_Update;
    int Capdo;

    void Update();

private slots:
    void on_pushButton_suaTK_clicked();

    void on_pushButton_CapnhatTK_clicked();

    void on_pushButton_XoaTK_clicked();

private:
    Ui::Dialog_SuaXoa *ui;

};

#endif // DIALOG_SUAXOA_H
