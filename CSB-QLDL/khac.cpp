#include "khac.h"
#include "ui_khac.h"

Khac::Khac(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Khac)
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

    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(SectionDoubleClick(int, int)));
    connect(ui->tableWidget_2, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(SectionDoubleClick_2(int, int)));
}

Khac::~Khac()
{
    delete ui;
}

void Khac::on_pushButton_2_clicked()  //HIỂN THỊ ADMIN
{
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }
    //===========================load thông tin tài khoản admin
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
       //Do some thing

        QSqlQuery query(db);
        query.prepare("SELECT * FROM tbl_taikhoan WHERE taikhoan_quyentruycap = '1'");
        query.exec();

        ui->tableWidget->setColumnCount(5);
        QStringList list_labels;
        list_labels << "id tài khoản" << "Tên người dùng" << "Tên đăng nhập"
                    << "Mật khẩu" << "Quyền truy cập";
        ui->tableWidget->setHorizontalHeaderLabels(list_labels);

        int rowcount = 0;
        while(query.next())
        {
            ui->tableWidget->insertRow(rowcount);
            QTableWidgetItem *taikhoan_id = new QTableWidgetItem;
            QTableWidgetItem *taikhoan_tennguoidung = new QTableWidgetItem;
            QTableWidgetItem *taikhoan_tendangnhap = new QTableWidgetItem;
            QTableWidgetItem *ttaikhoan_matkhau = new QTableWidgetItem;
            QTableWidgetItem *taikhoan_quyentruycap = new QTableWidgetItem;


            taikhoan_id->setText(query.value(0).toString());
            taikhoan_tennguoidung->setText(query.value(1).toString());
            taikhoan_tendangnhap->setText(query.value(2).toString());
            ttaikhoan_matkhau->setText(query.value(3).toString());
            taikhoan_quyentruycap->setText(query.value(4).toString());

            ui->tableWidget->setItem(rowcount, 0, taikhoan_id);
            ui->tableWidget->setItem(rowcount, 1, taikhoan_tennguoidung);
            ui->tableWidget->setItem(rowcount, 2, taikhoan_tendangnhap);
            ui->tableWidget->setItem(rowcount, 3, ttaikhoan_matkhau);
            ui->tableWidget->setItem(rowcount, 4, taikhoan_quyentruycap);

            rowcount++;
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Database connect Fail!");
    }
}

void Khac::on_pushButton_3_clicked() //HIỂN THỊ CÁN BỘ QL
{
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }
    //===========================load thông tin tài khoản cán bộ
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
       //Do some thing

        QSqlQuery query(db);
        query.prepare("SELECT * FROM tbl_taikhoan WHERE taikhoan_quyentruycap = '2'");
        query.exec();

        ui->tableWidget->setColumnCount(5);
        QStringList list_labels;
        list_labels << "id tài khoản" << "Tên người dùng" << "Tên đăng nhập"
                    << "Mật khẩu" << "Quyền truy cập";
        ui->tableWidget->setHorizontalHeaderLabels(list_labels);

        int rowcount = 0;
        while(query.next())
        {
            ui->tableWidget->insertRow(rowcount);
            QTableWidgetItem *taikhoan_id = new QTableWidgetItem;
            QTableWidgetItem *taikhoan_tennguoidung = new QTableWidgetItem;
            QTableWidgetItem *taikhoan_tendangnhap = new QTableWidgetItem;
            QTableWidgetItem *ttaikhoan_matkhau = new QTableWidgetItem;
            QTableWidgetItem *taikhoan_quyentruycap = new QTableWidgetItem;


            taikhoan_id->setText(query.value(0).toString());
            taikhoan_tennguoidung->setText(query.value(1).toString());
            taikhoan_tendangnhap->setText(query.value(2).toString());
            ttaikhoan_matkhau->setText(query.value(3).toString());
            taikhoan_quyentruycap->setText(query.value(4).toString());

            ui->tableWidget->setItem(rowcount, 0, taikhoan_id);
            ui->tableWidget->setItem(rowcount, 1, taikhoan_tennguoidung);
            ui->tableWidget->setItem(rowcount, 2, taikhoan_tendangnhap);
            ui->tableWidget->setItem(rowcount, 3, ttaikhoan_matkhau);
            ui->tableWidget->setItem(rowcount, 4, taikhoan_quyentruycap);

            rowcount++;
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Database connect Fail!");
    }
}

void Khac::on_pushButton_4_clicked()  //HIỂN THỊ NV NHẬP LIỆU
{
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }
    //===========================load thông tin tài khoản admin
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
       //Do some thing

        QSqlQuery query(db);
        query.prepare("SELECT * FROM tbl_taikhoan WHERE taikhoan_quyentruycap = '3'");
        query.exec();

        ui->tableWidget->setColumnCount(5);
        QStringList list_labels;
        list_labels << "id tài khoản" << "Tên người dùng" << "Tên đăng nhập"
                    << "Mật khẩu" << "Quyền truy cập";
        ui->tableWidget->setHorizontalHeaderLabels(list_labels);

        int rowcount = 0;
        while(query.next())
        {
            ui->tableWidget->insertRow(rowcount);
            QTableWidgetItem *taikhoan_id = new QTableWidgetItem;
            QTableWidgetItem *taikhoan_tennguoidung = new QTableWidgetItem;
            QTableWidgetItem *taikhoan_tendangnhap = new QTableWidgetItem;
            QTableWidgetItem *ttaikhoan_matkhau = new QTableWidgetItem;
            QTableWidgetItem *taikhoan_quyentruycap = new QTableWidgetItem;


            taikhoan_id->setText(query.value(0).toString());
            taikhoan_tennguoidung->setText(query.value(1).toString());
            taikhoan_tendangnhap->setText(query.value(2).toString());
            ttaikhoan_matkhau->setText(query.value(3).toString());
            taikhoan_quyentruycap->setText(query.value(4).toString());

            ui->tableWidget->setItem(rowcount, 0, taikhoan_id);
            ui->tableWidget->setItem(rowcount, 1, taikhoan_tennguoidung);
            ui->tableWidget->setItem(rowcount, 2, taikhoan_tendangnhap);
            ui->tableWidget->setItem(rowcount, 3, ttaikhoan_matkhau);
            ui->tableWidget->setItem(rowcount, 4, taikhoan_quyentruycap);

            rowcount++;
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Database connect Fail!");
    }
}

void Khac::on_pushButton_clicked()
{
    mdialog_themtaikhoan = new Dialog_ThemTaikhoan();
    mdialog_themtaikhoan->show();
}

void Khac::SectionDoubleClick(int row, int column)  //NHẬN SIGNAL DOUBLE CLICK VÀ ĐIỀN DỮ LIỆU VÀ CÁC LINE EDIT
{
    //========LẤY ID
    QString ID = ui->tableWidget->item(row, 0)->text();
    this->ID_DoubleCLick = ID.toInt();
//    qDebug()<<"id: " << ID_DoubleCLick;

    mdialog_suaxoa = new Dialog_SuaXoa();
    if(this->ok)
    {
       //Do some thing

        QSqlQuery query(db);
        QString QueryString = "SELECT * FROM tbl_taikhoan WHERE taikhoan_id LIKE '" + ID + "'";
        query.prepare(QueryString);
        query.exec();
        while(query.next())
        {
            mdialog_suaxoa->TenND_Update = query.value(1).toString();
            qDebug() << "TRONG KHAC.CPP: " << mdialog_suaxoa->TenND_Update;
            mdialog_suaxoa->TenDN_Update = query.value(2).toString();
            mdialog_suaxoa->MK_Update = query.value(3).toString();
            mdialog_suaxoa->Capdo = query.value(4).toInt();

            mdialog_suaxoa->ID_DoubleCLick = this->ID_DoubleCLick;
            mdialog_suaxoa->Update();
        }
        mdialog_suaxoa->show();

    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }
}

void Khac::on_pushButton_6_clicked()  //HIỂN THỊ THÔNG TIN TÀU TRONG BIÊN CHẾ
{
    while (ui->tableWidget_2->rowCount() > 0)
    {
        ui->tableWidget_2->removeRow(0);
    }
    //===========================load thông tin tài khoản admin
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
       //Do some thing

        QSqlQuery query(db);
        query.prepare("SELECT * FROM tbl_tau");
        query.exec();

        ui->tableWidget_2->setColumnCount(5);
        QStringList list_labels;
        list_labels << "id tàu" << "Số hiệu tàu" << "Tên gọi"
                    << "MMSI" << "Ghi chú";
        ui->tableWidget_2->setHorizontalHeaderLabels(list_labels);

        int rowcount = 0;
        while(query.next())
        {
            ui->tableWidget_2->insertRow(rowcount);
            QTableWidgetItem *tau_id = new QTableWidgetItem;
            QTableWidgetItem *tau_sohieu = new QTableWidgetItem;
            QTableWidgetItem *tau_tengoi = new QTableWidgetItem;
            QTableWidgetItem *tau_MMSI = new QTableWidgetItem;
            QTableWidgetItem *tau_ghichu = new QTableWidgetItem;


            tau_id->setText(query.value(0).toString());
            tau_sohieu->setText(query.value(2).toString());
            tau_tengoi->setText(query.value(3).toString());
            tau_MMSI->setText(query.value(5).toString());
            tau_ghichu->setText(query.value(6).toString());

            ui->tableWidget_2->setItem(rowcount, 0, tau_id);
            ui->tableWidget_2->setItem(rowcount, 1, tau_sohieu);
            ui->tableWidget_2->setItem(rowcount, 2, tau_tengoi);
            ui->tableWidget_2->setItem(rowcount, 3, tau_MMSI);
            ui->tableWidget_2->setItem(rowcount, 4, tau_ghichu);

            rowcount++;
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Database connect Fail!");
    }
}

void Khac::on_pushButton_5_clicked()  //DIALOG_THEMTAU
{
    mdialog_themtau = new Dialog_ThemTau();
    mdialog_themtau->show();
}

void Khac::SectionDoubleClick_2(int row, int column)
{
    //========LẤY ID
    QString ID = ui->tableWidget_2->item(row, 0)->text();
    this->ID_DoubleCLick = ID.toInt();
    qDebug()<<"id: " << ID_DoubleCLick;

    mdialog_themtau = new Dialog_ThemTau();
    mdialog_themtau->ID_DoubleCLick = this->ID_DoubleCLick;

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
       //Do some thing
        qDebug()<<"MO DATABASE";
        QSqlQuery query(db);
        QString QueryString = "SELECT * FROM tbl_tau WHERE tau_id LIKE '" + ID + "'";
        query.prepare(QueryString);
        query.exec();
        while(query.next())
        {
            qDebug()<<"EXEC DATABASE";
            mdialog_themtau->Sohieu_update = query.value(2).toString();
            qDebug()<<"so hieu: " << query.value(2).toString();

            mdialog_themtau->Tengoi_update = query.value(3).toString();
            qDebug()<<"ten goi: " << query.value(3).toString();

            mdialog_themtau->mmsi_update = query.value(5).toString();
            qDebug()<<"mmsi: " << query.value(5).toString();

            mdialog_themtau->Ghichu_update = query.value(6).toString();
            qDebug()<<"ghi chu: " << query.value(6).toString();

            mdialog_themtau->Update_tau();
        }
        mdialog_themtau->show();

    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }
}
