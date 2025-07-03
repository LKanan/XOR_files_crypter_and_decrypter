#pragma once
#include <QWidget>
#include "../model/cryptomodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseButton_clicked();
    void on_actionButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::MainWindow *ui;
    CryptoModel model;
    void updateProgress(int value);
};
