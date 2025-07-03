#pragma once
#include <QWidget>

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
    void on_cancelButton_clicked(); // Ajouté

private:
    Ui::MainWindow *ui;
    void encryptFile(const QString &filePath);
    void decryptFile(const QString &filePath, const QString &password);
    void updateProgress(int value);
};
