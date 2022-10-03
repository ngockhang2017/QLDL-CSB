#include "cuuho.h"
#include "ui_CuuHo.h"


CuuHo::CuuHo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CuuHo)
{
    ui->setupUi(this);
    ui->pushButton->setDisabled(false);  ///Còn hiện mỗi nút thêm mới
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);

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


    //===========================load dữ liệu cứu hộ
    if(ok)
    {
       //Do some thing

        QSqlQuery query(db);
        query.prepare("SELECT * FROM tbl_cuuho");
        query.exec();

        ui->tableWidget->setColumnCount(16);
        QStringList list_labels;
        list_labels << "id cứu hộ" << "Tên nhiệm vụ cứu hộ" << "Thời gian"
                    << "Kinh độ" << "Vĩ độ" << "Tiếp cận lúc" << "KĐ tiếp cận" << "VĐ tiếp cận"
                    << "Thời gian lai dắt" << "Địa điểm lai dắt" << "Số người cứu được"
                    << "Số người mất tích" << "Số người tử vong" << "Ghi chú" << "DS tàu cứu nạn"
                    << "DS tàu gặp nạn";
        ui->tableWidget->setHorizontalHeaderLabels(list_labels);

        int rowcount = 0;
        while(query.next())
        {
            ui->tableWidget->insertRow(rowcount);
            QTableWidgetItem *cuuho_id = new QTableWidgetItem;
            QTableWidgetItem * cuuho_tennhiemvu = new QTableWidgetItem;
            QTableWidgetItem *cuuho_thoigian = new QTableWidgetItem;
            QTableWidgetItem *cuuho_kinhdo = new QTableWidgetItem;
            QTableWidgetItem *cuuho_vido = new QTableWidgetItem;
            QTableWidgetItem *cuuho_thoigiantiepcan = new QTableWidgetItem;
            QTableWidgetItem *diadiemtiepcan_kinhdo = new QTableWidgetItem;
            QTableWidgetItem *diadiemtiepcan_vido = new QTableWidgetItem;
            QTableWidgetItem *cuuho_thoigianlaidat = new QTableWidgetItem;
            QTableWidgetItem *cuuho_diadiemlaidat = new QTableWidgetItem;
            QTableWidgetItem *cuuho_songuoicuuduoc = new QTableWidgetItem;
            QTableWidgetItem *cuuho_songuoimattich = new QTableWidgetItem;
            QTableWidgetItem *cuuho_songuoituvong = new QTableWidgetItem;
            QTableWidgetItem *cuuho_ghichu = new QTableWidgetItem;
            QTableWidgetItem *cuuho_dstaucuunan_rawtext = new QTableWidgetItem;
            QTableWidgetItem *cuuho_dstaugapnan_rawtext = new QTableWidgetItem;

            cuuho_id->setText(query.value(0).toString());
            cuuho_tennhiemvu->setText(query.value(1).toString());
            cuuho_thoigian->setText(query.value(2).toString());
            cuuho_kinhdo->setText(query.value(3).toString());
            cuuho_vido->setText(query.value(4).toString());
            cuuho_thoigiantiepcan->setText(query.value(5).toString());
            diadiemtiepcan_kinhdo->setText(query.value(6).toString());
            diadiemtiepcan_vido->setText(query.value(7).toString());
            cuuho_thoigianlaidat->setText(query.value(8).toString());
            cuuho_diadiemlaidat->setText(query.value(9).toString());
            cuuho_songuoicuuduoc->setText(query.value(10).toString());
            cuuho_songuoimattich->setText(query.value(11).toString());
            cuuho_songuoituvong->setText(query.value(12).toString());
            cuuho_ghichu->setText(query.value(13).toString());
            cuuho_dstaucuunan_rawtext->setText(query.value(14).toString());
            cuuho_dstaugapnan_rawtext->setText(query.value(15).toString());


            ui->tableWidget->setItem(rowcount, 0, cuuho_id);
            ui->tableWidget->setItem(rowcount, 1, cuuho_tennhiemvu);
            ui->tableWidget->setItem(rowcount, 2, cuuho_thoigian);
            ui->tableWidget->setItem(rowcount, 3, cuuho_kinhdo);
            ui->tableWidget->setItem(rowcount, 4, cuuho_vido);
            ui->tableWidget->setItem(rowcount, 5, cuuho_thoigiantiepcan);
            ui->tableWidget->setItem(rowcount, 6, diadiemtiepcan_kinhdo);
            ui->tableWidget->setItem(rowcount, 7, diadiemtiepcan_vido);
            ui->tableWidget->setItem(rowcount, 8, cuuho_thoigianlaidat);
            ui->tableWidget->setItem(rowcount, 9, cuuho_diadiemlaidat);
            ui->tableWidget->setItem(rowcount, 10, cuuho_songuoicuuduoc);
            ui->tableWidget->setItem(rowcount, 11, cuuho_songuoimattich);
            ui->tableWidget->setItem(rowcount, 12, cuuho_songuoituvong);
            ui->tableWidget->setItem(rowcount, 13, cuuho_ghichu);
            ui->tableWidget->setItem(rowcount, 14, cuuho_dstaucuunan_rawtext);
            ui->tableWidget->setItem(rowcount, 15, cuuho_dstaugapnan_rawtext);


           //ui->tableWidget->clicked()
            rowcount++;
        }
    }

//    connect(ui->tableWidget->verticalHeader(), &QHeaderView::sectionDoubleClicked, this, SectionDoubleClick(int ));
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(SectionDoubleClick(int, int)));
}

CuuHo::~CuuHo()
{
    delete ui;
}

//các hàm chức năng

void CuuHo::on_pushButton_Cuuho_Tatca_clicked()  //HIỆN TẤT CẢ
{
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }
    //===========================load dữ liệu cứu hộ
    if(ok)
    {
       //Do some thing

        QSqlQuery query(db);
        query.prepare("SELECT * FROM tbl_cuuho");
        query.exec();

        ui->tableWidget->setColumnCount(16);
        QStringList list_labels;
        list_labels << "id cứu hộ" << "Tên nhiệm vụ cứu hộ" << "Thời gian"
                    << "Kinh độ" << "Vĩ độ" << "Tiếp cận lúc" << "KĐ tiếp cận" << "VĐ tiếp cận"
                    << "Thời gian lai dắt" << "Địa điểm lai dắt" << "Số người cứu được"
                    << "Số người mất tích" << "Số người tử vong" << "Ghi chú" << "DS tàu cứu nạn"
                    << "DS tàu gặp nạn";
        ui->tableWidget->setHorizontalHeaderLabels(list_labels);

        int rowcount = 0;
        while(query.next())
        {
            ui->tableWidget->insertRow(rowcount);
            QTableWidgetItem *cuuho_id = new QTableWidgetItem;
            QTableWidgetItem * cuuho_tennhiemvu = new QTableWidgetItem;
            QTableWidgetItem *cuuho_thoigian = new QTableWidgetItem;
            QTableWidgetItem *cuuho_kinhdo = new QTableWidgetItem;
            QTableWidgetItem *cuuho_vido = new QTableWidgetItem;
            QTableWidgetItem *cuuho_thoigiantiepcan = new QTableWidgetItem;
            QTableWidgetItem *diadiemtiepcan_kinhdo = new QTableWidgetItem;
            QTableWidgetItem *diadiemtiepcan_vido = new QTableWidgetItem;
            QTableWidgetItem *cuuho_thoigianlaidat = new QTableWidgetItem;
            QTableWidgetItem *cuuho_diadiemlaidat = new QTableWidgetItem;
            QTableWidgetItem *cuuho_songuoicuuduoc = new QTableWidgetItem;
            QTableWidgetItem *cuuho_songuoimattich = new QTableWidgetItem;
            QTableWidgetItem *cuuho_songuoituvong = new QTableWidgetItem;
            QTableWidgetItem *cuuho_ghichu = new QTableWidgetItem;
            QTableWidgetItem *cuuho_dstaucuunan_rawtext = new QTableWidgetItem;
            QTableWidgetItem *cuuho_dstaugapnan_rawtext = new QTableWidgetItem;

            cuuho_id->setText(query.value(0).toString());
            cuuho_tennhiemvu->setText(query.value(1).toString());
            cuuho_thoigian->setText(query.value(2).toString());
            cuuho_kinhdo->setText(query.value(3).toString());
            cuuho_vido->setText(query.value(4).toString());
            cuuho_thoigiantiepcan->setText(query.value(5).toString());
            diadiemtiepcan_kinhdo->setText(query.value(6).toString());
            diadiemtiepcan_vido->setText(query.value(7).toString());
            cuuho_thoigianlaidat->setText(query.value(8).toString());
            cuuho_diadiemlaidat->setText(query.value(9).toString());
            cuuho_songuoicuuduoc->setText(query.value(10).toString());
            cuuho_songuoimattich->setText(query.value(11).toString());
            cuuho_songuoituvong->setText(query.value(12).toString());
            cuuho_ghichu->setText(query.value(13).toString());
            cuuho_dstaucuunan_rawtext->setText(query.value(14).toString());
            cuuho_dstaugapnan_rawtext->setText(query.value(15).toString());


            ui->tableWidget->setItem(rowcount, 0, cuuho_id);
            ui->tableWidget->setItem(rowcount, 1, cuuho_tennhiemvu);
            ui->tableWidget->setItem(rowcount, 2, cuuho_thoigian);
            ui->tableWidget->setItem(rowcount, 3, cuuho_kinhdo);
            ui->tableWidget->setItem(rowcount, 4, cuuho_vido);
            ui->tableWidget->setItem(rowcount, 5, cuuho_thoigiantiepcan);
            ui->tableWidget->setItem(rowcount, 6, diadiemtiepcan_kinhdo);
            ui->tableWidget->setItem(rowcount, 7, diadiemtiepcan_vido);
            ui->tableWidget->setItem(rowcount, 8, cuuho_thoigianlaidat);
            ui->tableWidget->setItem(rowcount, 9, cuuho_diadiemlaidat);
            ui->tableWidget->setItem(rowcount, 10, cuuho_songuoicuuduoc);
            ui->tableWidget->setItem(rowcount, 11, cuuho_songuoimattich);
            ui->tableWidget->setItem(rowcount, 12, cuuho_songuoituvong);
            ui->tableWidget->setItem(rowcount, 13, cuuho_ghichu);
            ui->tableWidget->setItem(rowcount, 14, cuuho_dstaucuunan_rawtext);
            ui->tableWidget->setItem(rowcount, 15, cuuho_dstaugapnan_rawtext);


            rowcount++;
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Database connect Fail!");
    }
}

void CuuHo::on_pushButton_2_clicked()//Lưu nhiệm vụ CỨU HỘ mới
{

    int cuuho_id;
    QString cuuho_tennhiemvu = ui->lineEdit_TenNV->text();
    QDateTime cuuho_thoigian = ui->dateTimeEdit_TGThongBao->dateTime();
    double cuuho_kinhdo = ui->lineEdit_KD_SuCo->text().toDouble();
    double cuuho_vido = ui->lineEdit_VD_SuCo->text().toDouble();
    QDateTime cuuho_thoigiantiepcan = ui->dateTimeEdit_TiepCan->dateTime();
    double diadiemtiepcan_kinhdo = ui->lineEdit_KD_TiepCan->text().toDouble();
    double diadiemtiepcan_vido = ui->lineEdit_VD_TiepCan->text().toDouble();
    QDateTime cuuho_thoigianlaidat = ui->dateTimeEdit_LaiDat->dateTime();
    QString cuuho_diadiemlaidat = ui->lineEditDDlaidat->text();
    int cuuho_songuoicuuduoc = ui->lineEdit_SoNguoiCuuDuoc->text().toInt();
    int cuuho_songuoimattich = ui->lineEdit_SoNguoiMatTich->text().toInt();
    int cuuho_songuoituvong = ui->lineEdit_SoNguoiTuVong->text().toInt();
    QString cuuho_ghichu = ui->textEdit_GhiChu->toPlainText();
    QString cuuho_dstaucuunan_rawtext = ui->lineEdit_tauCuuHo->text();
    QString cuuho_dstaugapnan_rawtext = ui->lineEdit_DS_tauSuCo->text();

    //=====================================TEST INSERT DATABASE
    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("INSERT INTO tbl_cuuho ( cuuho_tennhiemvu, cuuho_thoigian, cuuho_kinhdo, cuuho_vido, cuuho_thoigiantiepcan, "
                    "diadiemtiepcan_kinhdo, diadiemtiepcan_vido, cuuho_thoigianlaidat, cuuho_diadiemlaidat, "
                    "cuuho_songuoicuuduoc, cuuho_songuoimattich, cuuho_songuoituvong, cuuho_ghichu, cuuho_dstaucuunan_rawtext,"
                    "cuuho_dstaugapnan_rawtext) "
                          "VALUES (:cuuho_tennhiemvu, :cuuho_thoigian, :cuuho_kinhdo, :cuuho_vido, :cuuho_thoigiantiepcan,"
                    ":diadiemtiepcan_kinhdo, :diadiemtiepcan_vido, :cuuho_thoigianlaidat, :cuuho_diadiemlaidat,"
                    ":cuuho_songuoicuuduoc, :cuuho_songuoimattich, :cuuho_songuoituvong, :cuuho_ghichu, "
                    ":cuuho_dstaucuunan_rawtext, :cuuho_dstaugapnan_rawtext)");
      //  qry.bindValue(":id", 50);
        qry.bindValue(":cuuho_tennhiemvu", cuuho_tennhiemvu);
        qry.bindValue(":cuuho_thoigian", cuuho_thoigian);
        qry.bindValue(":cuuho_kinhdo", cuuho_kinhdo);
        qry.bindValue(":cuuho_vido", cuuho_vido);
        qry.bindValue(":cuuho_thoigiantiepcan", cuuho_thoigiantiepcan);
        qry.bindValue(":diadiemtiepcan_kinhdo", diadiemtiepcan_kinhdo);
        qry.bindValue(":diadiemtiepcan_vido", diadiemtiepcan_vido);
        qry.bindValue(":cuuho_thoigianlaidat", cuuho_thoigianlaidat);
        qry.bindValue(":cuuho_diadiemlaidat", cuuho_diadiemlaidat);
        qry.bindValue(":cuuho_songuoicuuduoc", cuuho_songuoicuuduoc);
        qry.bindValue(":cuuho_songuoimattich", cuuho_songuoimattich);
        qry.bindValue(":cuuho_songuoituvong", cuuho_songuoituvong);
        qry.bindValue(":cuuho_ghichu", cuuho_ghichu);
        qry.bindValue(":cuuho_dstaucuunan_rawtext", cuuho_dstaucuunan_rawtext);
        qry.bindValue(":cuuho_dstaugapnan_rawtext", cuuho_dstaugapnan_rawtext);


        cuuho_id = -1;
        if(qry.exec())
        {
            if(qry.lastInsertId().isValid())
            {
                cuuho_id = qry.lastInsertId().toInt();
            }
            QMessageBox::information(this, "report", "Thông tin nhiệm vụ được thêm thành công");
            //clear all text
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
               le->clear();
               le->setDisabled(true);
            }

            foreach(QTextEdit* le, findChildren<QTextEdit*>())
            {
               le->clear();
               le->setDisabled(true);
            }
            ui->pushButton->setDisabled(false);  ///Còn hiện mỗi nút thêm mới
            ui->pushButton_2->setDisabled(true);
            ui->pushButton_3->setDisabled(true);
            ui->pushButton_4->setDisabled(true);
            ui->pushButton_5->setDisabled(true);
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

void CuuHo::on_pushButton_clicked() //BẮT ĐẦU THÊM THÔNG TIN MỚI
{

    ui->pushButton->setDisabled(true);  //ấn nút này đi
    ui->pushButton_2->setDisabled(false);  //hiện nút lưu nhiệm vụ
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);

    //clear all text
    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
       le->clear();
       le->setDisabled(false);
    }

    foreach(QTextEdit* le, findChildren<QTextEdit*>())
    {
       le->clear();
       le->setDisabled(false);
    }

}

void CuuHo::SectionDoubleClick(int row, int column)  //NHẬN SIGNAL DOUBLE CLICK VÀ ĐIỀN DỮ LIỆU VÀ CÁC LINE EDIT
{
    //========LẤY ID
    QString ID = ui->tableWidget->item(row, 0)->text();
    this->ID_DoubleCLick = ID.toInt();

    //======THOÁT RA MÀN HÌNH CHÍNH --> TRUY VẤN THEO ID
    ui->tabWidget->setCurrentIndex(0);

    if(this->ok)
    {
       //Do some thing

        QSqlQuery query(db);
        QString QueryString = "SELECT * FROM tbl_cuuho WHERE cuuho_id LIKE '" + ID + "'";
        query.prepare(QueryString);
        query.exec();
        while(query.next())
        {
            ui->lineEdit_TenNV->setText(query.value(1).toString());
            ui->dateTimeEdit_TGThongBao->setDateTime(query.value(2).toDateTime()); //set datetime
            ui->lineEdit_KD_SuCo->setText(query.value(3).toString());
            ui->lineEdit_VD_SuCo->setText(query.value(4).toString());
            ui->lineEdit_DS_tauSuCo->setText(query.value(15).toString());
            ui->lineEdit_tauCuuHo->setText(query.value(14).toString());
            ui->textEdit_GhiChu->setText(query.value(13).toString());
            ui->dateTimeEdit_TiepCan->setDateTime(query.value(5).toDateTime());
            ui->lineEdit_KD_TiepCan->setText(query.value(6).toString());
            ui->lineEdit_VD_TiepCan->setText(query.value(7).toString());
            ui->dateTimeEdit_LaiDat->setDateTime(query.value(8).toDateTime());
            ui->lineEditDDlaidat->setText(query.value(9).toString());
            ui->lineEdit_SoNguoiCuuDuoc->setText(query.value(10).toString());
            ui->lineEdit_SoNguoiTuVong->setText(query.value(12).toString());
            ui->lineEdit_SoNguoiMatTich->setText(query.value(11).toString());
        }
        //setDisabled all line edit
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
               le->setDisabled(true);
            }
            foreach(QTextEdit* le, findChildren<QTextEdit*>())
            {
               le->setDisabled(true);
            }
            ui->pushButton->setDisabled(false);
            ui->pushButton_2->setDisabled(true); //ẩn nút lưu thông tin
            ui->pushButton_3->setDisabled(false);
            ui->pushButton_4->setDisabled(true); //ẩn nút cập nhật
            ui->pushButton_5->setDisabled(false);
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }
}

void CuuHo::on_pushButton_3_clicked()  //sửa
{
    ui->pushButton->setDisabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(false); //hiện cập nhật
    ui->pushButton_5->setDisabled(true);

    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        le->setDisabled(false);
    }
    foreach(QTextEdit* le, findChildren<QTextEdit*>())
    {
       le->setDisabled(false);
    }
}

void CuuHo::on_pushButton_5_clicked()  //xóa
{

    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("DELETE FROM tbl_cuuho WHERE cuuho_id=:cuuho_id");
        qry.bindValue(":cuuho_id", this->ID_DoubleCLick);

        if(qry.exec())
        {
            QMessageBox::information(this, "Thông báo", "Xóa thông tin thành công!");
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
                le->clear();
            }
            foreach(QTextEdit* le, findChildren<QTextEdit*>())
            {
               le->clear();
            }
            ui->pushButton->setDisabled(false);  ///Còn hiện mỗi nút thêm mới
            ui->pushButton_2->setDisabled(true);
            ui->pushButton_3->setDisabled(true);
            ui->pushButton_4->setDisabled(true);
            ui->pushButton_5->setDisabled(true);
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }
}

void CuuHo::on_pushButton_4_clicked()  //Cập nhật thông tin đã sửa
{
    //Lấy ra các giá trị đã được sửa từ ui
    int cuuho_id = this->ID_DoubleCLick; //lấy từ lần double click
    QString cuuho_tennhiemvu = ui->lineEdit_TenNV->text();
    QDateTime cuuho_thoigian = ui->dateTimeEdit_TGThongBao->dateTime();
    double cuuho_kinhdo = ui->lineEdit_KD_SuCo->text().toDouble();
    double cuuho_vido = ui->lineEdit_VD_SuCo->text().toDouble();
    QDateTime cuuho_thoigiantiepcan = ui->dateTimeEdit_TiepCan->dateTime();
    double diadiemtiepcan_kinhdo = ui->lineEdit_KD_TiepCan->text().toDouble();
    double diadiemtiepcan_vido = ui->lineEdit_VD_TiepCan->text().toDouble();
    QDateTime cuuho_thoigianlaidat = ui->dateTimeEdit_LaiDat->dateTime();
    QString cuuho_diadiemlaidat = ui->lineEditDDlaidat->text();
    int cuuho_songuoicuuduoc = ui->lineEdit_SoNguoiCuuDuoc->text().toInt();
    int cuuho_songuoimattich = ui->lineEdit_SoNguoiMatTich->text().toInt();
    int cuuho_songuoituvong = ui->lineEdit_SoNguoiTuVong->text().toInt();
    QString cuuho_ghichu = ui->textEdit_GhiChu->toPlainText();
    QString cuuho_dstaucuunan_rawtext = ui->lineEdit_tauCuuHo->text();
    QString cuuho_dstaugapnan_rawtext = ui->lineEdit_DS_tauSuCo->text();

    if(this->ok)
    {
        QSqlQuery qry(this->db);

        qry.prepare("UPDATE tbl_cuuho SET cuuho_tennhiemvu=:cuuho_tennhiemvu, cuuho_thoigian=:cuuho_thoigian, cuuho_kinhdo=:cuuho_kinhdo, cuuho_vido=:cuuho_vido, cuuho_thoigiantiepcan=:cuuho_thoigiantiepcan, "
                    "diadiemtiepcan_kinhdo=:diadiemtiepcan_kinhdo, diadiemtiepcan_vido=:diadiemtiepcan_vido, cuuho_thoigianlaidat=:cuuho_thoigianlaidat, cuuho_diadiemlaidat=:cuuho_diadiemlaidat, "
                    "cuuho_songuoicuuduoc=:cuuho_songuoicuuduoc, cuuho_songuoimattich=:cuuho_songuoimattich, cuuho_songuoituvong=:cuuho_songuoituvong, cuuho_ghichu=:cuuho_ghichu, cuuho_dstaucuunan_rawtext=:cuuho_dstaucuunan_rawtext,"
                    "cuuho_dstaugapnan_rawtext=:cuuho_dstaugapnan_rawtext "
                          "WHERE cuuho_id=:cuuho_id");


        qry.bindValue(":cuuho_tennhiemvu", cuuho_tennhiemvu);
        qry.bindValue(":cuuho_thoigian", cuuho_thoigian);
        qry.bindValue(":cuuho_kinhdo", cuuho_kinhdo);
        qry.bindValue(":cuuho_vido", cuuho_vido);
        qry.bindValue(":cuuho_thoigiantiepcan", cuuho_thoigiantiepcan);
        qry.bindValue(":diadiemtiepcan_kinhdo", diadiemtiepcan_kinhdo);
        qry.bindValue(":diadiemtiepcan_vido", diadiemtiepcan_vido);
        qry.bindValue(":cuuho_thoigianlaidat", cuuho_thoigianlaidat);
        qry.bindValue(":cuuho_diadiemlaidat", cuuho_diadiemlaidat);
        qry.bindValue(":cuuho_songuoicuuduoc", cuuho_songuoicuuduoc);
        qry.bindValue(":cuuho_songuoimattich", cuuho_songuoimattich);
        qry.bindValue(":cuuho_songuoituvong", cuuho_songuoituvong);
        qry.bindValue(":cuuho_ghichu", cuuho_ghichu);
        qry.bindValue(":cuuho_dstaucuunan_rawtext", cuuho_dstaucuunan_rawtext);
        qry.bindValue(":cuuho_dstaugapnan_rawtext", cuuho_dstaugapnan_rawtext);

        qry.bindValue(":cuuho_id", cuuho_id);

        if(qry.exec())
        {
            QMessageBox::information(this, "Thông báo", "Cập nhật thông tin thành công!");
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
               le->clear();
            }

            foreach(QTextEdit* le, findChildren<QTextEdit*>())
            {
               le->clear();
            }
            ui->pushButton->setDisabled(false);  ///Còn hiện mỗi nút thêm mới
            ui->pushButton_2->setDisabled(true);
            ui->pushButton_3->setDisabled(true);
            ui->pushButton_4->setDisabled(true);
            ui->pushButton_5->setDisabled(true);
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

void CuuHo::on_pushButton_9_clicked() //XUẤT FILE
{
    mdialog_XuatFile = new Dialog_XuatFile(this);
    mdialog_XuatFile->exec();

 if(mdialog_XuatFile->status == true)
 {
    //qDebug() << "Ngay dau: " << mDialogXuatFile->Ngaydau.toString("yyyy-MM-dd") << "Ngay cuoi: " << mDialogXuatFile->Ngaycuoi.toString("yyyy-MM-dd");
    QString FileName = "TypeFileName";
    QString pathToSave_01 = QFileDialog::getSaveFileUrl(this, tr("Select Folder"), FileName, tr("Microsoft Office 2007 (*.xlsx)")).toEncoded();

    //qDebug() << "pathToSave_01 status: " << !pathToSave_01.isEmpty();

     if(!pathToSave_01.isEmpty())
     {
         QAxObject *excel = new QAxObject(this);
         excel->setControl("Excel.Application");
         excel->dynamicCall("SetVisible (bool Visible)","false");
         excel->setProperty("DisplayAlerts", false);

         QAxObject *workbooks = excel->querySubObject("WorkBooks");
         workbooks->dynamicCall("Add");

         QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
         QAxObject *worksheets = workbook->querySubObject("Sheets");
         QAxObject *worksheet = worksheets->querySubObject("Item(int)",1);

         QAxObject *cellcuuho_id,*cellcuuho_tennhiemvu,*cellcuuho_thoigian,*cellcuuho_kinhdo,
                 *cellcuuho_vido,*cellcuuho_thoigiantiepcan,*celldiadiemtiepcan_kinhdo,*celldiadiemtiepcan_vido,
                 *cellcuuho_thoigianlaidat,*cellcuuho_diadiemlaidat,*cellcuuho_songuoicuuduoc,*cellcuuho_songuoimattich,
                 *cellcuuho_songuoituvong,*cellcuuho_ghichu, *cellcuuho_dstaucuunan_rawtext, *cellcuuho_dstaugapnan_rawtext;

         int cellrow = 1;

         QString A= "A"+QString::number(cellrow);
         QString B= "B"+QString::number(cellrow);
         QString C= "C"+QString::number(cellrow);
         QString D= "D"+QString::number(cellrow);
         QString E= "E"+QString::number(cellrow);
         QString F= "F"+QString::number(cellrow);
         QString G= "G"+QString::number(cellrow);
         QString H= "H"+QString::number(cellrow);
         QString I= "I"+QString::number(cellrow);
         QString J= "J"+QString::number(cellrow);
         QString K= "K"+QString::number(cellrow);
         QString L= "L"+QString::number(cellrow);
         QString M= "M"+QString::number(cellrow);
         QString N= "N"+QString::number(cellrow);
         QString O= "O"+QString::number(cellrow);
         QString P= "P"+QString::number(cellrow);


         cellcuuho_id = worksheet->querySubObject("Range(QVariant, QVariant)",A);
         cellcuuho_tennhiemvu = worksheet->querySubObject("Range(QVariant, QVariant)",B);
         cellcuuho_thoigian = worksheet->querySubObject("Range(QVariant, QVariant)",C);
         cellcuuho_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",D);
         cellcuuho_vido = worksheet->querySubObject("Range(QVariant, QVariant)",E);
         cellcuuho_thoigiantiepcan = worksheet->querySubObject("Range(QVariant, QVariant)",F);
         celldiadiemtiepcan_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",G);
         celldiadiemtiepcan_vido = worksheet->querySubObject("Range(QVariant, QVariant)",H);
         cellcuuho_thoigianlaidat = worksheet->querySubObject("Range(QVariant, QVariant)",I);
         cellcuuho_diadiemlaidat = worksheet->querySubObject("Range(QVariant, QVariant)",J);
         cellcuuho_songuoicuuduoc = worksheet->querySubObject("Range(QVariant, QVariant)",K);
         cellcuuho_songuoimattich = worksheet->querySubObject("Range(QVariant, QVariant)",L);
         cellcuuho_songuoituvong = worksheet->querySubObject("Range(QVariant, QVariant)",M);
         cellcuuho_ghichu = worksheet->querySubObject("Range(QVariant, QVariant)",N);
         cellcuuho_dstaucuunan_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",O);
         cellcuuho_dstaugapnan_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",P);


         cellcuuho_id->dynamicCall("SetValue(const QVariant&)",QVariant("ID CỨU HỘ"));
         cellcuuho_tennhiemvu->dynamicCall("SetValue(const QVariant&)",QVariant("TÊN NHIỆM VỤ"));
         cellcuuho_thoigian->dynamicCall("SetValue(const QVariant&)",QVariant("THỜI GIAN THỰC HIỆN"));
         cellcuuho_kinhdo->dynamicCall("SetValue(const QVariant&)",QVariant("KINH ĐỘ TAI NẠN"));
         cellcuuho_vido->dynamicCall("SetValue(const QVariant&)",QVariant("VĨ ĐỘ TAI NẠN"));
         cellcuuho_thoigiantiepcan->dynamicCall("SetValue(const QVariant&)",QVariant("THỜI GIAN TIẾP CẬN"));
         celldiadiemtiepcan_kinhdo->dynamicCall("SetValue(const QVariant&)",QVariant("KINH ĐỘ TIẾP CẬN"));
         celldiadiemtiepcan_vido->dynamicCall("SetValue(const QVariant&)",QVariant("VĨ ĐỘ TIẾP CẬN"));
         cellcuuho_thoigianlaidat->dynamicCall("SetValue(const QVariant&)",QVariant("THỜI GIAN LAI DẮT"));
         cellcuuho_diadiemlaidat->dynamicCall("SetValue(const QVariant&)",QVariant("ĐỊA ĐIỂM LAI DẮT"));
         cellcuuho_songuoicuuduoc->dynamicCall("SetValue(const QVariant&)",QVariant("SỐ NGƯỜI CỨU ĐƯỢC"));
         cellcuuho_songuoimattich->dynamicCall("SetValue(const QVariant&)",QVariant("SỐ NGƯỜI MẤT TÍCH"));
         cellcuuho_songuoituvong->dynamicCall("SetValue(const QVariant&)",QVariant("SỐ NGƯỜI TỬ VONG"));
         cellcuuho_ghichu->dynamicCall("SetValue(const QVariant&)",QVariant("GHI CHÚ"));
         cellcuuho_dstaucuunan_rawtext->dynamicCall("SetValue(const QVariant&)",QVariant("DS TÀU THỰC HIỆN NV"));
         cellcuuho_dstaugapnan_rawtext->dynamicCall("SetValue(const QVariant&)",QVariant("DS TÀU GẶP NẠN"));

         cellrow++;

         if(this->ok)
         {
             QString query_string = "SELECT * FROM tbl_cuuho WHERE DATE(cuuho_thoigiantiepcan)>= '" + mdialog_XuatFile->NgayDau.toString("yyyy-MM-dd") + "' AND DATE(cuuho_thoigiantiepcan)<= '" + mdialog_XuatFile->NgayCuoi.toString("yyyy-MM-dd") + "'";
//             qDebug() << "Query: " << query_string;
             QSqlQuery qry(this->db);
             qry.prepare(query_string);
             qry.exec();

             //truy vấn
             while (qry.next())
             {
                 //tiến hành ghi vào từng hàng trong file *.xlsx
                  A= "A"+QString::number(cellrow);
                  B= "B"+QString::number(cellrow);
                  C= "C"+QString::number(cellrow);
                  D= "D"+QString::number(cellrow);
                  E= "E"+QString::number(cellrow);
                  F= "F"+QString::number(cellrow);
                  G= "G"+QString::number(cellrow);
                  H= "H"+QString::number(cellrow);
                  I= "I"+QString::number(cellrow);
                  J= "J"+QString::number(cellrow);
                  K= "K"+QString::number(cellrow);
                  L= "L"+QString::number(cellrow);
                  M= "M"+QString::number(cellrow);
                  N= "N"+QString::number(cellrow);
                  O= "O"+QString::number(cellrow);
                  P= "P"+QString::number(cellrow);

                  cellcuuho_id = worksheet->querySubObject("Range(QVariant, QVariant)",A);
                  cellcuuho_tennhiemvu = worksheet->querySubObject("Range(QVariant, QVariant)",B);
                  cellcuuho_thoigian = worksheet->querySubObject("Range(QVariant, QVariant)",C);
                  cellcuuho_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",D);
                  cellcuuho_vido = worksheet->querySubObject("Range(QVariant, QVariant)",E);
                  cellcuuho_thoigiantiepcan = worksheet->querySubObject("Range(QVariant, QVariant)",F);
                  celldiadiemtiepcan_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",G);
                  celldiadiemtiepcan_vido = worksheet->querySubObject("Range(QVariant, QVariant)",H);
                  cellcuuho_thoigianlaidat = worksheet->querySubObject("Range(QVariant, QVariant)",I);
                  cellcuuho_diadiemlaidat = worksheet->querySubObject("Range(QVariant, QVariant)",J);
                  cellcuuho_songuoicuuduoc = worksheet->querySubObject("Range(QVariant, QVariant)",K);
                  cellcuuho_songuoimattich = worksheet->querySubObject("Range(QVariant, QVariant)",L);
                  cellcuuho_songuoituvong = worksheet->querySubObject("Range(QVariant, QVariant)",M);
                  cellcuuho_ghichu = worksheet->querySubObject("Range(QVariant, QVariant)",N);
                  cellcuuho_dstaucuunan_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",O);
                  cellcuuho_dstaugapnan_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",P);


                 cellcuuho_id->dynamicCall("SetValue(const QVariant&)", qry.value(0).toString());
                 cellcuuho_tennhiemvu->dynamicCall("SetValue(const QVariant&)",qry.value(1).toString());
                 cellcuuho_thoigian->dynamicCall("SetValue(const QVariant&)", qry.value(2).toString());
                 cellcuuho_kinhdo->dynamicCall("SetValue(const QVariant&)", qry.value(3).toString());
                 cellcuuho_vido->dynamicCall("SetValue(const QVariant&)",qry.value(4).toString());
                 cellcuuho_thoigiantiepcan->dynamicCall("SetValue(const QVariant&)", qry.value(5).toString());
                 celldiadiemtiepcan_kinhdo->dynamicCall("SetValue(const QVariant&)", qry.value(6).toString());
                 celldiadiemtiepcan_vido->dynamicCall("SetValue(const QVariant&)", qry.value(7).toString());
                 cellcuuho_thoigianlaidat->dynamicCall("SetValue(const QVariant&)", qry.value(8).toString());
                 cellcuuho_diadiemlaidat->dynamicCall("SetValue(const QVariant&)", qry.value(9).toString());
                 cellcuuho_songuoicuuduoc->dynamicCall("SetValue(const QVariant&)", qry.value(10).toString());
                 cellcuuho_songuoimattich->dynamicCall("SetValue(const QVariant&)", qry.value(11).toString());
                 cellcuuho_songuoituvong->dynamicCall("SetValue(const QVariant&)", qry.value(12).toString());
                 cellcuuho_ghichu->dynamicCall("SetValue(const QVariant&)", qry.value(13).toString());
                 cellcuuho_dstaucuunan_rawtext->dynamicCall("SetValue(const QVariant&)", qry.value(14).toString());
                 cellcuuho_dstaugapnan_rawtext->dynamicCall("SetValue(const QVariant&)", qry.value(15).toString());

                 cellrow++;
             }

             workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(pathToSave_01));

             workbook->dynamicCall("Close()");
             excel->dynamicCall("Quit()");
             delete excel;
             excel=NULL;
         }
         else
         {
             QMessageBox::warning(this, "Warning", "Không tìm thấy file. Vui lòng thử lại!");
         }
     }
     else
     {
         QMessageBox::warning(this, "Warning", "Kết nối file ghi không thành công");
     }
 }
}
