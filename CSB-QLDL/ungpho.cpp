#include "ungpho.h"
#include "ui_ungpho.h"

UngPho::UngPho(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UngPho)
{
    ui->setupUi(this);

    ui->pushButton->setDisabled(false);  ///Còn hiện mỗi nút thêm mới
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);
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
         query.prepare("SELECT * FROM tbl_suco");
         query.exec();

         //Create a blank table
         ui->tableWidget->setColumnCount(14);
         QStringList list_lables;
         list_lables << "id" << "Tên sự cố" << "id loại sự cố" << "thời gian" << "kinh độ" << "vĩ độ"
                                       << "đối tượng" << "DS tàu làm NV" << "Lực lượng phối hợp"
                                       << "Thời gian tiếp cận" << "KĐ tiếp cận" << "VĐ tiếp cận"
                                       << "Kết quả NV" << "Ghi chú";
         ui->tableWidget->setHorizontalHeaderLabels(list_lables);


         int rowcout = 0;
         while(query.next())
         {
            ui->tableWidget->insertRow(rowcout);
            QTableWidgetItem *id = new QTableWidgetItem;
            QTableWidgetItem *Ten = new QTableWidgetItem;
            QTableWidgetItem *Loai = new QTableWidgetItem;
            QTableWidgetItem *thoigian = new QTableWidgetItem;
            QTableWidgetItem *Kinhdo = new QTableWidgetItem;
            QTableWidgetItem *Vido = new QTableWidgetItem;
            QTableWidgetItem *Doituong = new QTableWidgetItem;
            QTableWidgetItem *DStauNV = new QTableWidgetItem;
            QTableWidgetItem *LLPhoihop = new QTableWidgetItem;
            QTableWidgetItem *ThoigianTiepCan = new QTableWidgetItem;
            QTableWidgetItem *KDTiepCan = new QTableWidgetItem;
            QTableWidgetItem *VDTiepCan = new QTableWidgetItem;
            QTableWidgetItem *KetQua = new QTableWidgetItem;
            QTableWidgetItem *Ghichu = new QTableWidgetItem;

            id->setText(query.value(0).toString());
            Ten->setText(query.value(1).toString());
            Loai->setText(query.value(2).toString());
            thoigian->setText(query.value(3).toString());
            Kinhdo->setText(query.value(4).toString());
            Vido->setText(query.value(5).toString());
            Doituong->setText(query.value(6).toString());
            DStauNV->setText(query.value(7).toString());
            LLPhoihop->setText(query.value(8).toString());
            ThoigianTiepCan->setText(query.value(9).toString());
            KDTiepCan->setText(query.value(10).toString());
            VDTiepCan->setText(query.value(11).toString());
            KetQua->setText(query.value(12).toString());
            Ghichu->setText(query.value(13).toString());

            ui->tableWidget->setItem(rowcout, 0, id);
            ui->tableWidget->setItem(rowcout, 1, Ten);
            ui->tableWidget->setItem(rowcout, 2, Loai);
            ui->tableWidget->setItem(rowcout, 3, thoigian);
            ui->tableWidget->setItem(rowcout, 4, Kinhdo);
            ui->tableWidget->setItem(rowcout, 5, Vido);
            ui->tableWidget->setItem(rowcout, 6, Doituong);
            ui->tableWidget->setItem(rowcout, 7, DStauNV);
            ui->tableWidget->setItem(rowcout, 8, LLPhoihop);
            ui->tableWidget->setItem(rowcout, 9, ThoigianTiepCan);
            ui->tableWidget->setItem(rowcout, 10, KDTiepCan);
            ui->tableWidget->setItem(rowcout, 11, VDTiepCan);
            ui->tableWidget->setItem(rowcout, 12, KetQua);
            ui->tableWidget->setItem(rowcout, 13, Ghichu);

            rowcout++;
         }
     }
     else
     {
         QMessageBox::warning(this, "report", "Database SuCo connection FAIL!");
     }
     connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(SectionDoubleClick(int, int)));
}

UngPho::~UngPho()
{
    delete ui;
}


void UngPho::on_pushButton_8_clicked()//HIỂN THỊ TẤT CẢ
{
    while (ui->tableWidget->rowCount() > 0)
    {
        ui->tableWidget->removeRow(0);
    }
    if(this->ok)
    {
        QSqlQuery query(db);
        query.prepare("SELECT * FROM tbl_suco");
        query.exec();

        //Create a blank table
        ui->tableWidget->setColumnCount(14);
        QStringList list_lables;
        list_lables << "id" << "Tên sự cố" << "id loại sự cố" << "thời gian" << "kinh độ" << "vĩ độ"
                                      << "đối tượng" << "DS tàu làm NV" << "Lực lượng phối hợp"
                                      << "Thời gian tiếp cận" << "KĐ tiếp cận" << "VĐ tiếp cận"
                                      << "Kết quả NV" << "Ghi chú";
        ui->tableWidget->setHorizontalHeaderLabels(list_lables);


        int rowcout = 0;
        while(query.next())
        {
            ui->tableWidget->insertRow(rowcout);
           QTableWidgetItem *id = new QTableWidgetItem;
           QTableWidgetItem *Ten = new QTableWidgetItem;
           QTableWidgetItem *Loai = new QTableWidgetItem;
           QTableWidgetItem *thoigian = new QTableWidgetItem;
           QTableWidgetItem *Kinhdo = new QTableWidgetItem;
           QTableWidgetItem *Vido = new QTableWidgetItem;
           QTableWidgetItem *Doituong = new QTableWidgetItem;
           QTableWidgetItem *DStauNV = new QTableWidgetItem;
           QTableWidgetItem *LLPhoihop = new QTableWidgetItem;
           QTableWidgetItem *ThoigianTiepCan = new QTableWidgetItem;
           QTableWidgetItem *KDTiepCan = new QTableWidgetItem;
           QTableWidgetItem *VDTiepCan = new QTableWidgetItem;
           QTableWidgetItem *KetQua = new QTableWidgetItem;
           QTableWidgetItem *Ghichu = new QTableWidgetItem;

           id->setText(query.value(0).toString());
           Ten->setText(query.value(1).toString());
           Loai->setText(query.value(2).toString());
           thoigian->setText(query.value(3).toString());
           Kinhdo->setText(query.value(4).toString());
           Vido->setText(query.value(5).toString());
           Doituong->setText(query.value(6).toString());
           DStauNV->setText(query.value(7).toString());
           LLPhoihop->setText(query.value(8).toString());
           ThoigianTiepCan->setText(query.value(9).toString());
           KDTiepCan->setText(query.value(10).toString());
           VDTiepCan->setText(query.value(11).toString());
           KetQua->setText(query.value(12).toString());
           Ghichu->setText(query.value(13).toString());

           ui->tableWidget->setItem(rowcout, 0, id);
           ui->tableWidget->setItem(rowcout, 1, Ten);
           ui->tableWidget->setItem(rowcout, 2, Loai);
           ui->tableWidget->setItem(rowcout, 3, thoigian);
           ui->tableWidget->setItem(rowcout, 4, Kinhdo);
           ui->tableWidget->setItem(rowcout, 5, Vido);
           ui->tableWidget->setItem(rowcout, 6, Doituong);
           ui->tableWidget->setItem(rowcout, 7, DStauNV);
           ui->tableWidget->setItem(rowcout, 8, LLPhoihop);
           ui->tableWidget->setItem(rowcout, 9, ThoigianTiepCan);
           ui->tableWidget->setItem(rowcout, 10, KDTiepCan);
           ui->tableWidget->setItem(rowcout, 11, VDTiepCan);
           ui->tableWidget->setItem(rowcout, 12, KetQua);
           ui->tableWidget->setItem(rowcout, 13, Ghichu);

           rowcout++;
        }
    }
    else
    {
        QMessageBox::warning(this, "report", "Database SuCo connection FAIL!");
    }
}

void UngPho::on_pushButton_9_clicked()//XUẤT FILE
{
    mdialog_XuatFile = new Dialog_XuatFile(this);
    mdialog_XuatFile->exec();

 if(mdialog_XuatFile->status == true)
 {
    QString FileName = "TypeFileName";
    QString pathToSave_01 = QFileDialog::getSaveFileUrl(this, tr("Select Folder"), FileName, tr("Microsoft Office 2007 (*.xlsx)")).toEncoded();


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

         QAxObject *cellsuco_id,*cellsuco_ten,*cellloaisuco_id,*cellsuco_thoigian,
                 *cellsuco_kinhdo,*cellsuco_vido,*cellsuco_doituong,*cellsuco_dstauxuly_rawtext,
                 *cellsuco_lucluongphoihop,*cellsuco_thoigiantiepcan,*celldiadiemtiepcan_kinhdo,*celldiadiemtiepcan_vido,
                 *cellsuco_ketqua,*cellsuco_ghichu;

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


         cellsuco_id = worksheet->querySubObject("Range(QVariant, QVariant)",A);
         cellsuco_ten = worksheet->querySubObject("Range(QVariant, QVariant)",B);
         cellloaisuco_id = worksheet->querySubObject("Range(QVariant, QVariant)",C);
         cellsuco_thoigian = worksheet->querySubObject("Range(QVariant, QVariant)",D);
         cellsuco_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",E);
         cellsuco_vido = worksheet->querySubObject("Range(QVariant, QVariant)",F);
         cellsuco_doituong = worksheet->querySubObject("Range(QVariant, QVariant)",G);
         cellsuco_dstauxuly_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",H);
         cellsuco_lucluongphoihop = worksheet->querySubObject("Range(QVariant, QVariant)",I);
         cellsuco_thoigiantiepcan = worksheet->querySubObject("Range(QVariant, QVariant)",J);
         celldiadiemtiepcan_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",K);
         celldiadiemtiepcan_vido = worksheet->querySubObject("Range(QVariant, QVariant)",L);
         cellsuco_ketqua = worksheet->querySubObject("Range(QVariant, QVariant)",M);
         cellsuco_ghichu = worksheet->querySubObject("Range(QVariant, QVariant)",N);


         cellsuco_id->dynamicCall("SetValue(const QVariant&)",QVariant("ID CỨU HỘ"));
         cellsuco_ten->dynamicCall("SetValue(const QVariant&)",QVariant("TÊN NHIỆM VỤ"));
         cellloaisuco_id->dynamicCall("SetValue(const QVariant&)",QVariant("THỜI GIAN THỰC HIỆN"));
         cellsuco_thoigian->dynamicCall("SetValue(const QVariant&)",QVariant("KINH ĐỘ TAI NẠN"));
         cellsuco_kinhdo->dynamicCall("SetValue(const QVariant&)",QVariant("VĨ ĐỘ TAI NẠN"));
         cellsuco_vido->dynamicCall("SetValue(const QVariant&)",QVariant("THỜI GIAN TIẾP CẬN"));
         cellsuco_doituong->dynamicCall("SetValue(const QVariant&)",QVariant("KINH ĐỘ TIẾP CẬN"));
         cellsuco_dstauxuly_rawtext->dynamicCall("SetValue(const QVariant&)",QVariant("VĨ ĐỘ TIẾP CẬN"));
         cellsuco_lucluongphoihop->dynamicCall("SetValue(const QVariant&)",QVariant("THỜI GIAN LAI DẮT"));
         cellsuco_thoigiantiepcan->dynamicCall("SetValue(const QVariant&)",QVariant("ĐỊA ĐIỂM LAI DẮT"));
         celldiadiemtiepcan_kinhdo->dynamicCall("SetValue(const QVariant&)",QVariant("SỐ NGƯỜI CỨU ĐƯỢC"));
         celldiadiemtiepcan_vido->dynamicCall("SetValue(const QVariant&)",QVariant("SỐ NGƯỜI MẤT TÍCH"));
         cellsuco_ketqua->dynamicCall("SetValue(const QVariant&)",QVariant("SỐ NGƯỜI TỬ VONG"));
         cellsuco_ghichu->dynamicCall("SetValue(const QVariant&)",QVariant("GHI CHÚ"));

         cellrow++;

         if(this->ok)
         {
             QString query_string = "SELECT * FROM tbl_suco WHERE DATE(suco_thoigian)>= '" + mdialog_XuatFile->NgayDau.toString("yyyy-MM-dd") + "' AND DATE(suco_thoigian)<= '" + mdialog_XuatFile->NgayCuoi.toString("yyyy-MM-dd") + "'";
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

                  cellsuco_id = worksheet->querySubObject("Range(QVariant, QVariant)",A);
                  cellsuco_ten = worksheet->querySubObject("Range(QVariant, QVariant)",B);
                  cellloaisuco_id = worksheet->querySubObject("Range(QVariant, QVariant)",C);
                  cellsuco_thoigian = worksheet->querySubObject("Range(QVariant, QVariant)",D);
                  cellsuco_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",E);
                  cellsuco_vido = worksheet->querySubObject("Range(QVariant, QVariant)",F);
                  cellsuco_doituong = worksheet->querySubObject("Range(QVariant, QVariant)",G);
                  cellsuco_dstauxuly_rawtext = worksheet->querySubObject("Range(QVariant, QVariant)",H);
                  cellsuco_lucluongphoihop = worksheet->querySubObject("Range(QVariant, QVariant)",I);
                  cellsuco_thoigiantiepcan = worksheet->querySubObject("Range(QVariant, QVariant)",J);
                  celldiadiemtiepcan_kinhdo = worksheet->querySubObject("Range(QVariant, QVariant)",K);
                  celldiadiemtiepcan_vido = worksheet->querySubObject("Range(QVariant, QVariant)",L);
                  cellsuco_ketqua = worksheet->querySubObject("Range(QVariant, QVariant)",M);
                  cellsuco_ghichu = worksheet->querySubObject("Range(QVariant, QVariant)",N);


                 cellsuco_id->dynamicCall("SetValue(const QVariant&)", qry.value(0).toString());
                 cellsuco_ten->dynamicCall("SetValue(const QVariant&)",qry.value(1).toString());
                 cellloaisuco_id->dynamicCall("SetValue(const QVariant&)", qry.value(2).toString());
                 cellsuco_thoigian->dynamicCall("SetValue(const QVariant&)", qry.value(3).toString());
                 cellsuco_kinhdo->dynamicCall("SetValue(const QVariant&)",qry.value(4).toString());
                 cellsuco_vido->dynamicCall("SetValue(const QVariant&)", qry.value(5).toString());
                 cellsuco_doituong->dynamicCall("SetValue(const QVariant&)", qry.value(6).toString());
                 cellsuco_dstauxuly_rawtext->dynamicCall("SetValue(const QVariant&)", qry.value(7).toString());
                 cellsuco_lucluongphoihop->dynamicCall("SetValue(const QVariant&)", qry.value(8).toString());
                 cellsuco_thoigiantiepcan->dynamicCall("SetValue(const QVariant&)", qry.value(9).toString());
                 celldiadiemtiepcan_kinhdo->dynamicCall("SetValue(const QVariant&)", qry.value(10).toString());
                 celldiadiemtiepcan_vido->dynamicCall("SetValue(const QVariant&)", qry.value(11).toString());
                 cellsuco_ketqua->dynamicCall("SetValue(const QVariant&)", qry.value(12).toString());
                 cellsuco_ghichu->dynamicCall("SetValue(const QVariant&)", qry.value(13).toString());

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

void UngPho::on_pushButton_2_clicked() //LƯU THÔNG TIN SỰ CỐ
{
    int suco_id;
    QString suco_ten = ui->lineEdit_TenSuCo->text();
    int loaisuco_id = ui->comboBox_LoaiSuCo->currentIndex();  //loại sự cố theo id
    QDateTime suco_thoigian = ui->dateTimeEdit_TGSuCo->dateTime();
    double suco_kinhdo = ui->lineEdit_KDSuCo->text().toDouble();
    double suco_vido = ui->lineEdit_VDSuCo->text().toDouble();
    QString suco_doituong = ui->lineEdit_DoituongGapSuCo->text();
    QString suco_dstauxuly_rawtext = ui->lineEdit_DSTauLamNV->text();
    QString suco_lucluongphoihop = ui->lineEdit_LLPhoiHop->text();
    QDateTime suco_thoigiantiepcan = ui->dateTimeEdit_TGTiepCan->dateTime();
    double diadiemtiepcan_kinhdo = ui->lineEdit_KDTiepCan->text().toDouble();
    double diadiemtiepcan_vido = ui->lineEdit_VDTiepCan->text().toDouble();
    QString suco_ketqua = ui->lineEdit_KetQua->text();
    QString suco_ghichu = ui->textEdit_GhiChu->toPlainText();


    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("INSERT INTO tbl_suco ( suco_ten, loaisuco_id, suco_thoigian, suco_kinhdo, suco_vido, "
                    "suco_doituong, suco_dstauxuly_rawtext, suco_lucluongphoihop, suco_thoigiantiepcan, "
                    "diadiemtiepcan_kinhdo, diadiemtiepcan_vido, suco_ketqua, suco_ghichu)"
                          "VALUES (:suco_ten, :loaisuco_id, :suco_thoigian, :suco_kinhdo, :suco_vido,"
                    ":suco_doituong, :suco_dstauxuly_rawtext, :suco_lucluongphoihop, :suco_thoigiantiepcan,"
                    ":diadiemtiepcan_kinhdo, :diadiemtiepcan_vido, :suco_ketqua, :suco_ghichu)");

      //  qry.bindValue(":id", 50);
        qry.bindValue(":suco_ten", suco_ten);
        qry.bindValue(":loaisuco_id", loaisuco_id);
        qry.bindValue(":suco_thoigian", suco_thoigian);
        qry.bindValue(":suco_kinhdo", suco_kinhdo);
        qry.bindValue(":suco_vido", suco_vido);
        qry.bindValue(":suco_doituong", suco_doituong);
        qry.bindValue(":suco_dstauxuly_rawtext", suco_dstauxuly_rawtext);
        qry.bindValue(":suco_lucluongphoihop", suco_lucluongphoihop);
        qry.bindValue(":suco_thoigiantiepcan", suco_thoigiantiepcan);
        qry.bindValue(":diadiemtiepcan_kinhdo", diadiemtiepcan_kinhdo);
        qry.bindValue(":diadiemtiepcan_vido", diadiemtiepcan_vido);
        qry.bindValue(":suco_ketqua", suco_ketqua);
        qry.bindValue(":suco_ghichu", suco_ghichu);


        suco_id = -1;
        if(qry.exec())
        {
            if(qry.lastInsertId().isValid())
            {
                suco_id = qry.lastInsertId().toInt();
            }
            QMessageBox::information(this, "report", "Thông tin sự cố được thêm thành công");
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
            QMessageBox::warning(this, "Warning", "Thêm thông tin không thành công. Vui lòng thử lại!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }

}

void UngPho::SectionDoubleClick(int row, int column)
{
    ui->pushButton->setDisabled(false);
    ui->pushButton_2->setDisabled(true); //ẩn nút lưu thông tin
    ui->pushButton_3->setDisabled(false);
    ui->pushButton_4->setDisabled(true); //ẩn nút cập nhật
    ui->pushButton_5->setDisabled(false);

    QString ID = ui->tableWidget->item(row, 0)->text();
    this->ID_DoubleCLick = ID.toInt();
//    qDebug()<< "ID_DoubleCLick: " << ID_DoubleCLick;

    //======THOÁT RA MÀN HÌNH CHÍNH --> TRUY VẤN THEO ID
    ui->tabWidget->setCurrentIndex(0);

    if(this->ok)
    {
       //Do some thing

        QSqlQuery query(db);
        QString QueryString = "SELECT * FROM tbl_suco WHERE suco_id LIKE '" + ID + "'";
        query.prepare(QueryString);
        query.exec();
        while(query.next())
        {
            ui->lineEdit_TenSuCo->setText(query.value(1).toString());
            ui->comboBox_LoaiSuCo->setCurrentIndex(query.value(2).toInt()); //set datetime
            ui->dateTimeEdit_TGSuCo->setDateTime(query.value(3).toDateTime());
            ui->lineEdit_KDSuCo->setText(query.value(4).toString());
            ui->lineEdit_VDSuCo->setText(query.value(5).toString());
            ui->lineEdit_DoituongGapSuCo->setText(query.value(6).toString());
            ui->lineEdit_DSTauLamNV->setText(query.value(7).toString());
            ui->lineEdit_LLPhoiHop->setText(query.value(8).toString());
            ui->dateTimeEdit_TGTiepCan->setDateTime(query.value(9).toDateTime());
            ui->lineEdit_KDTiepCan->setText(query.value(10).toString());
            ui->lineEdit_VDTiepCan->setText(query.value(11).toString());
            ui->lineEdit_KetQua->setText(query.value(12).toString());
            ui->textEdit_GhiChu->setText(query.value(13).toString());
        }
        //setDisabled all line edit
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
            {
               le->setDisabled(true);
            }
            ui->textEdit_GhiChu->setDisabled(true);
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Database connect fail!");
    }
}

void UngPho::on_pushButton_4_clicked()//CẬP NHẬT THÔNG TIN ĐÃ SỬA
{
    //Lấy ra các giá trị đã được sửa từ ui
    int suco_id = this->ID_DoubleCLick;
    QString suco_ten = ui->lineEdit_TenSuCo->text();
    int loaisuco_id = ui->comboBox_LoaiSuCo->currentIndex();  //loại sự cố theo id
    QDateTime suco_thoigian = ui->dateTimeEdit_TGSuCo->dateTime();
    double suco_kinhdo = ui->lineEdit_KDSuCo->text().toDouble();
    double suco_vido = ui->lineEdit_VDSuCo->text().toDouble();
    QString suco_doituong = ui->lineEdit_DoituongGapSuCo->text();
    QString suco_dstauxuly_rawtext = ui->lineEdit_DSTauLamNV->text();
    QString suco_lucluongphoihop = ui->lineEdit_LLPhoiHop->text();
    QDateTime suco_thoigiantiepcan = ui->dateTimeEdit_TGTiepCan->dateTime();
    double diadiemtiepcan_kinhdo = ui->lineEdit_KDTiepCan->text().toDouble();
    double diadiemtiepcan_vido = ui->lineEdit_VDTiepCan->text().toDouble();
    QString suco_ketqua = ui->lineEdit_KetQua->text();
    QString suco_ghichu = ui->textEdit_GhiChu->toPlainText();

    //=====================================TEST INSERT DATABASE
    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("UPDATE tbl_suco SET suco_ten=:suco_ten, loaisuco_id=:loaisuco_id, suco_thoigian=:suco_thoigian, suco_kinhdo=:suco_kinhdo, suco_vido=:suco_vido, "
                    "suco_doituong=:suco_doituong, suco_dstauxuly_rawtext=:suco_dstauxuly_rawtext, suco_lucluongphoihop=:suco_lucluongphoihop, suco_thoigiantiepcan=:suco_thoigiantiepcan, "
                    "diadiemtiepcan_kinhdo=:diadiemtiepcan_kinhdo, diadiemtiepcan_vido=:diadiemtiepcan_vido, suco_ketqua=:suco_ketqua, suco_ghichu=:suco_ghichu "
                          "WHERE suco_id=:suco_id");


        qry.bindValue(":suco_ten", suco_ten);
        qry.bindValue(":loaisuco_id", loaisuco_id);
        qry.bindValue(":suco_thoigian", suco_thoigian);
        qry.bindValue(":suco_kinhdo", suco_kinhdo);
        qry.bindValue(":suco_vido", suco_vido);
        qry.bindValue(":suco_doituong", suco_doituong);
        qry.bindValue(":suco_dstauxuly_rawtext", suco_dstauxuly_rawtext);
        qry.bindValue(":suco_lucluongphoihop", suco_lucluongphoihop);
        qry.bindValue(":suco_thoigiantiepcan", suco_thoigiantiepcan);
        qry.bindValue(":diadiemtiepcan_kinhdo", diadiemtiepcan_kinhdo);
        qry.bindValue(":diadiemtiepcan_vido", diadiemtiepcan_vido);
        qry.bindValue(":suco_ketqua", suco_ketqua);
        qry.bindValue(":suco_ghichu", suco_ghichu);

        qry.bindValue(":suco_id", suco_id);

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

void UngPho::on_pushButton_5_clicked()  //XÓA SỰ CỐ HIỆN TẠI
{
    if(this->ok)
    {
        QSqlQuery qry(this->db);
        qry.prepare("DELETE FROM tbl_suco WHERE suco_id=:suco_id");
        qry.bindValue(":suco_id", this->ID_DoubleCLick);

        if(qry.exec())
        {
            QMessageBox::information(this, "Thông báo", "Xóa thông tin thành công!");
            foreach(QLineEdit* le, findChildren<QLineEdit*>())
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
            QMessageBox::warning(this, "Warning", "Xóa thông tin không thành công. Vui lòng thử lại!");
        }
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Kết nối cơ sở dữ liệu không thành công. Vui lòng thử lại!");
    }
}

void UngPho::on_pushButton_3_clicked()  //SỬA
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

    foreach(QTextEdit* te, findChildren<QTextEdit*>())
    {
       te->setDisabled(false);
    }
}

void UngPho::on_pushButton_clicked()
{
    ui->pushButton->setDisabled(true);  ///Còn hiện mỗi nút thêm mới
    ui->pushButton_2->setDisabled(false);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);
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
