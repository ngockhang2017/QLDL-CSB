#ifndef DIALOG_XUATFILE_H
#define DIALOG_XUATFILE_H

#include <QDialog>
#include<QDate>

namespace Ui {
class Dialog_XuatFile;
}

class Dialog_XuatFile : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_XuatFile(QWidget *parent = nullptr);
    ~Dialog_XuatFile();
    QDate NgayDau, NgayCuoi;
    bool status = false;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog_XuatFile *ui;
};

#endif // DIALOG_XUATFILE_H
