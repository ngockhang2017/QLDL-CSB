#ifndef DIALOG_CUUHO_H
#define DIALOG_CUUHO_H

#include <QDialog>

namespace Ui {
class Dialog_CuuHo;
}

class Dialog_CuuHo : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_CuuHo(QWidget *parent = nullptr);
    ~Dialog_CuuHo();

private:
    Ui::Dialog_CuuHo *ui;
};

#endif // DIALOG_CUUHO_H
