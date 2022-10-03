#include "dialog_themtaikhoan.h"
#include "ui_dialog_themtaikhoan.h"

Dialog_ThemTaikhoan::Dialog_ThemTaikhoan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ThemTaikhoan)
{
    ui->setupUi(this);

    this->db =  QSqlDatabase::addDatabase("QODBC", "my_conn");
    QString inpSqlServer = "127.0.0.1";
    QString dbName = "db_csb";
    QString connString = QString("Driver={MySQL ODBC 8.0 Unicode Driver};Server=%1;DATABASE=%2;Trusted_Connection=Yes;")
            .arg(inpSqlServer).arg(dbName); //the argument replace the %1 and %2
    db.setDatabaseName(connString);
    db.setUserName("root");
    db.setPassword("ngockhang@mta");
    db.setHostName("localhost");
    db.setPort(3306);
    this->ok = db.open();
}

Dialog_ThemTaikhoan::~Dialog_ThemTaikhoan()
{
    delete ui;
}

void Dialog_ThemTaikhoan::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog_ThemTaikhoan::on_pushButton_clicked()  //  THÊM TẢI KHOẢN MỚI
{
    int taikhoan_id;
    QString taikhoan_tennguoidung = ui->lineEdit_TenND->text();
    QString taikhoan_tendangnhap = ui->lineEdit_TenDN->text();
    QString ttaikhoan_matkhau = ui->lineEdit_MK->text();
    int taikhoan_quyentruycap;
    if(ui->radioButton->isChecked())
    {
        taikhoan_quyentruycap = 1;
    }
    else if(ui->radioButton_2->isChecked())
    {
        taikhoan_quyentruycap = 2;
    }
    else if(ui->radioButton_3->isChecked())
    {
        taikhoan_quyentruycap = 3;
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Chưa cấp quyền truy cập cho tài khoản. Hãy thử lại!");
    }


    //=====================================TEST INSERT DATABASE
//    this->db =  QSqlDatabase::addDatabase("QODBC", "my_conn");
//    QString inpSqlServer = "127.0.0.1";
//    QString dbName = "db_csb";
//    QString connString = QString("Driver={MySQL ODBC 8.0 Unicode Driver};Server=%1;DATABASE=%2;Trusted_Connection=Yes;")
//            .arg(inpSqlServer).arg(dbName); //the argument replace the %1 and %2
//    db.setDatabaseName(connString);
//    db.setUserName("root");
//    db.setPassword("ngockhang@mta");
//    db.setHostName("localhost");
//    db.setPort(3306);
//    this->ok = db.open();

    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("INSERT INTO tbl_taikhoan ( taikhoan_tennguoidung, taikhoan_tendangnhap, ttaikhoan_matkhau, taikhoan_quyentruycap) "
                          "VALUES (:taikhoan_tennguoidung, :taikhoan_tendangnhap, :ttaikhoan_matkhau, :taikhoan_quyentruycap)");
      //  qry.bindValue(":id", 50);
        qry.bindValue(":taikhoan_tennguoidung", taikhoan_tennguoidung);
        qry.bindValue(":taikhoan_tendangnhap", taikhoan_tendangnhap);
        qry.bindValue(":ttaikhoan_matkhau", ttaikhoan_matkhau);
        qry.bindValue(":taikhoan_quyentruycap", taikhoan_quyentruycap);

        taikhoan_id = -1;
        if(qry.exec())
        {
            if(qry.lastInsertId().isValid())
            {
                taikhoan_id = qry.lastInsertId().toInt();
            }
            QMessageBox::information(this, "report", "Tài khoản được cấp thành công");
            //clear all text
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
               le->clear();
            }
        }
        else
        {
            QMessageBox::warning(this, "Warning", "Lưu không thành công. Vui lòng thử lại!");
        }

    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại");
    }
}
