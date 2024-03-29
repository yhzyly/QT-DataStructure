#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TestWindow; }
QT_END_NAMESPACE

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    TestWindow(QWidget *parent = nullptr);
    ~TestWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton2_clicked(bool checked);

private:
    Ui::TestWindow *ui;
};
#endif // TESTWINDOW_H
