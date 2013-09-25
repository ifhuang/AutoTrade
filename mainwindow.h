#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:    
    void new_swing_trade();    
    void new_combo_trade();
    void about();
    void activate_swing();
    void activate_combo();
    void update_swing_contract(QString contract);

private:
    Ui::MainWindow *ui;    
    QComboBox *selCon;
    QComboBox *orderType;
    QLineEdit *qty;
    QLineEdit *price;
    QComboBox *valid;
    QPushButton *buy;
    QPushButton *sell;

    int swing_counter;
    int combo_counter;

    void resizeEvent(QResizeEvent* event);
};

#endif // MAINWINDOW_H
