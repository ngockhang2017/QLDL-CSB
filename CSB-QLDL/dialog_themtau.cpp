#include "dialog_themtau.h"
#include "ui_dialog_themtau.h"

Dialog_ThemTau::Dialog_ThemTau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ThemTau)
{
    ui->setupUi(this);

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
}

Dialog_ThemTau::~Dialog_ThemTau()
{
    delete ui;
}

void Dialog_ThemTau::on_pushButton_luutau_clicked()  //Lưu thông tin tàu mới
{
    int tau_id;
    QString tau_sohieu = ui->lineEdit_SoHieu->text();
    QString tau_tengoi = ui->lineEdit_Tengoi->text();
    QString tau_MMSI = ui->lineEdit_mmsi->text();
    QString tau_ghichu = ui->lineEdit_Ghichu->text();

    //=====================================TEST INSERT DATABASE
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
        qry.prepare("INSERT INTO tbl_tau ( tau_sohieu, tau_tengoi, tau_MMSI, tau_ghichu) "
                          "VALUES (:tau_sohieu, :tau_tengoi, :tau_MMSI, :tau_ghichu)");
      //  qry.bindValue(":id", 50);
        qry.bindValue(":tau_sohieu", tau_sohieu);
        qry.bindValue(":tau_tengoi", tau_tengoi);
        qry.bindValue(":tau_MMSI", tau_MMSI);
        qry.bindValue(":tau_ghichu", tau_ghichu);

        tau_id = -1;
        if(qry.exec())
        {
            if(qry.lastInsertId().isValid())
            {
                tau_id = qry.lastInsertId().toInt();
            }
            QMessageBox::information(this, "report", "Thông tin tàu được thêm thành công");
            //clear all text
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
               le->clear();
               le->setDisabled(true);
            }

            ui->pushButton_themtau->setDisabled(false);
            ui->pushButton_luutau->setDisabled(true);
            ui->pushButton_sua->setDisabled(true);
            ui->pushButton_capnhat->setDisabled(true);
            ui->pushButton_xoa->setDisabled(true);

            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
                le->setDisabled(false);
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

void Dialog_ThemTau::Update_tau()
{
    ui->lineEdit_SoHieu->setText(this->Sohieu_update);
    ui->lineEdit_Tengoi->setText(this->Tengoi_update);
    ui->lineEdit_mmsi->setText(this->mmsi_update);
    ui->lineEdit_Ghichu->setText(this->Ghichu_update);

    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
       le->setDisabled(true);
    }

    ui->pushButton_themtau->setDisabled(true);
    ui->pushButton_luutau->setDisabled(true);
    ui->pushButton_sua->setDisabled(false);
    ui->pushButton_capnhat->setDisabled(true);
    ui->pushButton_xoa->setDisabled(false);
}

void Dialog_ThemTau::on_pushButton_capnhat_clicked()  //CẬP NHẬT TÀU
{

    //Lấy ra các giá trị đã được sửa từ ui
    int tau_id = this->ID_DoubleCLick;
    QString tau_sohieu = ui->lineEdit_SoHieu->text();
    QString tau_tengoi = ui->lineEdit_Tengoi->text();
    QString tau_MMSI = ui->lineEdit_mmsi->text();
    QString tau_ghichu = ui->lineEdit_Ghichu->text();

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

        qry.prepare("UPDATE tbl_tau SET tau_sohieu=:tau_sohieu, tau_tengoi=:tau_tengoi, tau_MMSI=:tau_MMSI, tau_ghichu=:tau_ghichu "
                          "WHERE tau_id=:tau_id");


        qry.bindValue(":tau_sohieu", tau_sohieu);
        qry.bindValue(":tau_tengoi", tau_tengoi);
        qry.bindValue(":tau_MMSI", tau_MMSI);
        qry.bindValue(":tau_ghichu", tau_ghichu);

        qry.bindValue(":tau_id", tau_id);

        if(qry.exec())
        {
            QMessageBox::information(this, "Thông báo", "Cập nhật thông tin thành công!");
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
               le->clear();
               le->setDisabled(true);
            }

            ui->pushButton_themtau->setDisabled(false);
            ui->pushButton_luutau->setDisabled(true);
            ui->pushButton_sua->setDisabled(true);
            ui->pushButton_capnhat->setDisabled(true);
            ui->pushButton_xoa->setDisabled(true);
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

void Dialog_ThemTau::on_pushButton_xoa_clicked()  //XÓA TÀU
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
        qry.prepare("DELETE FROM tbl_tau WHERE tau_id=:tau_id");
        qry.bindValue(":tau_id", this->ID_DoubleCLick);
//        qDebug()<<"CLICK: " << this->ID_DoubleCLick;

        if(qry.exec())
        {
            QMessageBox::information(this, "Thông báo", "Xóa thông tin thành công!");
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
               le->clear();
               le->setDisabled(true);
            }

            ui->pushButton_themtau->setDisabled(false);
            ui->pushButton_luutau->setDisabled(true);
            ui->pushButton_sua->setDisabled(true);
            ui->pushButton_capnhat->setDisabled(true);
            ui->pushButton_xoa->setDisabled(true);
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }
}

void Dialog_ThemTau::on_pushButton_sua_clicked()
{
    ui->pushButton_themtau->setDisabled(true);
    ui->pushButton_luutau->setDisabled(true);
    ui->pushButton_sua->setDisabled(true);
    ui->pushButton_capnhat->setDisabled(false);
    ui->pushButton_xoa->setDisabled(true);

    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        le->setDisabled(false);
    }
}

void Dialog_ThemTau::on_pushButton_themtau_clicked()
{
    ui->pushButton_themtau->setDisabled(true);
    ui->pushButton_luutau->setDisabled(false);
    ui->pushButton_sua->setDisabled(true);
    ui->pushButton_capnhat->setDisabled(true);
    ui->pushButton_xoa->setDisabled(true);

    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        le->clear();
        le->setDisabled(false);
    }
}
