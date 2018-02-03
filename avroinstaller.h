#ifndef AVROINSTALLER_H
#define AVROINSTALLER_H

#include <DMainWindow>
DWIDGET_USE_NAMESPACE
namespace Ui {
class AvroInstaller;
}

class AvroInstaller : public QMainWindow
{
    Q_OBJECT

public:
    explicit AvroInstaller(DMainWindow *parent = 0);
    ~AvroInstaller();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AvroInstaller *ui;
};

#endif // AVROINSTALLER_H
