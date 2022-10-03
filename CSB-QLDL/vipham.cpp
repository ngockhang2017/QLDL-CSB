#include "vipham.h"
#include "ui_vipham.h"

ViPham::ViPham(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViPham)
{
    ui->setupUi(this);

    ui->pushButton_6->setDisabled(false);  ///Hiện mỗi nút thêm mới
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);

    //Connect to Database
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

        if(ok)
        {
            QSqlQuery query(db);
            query.prepare("SELECT * FROM tbl_suvu");
            query.exec();

            //Create a blank table
            ui->tableWidget->setColumnCount(15);
            QStringList list_lables;
            list_lables << "id" << "Tên sự vụ" << "ID Loại vi phạm" << "Thời gian vi phạm" << "Kinh độ" << "Vĩ độ"
                                          << "Thời gian tiếp cận" << "KĐ tiếp cận" << "VĐ tiếp cận"
                                          << "Thời gian lai dắt" << "Địa điểm lai dắt" << "Số người bắt giữ"
                                          << "Ghi chú" << "DS tàu vi phạm" << "DS tàu làm NV";
            ui->tableWidget->setHorizontalHeaderLabels(list_lables);


            int rowcout = 0;
            while(query.next())
            {
                ui->tableWidget->insertRow(rowcout);
               QTableWidgetItem *id = new QTableWidgetItem;
               QTableWidgetItem *Ten = new QTableWidgetItem;
               QTableWidgetItem *Loai = new QTableWidgetItem;
               QTableWidgetItem *thoigianVP = new QTableWidgetItem;
               QTableWidgetItem *Kinhdo = new QTableWidgetItem;
               QTableWidgetItem *Vido = new QTableWidgetItem;
               QTableWidgetItem *thoigianTC = new QTableWidgetItem;
               QTableWidgetItem *KDtiepcan = new QTableWidgetItem;
               QTableWidgetItem *VDtiepcan = new QTableWidgetItem;
               QTableWidgetItem *ThoigianLaiDat = new QTableWidgetItem;
               QTableWidgetItem *DDLaidat = new QTableWidgetItem;
               QTableWidgetItem *SonguoiwBatgiu = new QTableWidgetItem;
               QTableWidgetItem *Ghichu = new QTableWidgetItem;
               QTableWidgetItem *DStauVP = new QTableWidgetItem;
               QTableWidgetItem *DStauLamNV = new QTableWidgetItem;

               id->setText(query.value(0).toString());
               Ten->setText(query.value(1).toString());
               Loai->setText(query.value(2).toString());
               thoigianVP->setText(query.value(3).toString());
               Kinhdo->setText(query.value(4).toString());
               Vido->setText(query.value(5).toString());
               thoigianTC->setText(query.value(6).toString());
               KDtiepcan->setText(query.value(7).toString());
               VDtiepcan->setText(query.value(8).toString());
               ThoigianLaiDat->setText(query.value(9).toString());
               DDLaidat->setText(query.value(10).toString());
               SonguoiwBatgiu->setText(query.value(11).toString());
               Ghichu->setText(query.value(12).toString());
               DStauVP->setText(query.value(13).toString());
               DStauLamNV->setText(query.value(14).toString());

               ui->tableWidget->setItem(rowcout, 0, id);
               ui->tableWidget->setItem(rowcout, 1, Ten);
               ui->tableWidget->setItem(rowcout, 2, Loai);
               ui->tableWidget->setItem(rowcout, 3, thoigianVP);
               ui->tableWidget->setItem(rowcout, 4, Kinhdo);
               ui->tableWidget->setItem(rowcout, 5, Vido);
               ui->tableWidget->setItem(rowcout, 6, thoigianTC);
               ui->tableWidget->setItem(rowcout, 7, KDtiepcan);
               ui->tableWidget->setItem(rowcout, 8, VDtiepcan);
               ui->tableWidget->setItem(rowcout, 9, ThoigianLaiDat);
               ui->tableWidget->setItem(rowcout, 10, DDLaidat);
               ui->tableWidget->setItem(rowcout, 11, SonguoiwBatgiu);
               ui->tableWidget->setItem(rowcout, 12, Ghichu);
               ui->tableWidget->setItem(rowcout, 13, DStauVP);
               ui->tableWidget->setItem(rowcout, 14, DStauLamNV);

               rowcout++;
            }
        }

        connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(SectionDoubleClick(int, int)));
}

ViPham::~ViPham()
{
    delete ui;  
}

void ViPham::on_pushButton_22_clicked()//HIỂN THỊ TẤT CẢ
{
    while(ui->tableWidget->rowCount()> 0)
    {
     ui->tableWidget->removeRow(0);
    }

    if(this->ok)
    {
        QSqlQuery query(db);
        query.prepare("SELECT * FROM tbl_suvu");
        query.exec();

        //Create a blank table
        ui->tableWidget->setColumnCount(15);
        QStringList list_lables;
        list_lables << "id" << "Tên sự vụ" << "Loại vi phạm" << "Thời gian vi phạm" << "Kinh độ" << "Vĩ độ"
                                      << "Thời gian tiếp cận" << "KĐ tiếp cận" << "VĐ tiếp cận"
                                      << "Thời gian lai dắt" << "Địa điểm lai dắt" << "Số người bắt giữ"
                                      << "Ghi chú" << "DS tàu vi phạm" << "DS tàu làm NV";
        ui->tableWidget->setHorizontalHeaderLabels(list_lables);


        int rowcout = 0;
        while(query.next())
        {
            ui->tableWidget->insertRow(rowcout);
           QTableWidgetItem *id = new QTableWidgetItem;
           QTableWidgetItem *Ten = new QTableWidgetItem;
           QTableWidgetItem *Loai = new QTableWidgetItem;
           QTableWidgetItem *thoigianVP = new QTableWidgetItem;
           QTableWidgetItem *Kinhdo = new QTableWidgetItem;
           QTableWidgetItem *Vido = new QTableWidgetItem;
           QTableWidgetItem *thoigianTC = new QTableWidgetItem;
           QTableWidgetItem *KDtiepcan = new QTableWidgetItem;
           QTableWidgetItem *VDtiepcan = new QTableWidgetItem;
           QTableWidgetItem *ThoigianLaiDat = new QTableWidgetItem;
           QTableWidgetItem *DDLaidat = new QTableWidgetItem;
           QTableWidgetItem *SonguoiwBatgiu = new QTableWidgetItem;
           QTableWidgetItem *Ghichu = new QTableWidgetItem;
           QTableWidgetItem *DStauVP = new QTableWidgetItem;
           QTableWidgetItem *DStauLamNV = new QTableWidgetItem;

           id->setText(query.value(0).toString());
           Ten->setText(query.value(1).toString());
           Loai->setText(query.value(2).toString());
           thoigianVP->setText(query.value(3).toString());
           Kinhdo->setText(query.value(4).toString());
           Vido->setText(query.value(5).toString());
           thoigianTC->setText(query.value(6).toString());
           KDtiepcan->setText(query.value(7).toString());
           VDtiepcan->setText(query.value(8).toString());
           ThoigianLaiDat->setText(query.value(9).toString());
           DDLaidat->setText(query.value(10).toString());
           SonguoiwBatgiu->setText(query.value(11).toString());
           Ghichu->setText(query.value(12).toString());
           DStauVP->setText(query.value(13).toString());
           DStauLamNV->setText(query.value(14).toString());

           ui->tableWidget->setItem(rowcout, 0, id);
           ui->tableWidget->setItem(rowcout, 1, Ten);
           ui->tableWidget->setItem(rowcout, 2, Loai);
           ui->tableWidget->setItem(rowcout, 3, thoigianVP);
           ui->tableWidget->setItem(rowcout, 4, Kinhdo);
           ui->tableWidget->setItem(rowcout, 5, Vido);
           ui->tableWidget->setItem(rowcout, 6, thoigianTC);
           ui->tableWidget->setItem(rowcout, 7, KDtiepcan);
           ui->tableWidget->setItem(rowcout, 8, VDtiepcan);
           ui->tableWidget->setItem(rowcout, 9, ThoigianLaiDat);
           ui->tableWidget->setItem(rowcout, 10, DDLaidat);
           ui->tableWidget->setItem(rowcout, 11, SonguoiwBatgiu);
           ui->tableWidget->setItem(rowcout, 12, Ghichu);
           ui->tableWidget->setItem(rowcout, 13, DStauVP);
           ui->tableWidget->setItem(rowcout, 14, DStauLamNV);

           rowcout++;
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "SuVu databse connect Fail!");
    }
}

void ViPham::on_pushButton_7_clicked() //LƯU THÔNG TIN
{
    int suvu_id;
    QString suvu_ten = ui->lineEdit_TenNV->text();
    int loaisuvu_id = ui->comboBox_LoaiVP->currentIndex();
    QDateTime suvu_thoigian = ui->dateTimeEdit_TGVP->dateTime();
    double suvu_kinhdo = ui->lineEdit_KDViPham->text().toDouble();
    double suvu_vido = ui->lineEdit_VDViPham->text().toDouble();
    QDateTime suvu_thoigiantiepcan = ui->dateTimeEdit_TiepCan->dateTime();
    double diadiemtiepcan_kinhdo = ui->lineEdit_KDTiepCan->text().toDouble();
    double diadiemtiepcan_vido = ui->lineEdit_VDTiepCan->text().toDouble();
    QDateTime suvu_thoigianlaidat = ui->dateTimeEdit_LaiDat->dateTime();
    QString suvu_diadiemlaidat = ui->lineEdit_DDLaidat->text();
    int suvu_songuoibatduoc = ui->lineEdit_SoNguoiBatGiu->text().toUInt();
    QString suvu_ghichu = ui->textEdit_Ghichu->toPlainText();
    QString suvu_dstauvipham_rawtext = ui->lineEdit_DSTauViPham->text();
    QString suvu_dstaudixuly_rawtext = ui->lineEdit_DSTauXuLy->text();


    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("INSERT INTO tbl_suvu ( suvu_ten, loaisuvu_id, suvu_thoigian, suvu_kinhdo, suvu_vido, "
                    "suvu_thoigiantiepcan, diadiemtiepcan_kinhdo, diadiemtiepcan_vido, suvu_thoigianlaidat, "
                    "suvu_diadiemlaidat, suvu_songuoibatduoc, suvu_ghichu, suvu_dstauvipham_rawtext, suvu_dstaudixuly_rawtext)"
                          "VALUES (:suvu_ten, :loaisuvu_id, :suvu_thoigian, :suvu_kinhdo, :suvu_vido,"
                    ":suvu_thoigiantiepcan, :diadiemtiepcan_kinhdo, :diadiemtiepcan_vido, :suvu_thoigianlaidat,"
                    ":suvu_diadiemlaidat, :suvu_songuoibatduoc, :suvu_ghichu, :suvu_dstauvipham_rawtext, :suvu_dstaudixuly_rawtext)");

      //  qry.bindValue(":id", 50);
        qry.bindValue(":suvu_ten", suvu_ten);
        qry.bindValue(":loaisuvu_id", loaisuvu_id);
        qry.bindValue(":suvu_thoigian", suvu_thoigian);
        qry.bindValue(":suvu_kinhdo", suvu_kinhdo);
        qry.bindValue(":suvu_vido", suvu_vido);
        qry.bindValue(":suvu_thoigiantiepcan", suvu_thoigiantiepcan);
        qry.bindValue(":diadiemtiepcan_kinhdo", diadiemtiepcan_kinhdo);
        qry.bindValue(":diadiemtiepcan_vido", diadiemtiepcan_vido);
        qry.bindValue(":suvu_thoigianlaidat", suvu_thoigianlaidat);
        qry.bindValue(":suvu_diadiemlaidat", suvu_diadiemlaidat);
        qry.bindValue(":suvu_songuoibatduoc", suvu_songuoibatduoc);
        qry.bindValue(":suvu_ghichu", suvu_ghichu);
        qry.bindValue(":suvu_dstauvipham_rawtext", suvu_dstauvipham_rawtext);
        qry.bindValue(":suvu_dstaudixuly_rawtext", suvu_dstaudixuly_rawtext);

        suvu_id = -1;
        if(qry.exec())
        {
            if(qry.lastInsertId().isValid())
            {
                suvu_id = qry.lastInsertId().toInt();
            }
            QMessageBox::information(this, "report", "Thông tin sự vụ vi phạm được thêm thành công");
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

            ui->pushButton_6->setDisabled(false);  ///Hiện mỗi nút thêm mới
            ui->pushButton_7->setDisabled(true);
            ui->pushButton_8->setDisabled(true);
            ui->pushButton_9->setDisabled(true);
            ui->pushButton_10->setDisabled(true);
        }
        else
        {
           QMessageBox::warning(this, "Warning", "Thêm thông tin không thành công. Vui lòng thử lại!");
        }

    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }

}

void ViPham::SectionDoubleClick(int row, int column)
{
    ui->pushButton_6->setDisabled(false);
    ui->pushButton_7->setDisabled(true); //ẩn nút lưu thông tin
    ui->pushButton_8->setDisabled(false);
    ui->pushButton_9->setDisabled(true); //ẩn nút cập nhật
    ui->pushButton_10->setDisabled(false);
//    QTableWidgetItem section;

    //========LẤY ID
    QString ID = ui->tableWidget->item(row, 0)->text();
    this->ID_DoubleCLick = ID.toInt();

    //======THOÁT RA MÀN HÌNH CHÍNH --> TRUY VẤN THEO ID
    ui->tabWidget_2->setCurrentIndex(0);

    if(this->ok)
    {
       //Do some thing

        QSqlQuery query(db);
        QString QueryString = "SELECT * FROM tbl_suvu WHERE suvu_id LIKE '" + ID + "'";
        query.prepare(QueryString);
        query.exec();
        while(query.next())
        {
            ui->lineEdit_TenNV->setText(query.value(1).toString());
            ui->comboBox_LoaiVP->setCurrentIndex(query.value(2).toInt()); //set datetime
            ui->dateTimeEdit_TGVP->setDateTime(query.value(3).toDateTime());
            ui->lineEdit_KDViPham->setText(query.value(4).toString());
            ui->lineEdit_VDViPham->setText(query.value(5).toString());
            ui->dateTimeEdit_TiepCan->setDateTime(query.value(6).toDateTime());
            ui->lineEdit_KDTiepCan->setText(query.value(7).toString());
            ui->lineEdit_VDTiepCan->setText(query.value(8).toString());
            ui->dateTimeEdit_LaiDat->setDateTime(query.value(9).toDateTime());
            ui->lineEdit_DDLaidat->setText(query.value(10).toString());
            ui->lineEdit_SoNguoiBatGiu->setText(query.value(11).toString());
            ui->textEdit_Ghichu->setText(query.value(12).toString());
            ui->lineEdit_DSTauViPham->setText(query.value(13).toString());
            ui->lineEdit_DSTauXuLy->setText(query.value(14).toString());
        }
        //setDisabled all line edit
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
               le->setDisabled(true);
            }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Database connect Fail!");
    }
}

void ViPham::on_pushButton_8_clicked()  //SỬA THÔNG TIN
{
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(false); //hiện cập nhật
    ui->pushButton_10->setDisabled(true);

    //BẤT TẤT CẢ CÁC LINE EDIT
    foreach(QLineEdit* le, findChildren<QLineEdit*>())
    {
        le->setDisabled(false);
    }
}

void ViPham::on_pushButton_9_clicked()  //CẬP NHẬT
{
    int suvu_id = this->ID_DoubleCLick;
    QString suvu_ten = ui->lineEdit_TenNV->text();
    int loaisuvu_id = ui->comboBox_LoaiVP->currentIndex();
    QDateTime suvu_thoigian = ui->dateTimeEdit_TGVP->dateTime();
    double suvu_kinhdo = ui->lineEdit_KDViPham->text().toDouble();
    double suvu_vido = ui->lineEdit_VDViPham->text().toDouble();
    QDateTime suvu_thoigiantiepcan = ui->dateTimeEdit_TiepCan->dateTime();
    double diadiemtiepcan_kinhdo = ui->lineEdit_KDTiepCan->text().toDouble();
    double diadiemtiepcan_vido = ui->lineEdit_VDTiepCan->text().toDouble();
    QDateTime suvu_thoigianlaidat = ui->dateTimeEdit_LaiDat->dateTime();
    QString suvu_diadiemlaidat = ui->lineEdit_DDLaidat->text();
    int suvu_songuoibatduoc = ui->lineEdit_SoNguoiBatGiu->text().toUInt();
    QString suvu_ghichu = ui->textEdit_Ghichu->toPlainText();
    QString suvu_dstauvipham_rawtext = ui->lineEdit_DSTauViPham->text();
    QString suvu_dstaudixuly_rawtext = ui->lineEdit_DSTauXuLy->text();


    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("UPDATE tbl_suvu SET suvu_ten=:suvu_ten, loaisuvu_id=:loaisuvu_id, suvu_thoigian=:suvu_thoigian, suvu_kinhdo=:suvu_kinhdo, suvu_vido=:suvu_kinhdo, "
                    "suvu_thoigiantiepcan=:suvu_thoigiantiepcan, diadiemtiepcan_kinhdo=:diadiemtiepcan_kinhdo, diadiemtiepcan_vido=:diadiemtiepcan_vido, suvu_thoigianlaidat=:suvu_thoigianlaidat, "
                    "suvu_diadiemlaidat=:suvu_diadiemlaidat, suvu_songuoibatduoc=:suvu_songuoibatduoc, suvu_ghichu=:suvu_ghichu, suvu_dstauvipham_rawtext=:suvu_dstauvipham_rawtext, suvu_dstaudixuly_rawtext=:suvu_dstaudixuly_rawtext "
                          "WHERE suvu_id=:suvu_id");

      //  qry.bindValue(":id", 50);
        qry.bindValue(":suvu_ten", suvu_ten);
        qry.bindValue(":loaisuvu_id", loaisuvu_id);
        qry.bindValue(":suvu_thoigian", suvu_thoigian);
        qry.bindValue(":suvu_kinhdo", suvu_kinhdo);
        qry.bindValue(":suvu_vido", suvu_vido);
        qry.bindValue(":suvu_thoigiantiepcan", suvu_thoigiantiepcan);
        qry.bindValue(":diadiemtiepcan_kinhdo", diadiemtiepcan_kinhdo);
        qry.bindValue(":diadiemtiepcan_vido", diadiemtiepcan_vido);
        qry.bindValue(":suvu_thoigianlaidat", suvu_thoigianlaidat);
        qry.bindValue(":suvu_diadiemlaidat", suvu_diadiemlaidat);
        qry.bindValue(":suvu_songuoibatduoc", suvu_songuoibatduoc);
        qry.bindValue(":suvu_ghichu", suvu_ghichu);
        qry.bindValue(":suvu_dstauvipham_rawtext", suvu_dstauvipham_rawtext);
        qry.bindValue(":suvu_dstaudixuly_rawtext", suvu_dstaudixuly_rawtext);

        qry.bindValue(":suvu_id", suvu_id);

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
            ui->pushButton_6->setDisabled(false);  ///Còn hiện mỗi nút thêm mới
            ui->pushButton_7->setDisabled(true);
            ui->pushButton_8->setDisabled(true);
            ui->pushButton_9->setDisabled(true);
            ui->pushButton_10->setDisabled(true);
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

void ViPham::on_pushButton_10_clicked() //XÓA
{
    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("DELETE FROM tbl_suvu WHERE suvu_id=:suvu_id");
        qry.bindValue(":suvu_id", this->ID_DoubleCLick);

        if(qry.exec())
        {
            QMessageBox::information(this, "Thông báo", "Xóa thông tin sự vụ thành công!");
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
                le->clear();
            }
            ui->pushButton_6->setDisabled(false);  ///Còn hiện mỗi nút thêm mới
            ui->pushButton_7->setDisabled(true);
            ui->pushButton_8->setDisabled(true);
            ui->pushButton_9->setDisabled(true);
            ui->pushButton_10->setDisabled(true);
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }
}

void ViPham::on_pushButton_6_clicked()
{
    ui->pushButton_6->setDisabled(true);  ///Hiện mỗi nút thêm mới
    ui->pushButton_7->setDisabled(false);
    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);

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

void ViPham::on_pushButton_23_clicked() //XUẤT FILE
{
    mdialog_XuatFile = new Dialog_XuatFile(this);
    mdialog_XuatFile->exec();

 if(mdialog_XuatFile->status == true)
 {
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

         QAxObject *cellsuvu_id,*cellsuvu_ten,*cellloaisuvu_id,*cellsuvu_thoigian,
                 *cellsuvu_kinhdo,*cellsuvu_vido,*cellsuvu_thoigiantiepcan,*celldiadiemtiepcan_kinhdo,
                 *celldiadiemtiepcan_vido,*cellsuvu_thoigianlaidat,*cellsuvu_diadiemlaidat,*cellsuvu_songuoibatduoc,
                 *cellsuvu_ghichu,*cellsuvu_dstauvipham_rawtext, *cellsuvu_dstaudixuly_rawtext;

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


         cellsuvu_id = worksheet->querySubObject("Range(QVariant, QVariant)",A);
         cellsuvu_ten = worksheet->querySubObject("Range(QVariant, QVariant)",B);
         cellloaisuvu_id = worksheet->querySubObject("Range(QVariant, QVariant)",C);
         cellsuvu_thoigian = worksheet->querySubObject("Range(QVariant, QVariant)",D);
         cellsuvu_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",E);
         cellsuvu_vido = worksheet->querySubObject("Range(QVariant, QVariant)",F);
         cellsuvu_thoigiantiepcan = worksheet->querySubObject("Range(QVariant, QVariant)",G);
         celldiadiemtiepcan_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",H);
         celldiadiemtiepcan_vido = worksheet->querySubObject("Range(QVariant, QVariant)",I);
         cellsuvu_thoigianlaidat = worksheet->querySubObject("Range(QVariant, QVariant)",J);
         cellsuvu_diadiemlaidat = worksheet->querySubObject("Range(QVariant, QVariant)",K);
         cellsuvu_songuoibatduoc = worksheet->querySubObject("Range(QVariant, QVariant)",L);
         cellsuvu_ghichu = worksheet->querySubObject("Range(QVariant, QVariant)",M);
         cellsuvu_dstauvipham_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",N);
         cellsuvu_dstaudixuly_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",O);



         cellsuvu_id->dynamicCall("SetValue(const QVariant&)",QVariant("ID CỨU HỘ"));
         cellsuvu_ten->dynamicCall("SetValue(const QVariant&)",QVariant("TÊN NHIỆM VỤ"));
         cellloaisuvu_id->dynamicCall("SetValue(const QVariant&)",QVariant("THỜI GIAN THỰC HIỆN"));
         cellsuvu_thoigian->dynamicCall("SetValue(const QVariant&)",QVariant("KINH ĐỘ TAI NẠN"));
         cellsuvu_kinhdo->dynamicCall("SetValue(const QVariant&)",QVariant("VĨ ĐỘ TAI NẠN"));
         cellsuvu_vido->dynamicCall("SetValue(const QVariant&)",QVariant("THỜI GIAN TIẾP CẬN"));
         cellsuvu_thoigiantiepcan->dynamicCall("SetValue(const QVariant&)",QVariant("KINH ĐỘ TIẾP CẬN"));
         celldiadiemtiepcan_kinhdo->dynamicCall("SetValue(const QVariant&)",QVariant("VĨ ĐỘ TIẾP CẬN"));
         celldiadiemtiepcan_vido->dynamicCall("SetValue(const QVariant&)",QVariant("THỜI GIAN LAI DẮT"));
         cellsuvu_thoigianlaidat->dynamicCall("SetValue(const QVariant&)",QVariant("ĐỊA ĐIỂM LAI DẮT"));
         cellsuvu_diadiemlaidat->dynamicCall("SetValue(const QVariant&)",QVariant("SỐ NGƯỜI CỨU ĐƯỢC"));
         cellsuvu_songuoibatduoc->dynamicCall("SetValue(const QVariant&)",QVariant("SỐ NGƯỜI MẤT TÍCH"));
         cellsuvu_ghichu->dynamicCall("SetValue(const QVariant&)",QVariant("SỐ NGƯỜI TỬ VONG"));
         cellsuvu_dstauvipham_rawtext->dynamicCall("SetValue(const QVariant&)",QVariant("GHI CHÚ"));
         cellsuvu_dstaudixuly_rawtext->dynamicCall("SetValue(const QVariant&)",QVariant("DS TÀU THỰC HIỆN NV"));

         cellrow++;

         if(this->ok)
         {
             QString query_string = "SELECT * FROM tbl_suvu WHERE DATE(suvu_thoigian)>= '" + mdialog_XuatFile->NgayDau.toString("yyyy-MM-dd") + "' AND DATE(suvu_thoigian)<= '" + mdialog_XuatFile->NgayCuoi.toString("yyyy-MM-dd") + "'";
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

                  cellsuvu_id = worksheet->querySubObject("Range(QVariant, QVariant)",A);
                  cellsuvu_ten = worksheet->querySubObject("Range(QVariant, QVariant)",B);
                  cellloaisuvu_id = worksheet->querySubObject("Range(QVariant, QVariant)",C);
                  cellsuvu_thoigian = worksheet->querySubObject("Range(QVariant, QVariant)",D);
                  cellsuvu_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",E);
                  cellsuvu_vido = worksheet->querySubObject("Range(QVariant, QVariant)",F);
                  cellsuvu_thoigiantiepcan = worksheet->querySubObject("Range(QVariant, QVariant)",G);
                  celldiadiemtiepcan_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",H);
                  celldiadiemtiepcan_vido = worksheet->querySubObject("Range(QVariant, QVariant)",I);
                  cellsuvu_thoigianlaidat = worksheet->querySubObject("Range(QVariant, QVariant)",J);
                  cellsuvu_diadiemlaidat = worksheet->querySubObject("Range(QVariant, QVariant)",K);
                  cellsuvu_songuoibatduoc = worksheet->querySubObject("Range(QVariant, QVariant)",L);
                  cellsuvu_ghichu = worksheet->querySubObject("Range(QVariant, QVariant)",M);
                  cellsuvu_dstauvipham_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",N);
                  cellsuvu_dstaudixuly_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",O);



                 cellsuvu_id->dynamicCall("SetValue(const QVariant&)", qry.value(0).toString());
                 cellsuvu_ten->dynamicCall("SetValue(const QVariant&)",qry.value(1).toString());
                 cellloaisuvu_id->dynamicCall("SetValue(const QVariant&)", qry.value(2).toString());
                 cellsuvu_thoigian->dynamicCall("SetValue(const QVariant&)", qry.value(3).toString());
                 cellsuvu_kinhdo->dynamicCall("SetValue(const QVariant&)",qry.value(4).toString());
                 cellsuvu_vido->dynamicCall("SetValue(const QVariant&)", qry.value(5).toString());
                 cellsuvu_thoigiantiepcan->dynamicCall("SetValue(const QVariant&)", qry.value(6).toString());
                 celldiadiemtiepcan_kinhdo->dynamicCall("SetValue(const QVariant&)", qry.value(7).toString());
                 celldiadiemtiepcan_vido->dynamicCall("SetValue(const QVariant&)", qry.value(8).toString());
                 cellsuvu_thoigianlaidat->dynamicCall("SetValue(const QVariant&)", qry.value(9).toString());
                 cellsuvu_diadiemlaidat->dynamicCall("SetValue(const QVariant&)", qry.value(10).toString());
                 cellsuvu_songuoibatduoc->dynamicCall("SetValue(const QVariant&)", qry.value(11).toString());
                 cellsuvu_ghichu->dynamicCall("SetValue(const QVariant&)", qry.value(12).toString());
                 cellsuvu_dstauvipham_rawtext->dynamicCall("SetValue(const QVariant&)", qry.value(13).toString());
                 cellsuvu_dstaudixuly_rawtext->dynamicCall("SetValue(const QVariant&)", qry.value(14).toString());

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
