#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QCryptographicHash>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Crypto safe");
    setFixedSize(800, 350);

    ui->passwordEdit->setVisible(true);
    connect(ui->decryptRadio, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) {
            ui->progressBar->setValue(0);
        }
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_browseButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Choisir un fichier");
    if (!fileName.isEmpty()) {
        ui->filePathEdit->setText(fileName);
    }
}

void MainWindow::on_actionButton_clicked() {
    QString filePath = ui->filePathEdit->text();
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez choisir un fichier.");
        return;
    }
    QString password = ui->passwordEdit->text();
    if (password != "12345") {
        ui->passwordEdit->setStyleSheet(
            "font-size: 16px;"
            "padding: 6px 10px;"
            "border: 2px solid red;"
            "border-radius: 8px;"
            "background: #fffbe6;"
        );
        QMessageBox::warning(this, "Erreur", "Mot de passe incorrect !");
        return;
    } else {
        ui->passwordEdit->setStyleSheet(
            "font-size: 16px;"
            "padding: 6px 10px;"
            "border: 2px solid #e67e22;"
            "border-radius: 8px;"
            "background: #fffbe6;"
        );
    }
    if (ui->decryptRadio->isChecked()) {
        QString outPath;
        bool ok = model.decryptFile(filePath, password, outPath, [this](int v){ updateProgress(v); });
        if (ok)
            QMessageBox::information(this, "Succès", "Fichier décrypté : " + outPath);
        else
            QMessageBox::warning(this, "Erreur", "Impossible de décrypter le fichier.");
    } else {
        QString outPath;
        bool ok = model.encryptFile(filePath, outPath, [this](int v){ updateProgress(v); });
        if (ok)
            QMessageBox::information(this, "Succès", "Fichier crypté : " + outPath);
        else
            QMessageBox::warning(this, "Erreur", "Impossible de crypter le fichier.");
    }
}

void MainWindow::updateProgress(int value) {
    ui->progressBar->setValue(value);
}

void MainWindow::on_cancelButton_clicked() {
    qApp->quit();
}