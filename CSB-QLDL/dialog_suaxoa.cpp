#include "dialog_suaxoa.h"
#include "ui_dialog_suaxoa.h"

Dialog_SuaXoa::Dialog_SuaXoa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_SuaXoa)
{
    ui->setupUi(this);
}

Dialog_SuaXoa::~Dialog_SuaXoa()
{
    delete ui;
}

void Dialog_SuaXoa::Update()
{
    ui->lineEdit_TenND->setText(this->TenND_Update);
    ui->lineEdit_TenDN->setText(this->TenDN_Update);
    ui->lineEdit_MK->setText(this->MK_Update);

    ui->pushButton_suaTK->setDisabled(false);
    ui->pushButton_CapnhatTK->setDisabled(true);
    ui->pushButton_XoaTK->setDisabled(false);

    if(this->Capdo == 1)
    {
      ui->radioButton->setChecked(true);
      ui->radioButton_2->setChecked(false);
      ui->radioButton_3->setChecked(false);
    }
    else if(this->Capdo == 2)
    {
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(true);
        ui->radioButton_3->setChecked(false);
    }
    else if(this->Capdo == 3)
    {
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(false);
        ui->radioButton_3->setChecked(true);
    }

    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        le->setDisabled(true);
    }
    foreach(QRadioButton* ra, findChildren<QRadioButton*>())
    {
        ra->setDisabled(true);
    }
}

void Dialog_SuaXoa::on_pushButton_suaTK_clicked()  //SỬA THÔNG TIN TÀI KHOẢN
{
    ui->pushButton_suaTK->setDisabled(true);
    ui->pushButton_CapnhatTK->setDisabled(false);
    ui->pushButton_XoaTK->setDisabled(true);

    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        le->setDisabled(false);
    }
    foreach(QRadioButton* ra, findChildren<QRadioButton*>())
    {
        ra->setDisabled(false);
    }
}

void Dialog_SuaXoa::on_pushButton_CapnhatTK_clicked()  //CẬP NHẬT THÔNG TIN TÀI KHOẢN
{
    //Lấy ra các giá trị đã được sửa từ ui
    int taikhoan_id = this->ID_DoubleCLick;
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

    //Connect to Databse MySql (db_csb)
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


    if(this->ok)
    {
        QSqlQuery qry(this->db);

        qry.prepare("UPDATE tbl_taikhoan SET taikhoan_tennguoidung=:taikhoan_tennguoidung, taikhoan_tendangnhap=:taikhoan_tendangnhap, ttaikhoan_matkhau=:ttaikhoan_matkhau, taikhoan_quyentruycap=:taikhoan_quyentruycap "
                          "WHERE taikhoan_id=:taikhoan_id");


        qry.bindValue(":taikhoan_tennguoidung", taikhoan_tennguoidung);
        qry.bindValue(":taikhoan_tendangnhap", taikhoan_tendangnhap);
        qry.bindValue(":ttaikhoan_matkhau", ttaikhoan_matkhau);
        qry.bindValue(":taikhoan_quyentruycap", taikhoan_quyentruycap);

        qry.bindValue(":taikhoan_id", taikhoan_id);

        if(qry.exec())
        {
            QMessageBox::information(this, "Thông báo", "Cập nhật thông tin thành công!");
//            foreach(QLineEdit* le, findChildren<QLineEdit*>())
//            {
//               le->clear();
//               le->setDisabled(true);
//            }
//            ui->pushButton_suaTK->setDisabled(true);
//            ui->pushButton_CapnhatTK->setDisabled(true);
//            ui->pushButton_XoaTK->setDisabled(true);
            this->close();
        }
        else
        {
            QMessageBox::warning(this, "Thông báo", "Cập nhật thông tin không thành công. Xin hãy thử lại!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Database connect Fail!");
    }
}

void Dialog_SuaXoa::on_pushButton_XoaTK_clicked()  //XÓA TÀI KHOẢN
{
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

    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("DELETE FROM tbl_taikhoan WHERE taikhoan_id=:taikhoan_id");
        qry.bindValue(":taikhoan_id", this->ID_DoubleCLick);
//        qDebug()<<"CLICK: " << this->ID_DoubleCLick;

        if(qry.exec())
        {
            QMessageBox::information(this, "Thông báo", "Tài khoản đã được xóa!");
           this->close();
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }
}
