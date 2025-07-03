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

    // Afficher/cacher le champ mot de passe selon le mode
    ui->passwordEdit->setVisible(ui->decryptRadio->isChecked());
    connect(ui->decryptRadio, &QRadioButton::toggled, this, [this](bool checked) {
        ui->passwordEdit->setVisible(checked);
        if (checked) {
            ui->progressBar->setValue(0); // Remettre la progress bar à 0 si décryptage sélectionné
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
    if (ui->decryptRadio->isChecked()) {
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
            // Remettre le style normal si le mot de passe est correct
            ui->passwordEdit->setStyleSheet(
                "font-size: 16px;"
                "padding: 6px 10px;"
                "border: 2px solid #e67e22;"
                "border-radius: 8px;"
                "background: #fffbe6;"
            );
        }
        decryptFile(filePath, password);
    } else {
        encryptFile(filePath);
    }
}

void MainWindow::encryptFile(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }
    QByteArray data = file.readAll();
    file.close();

    QByteArray key = "CRYPTKEY";
    int dataSize = data.size();
    ui->progressBar->setValue(0);
    for (int i = 0; i < dataSize; ++i) {
        data[i] = data[i] ^ key[i % key.size()];
        if (dataSize > 100 && i % (dataSize / 100) == 0) {
            ui->progressBar->setValue((i * 100) / dataSize);
            qApp->processEvents();
        }
    }
    ui->progressBar->setValue(100);

    QString outPath = filePath + ".crypt";
    QFile outFile(outPath);
    if (!outFile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'écrire le fichier.");
        return;
    }
    outFile.write(data);
    outFile.close();
    QMessageBox::information(this, "Succès", "Fichier crypté : " + outPath);
}

void MainWindow::decryptFile(const QString &filePath, const QString &) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }
    QByteArray data = file.readAll();
    file.close();

    QByteArray key = "CRYPTKEY";
    int dataSize = data.size();
    ui->progressBar->setValue(0);
    for (int i = 0; i < dataSize; ++i) {
        data[i] = data[i] ^ key[i % key.size()];
        if (dataSize > 100 && i % (dataSize / 100) == 0) {
            ui->progressBar->setValue((i * 100) / dataSize);
            qApp->processEvents();
        }
    }
    ui->progressBar->setValue(100);

    QString outPath = filePath;
    if (outPath.endsWith(".crypt"))
        outPath.chop(6);
    outPath += ".decrypted";
    QFile outFile(outPath);
    if (!outFile.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'écrire le fichier.");
        return;
    }
    outFile.write(data);
    outFile.close();
    QMessageBox::information(this, "Succès", "Fichier décrypté : " + outPath);
}

void MainWindow::updateProgress(int value) {
    ui->progressBar->setValue(value);
}

void MainWindow::on_cancelButton_clicked() {
    qApp->quit();
}