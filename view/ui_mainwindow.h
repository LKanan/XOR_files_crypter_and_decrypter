/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QHBoxLayout *fileLayout;
    QLineEdit *filePathEdit;
    QPushButton *browseButton;
    QHBoxLayout *modeLayout;
    QRadioButton *encryptRadio;
    QRadioButton *decryptRadio;
    QLineEdit *passwordEdit;
    QPushButton *actionButton;
    QPushButton *cancelButton;
    QProgressBar *progressBar;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(MainWindow);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        fileLayout = new QHBoxLayout();
        fileLayout->setObjectName(QString::fromUtf8("fileLayout"));
        filePathEdit = new QLineEdit(MainWindow);
        filePathEdit->setObjectName(QString::fromUtf8("filePathEdit"));

        fileLayout->addWidget(filePathEdit);

        browseButton = new QPushButton(MainWindow);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        fileLayout->addWidget(browseButton);


        verticalLayout->addLayout(fileLayout);

        modeLayout = new QHBoxLayout();
        modeLayout->setObjectName(QString::fromUtf8("modeLayout"));
        encryptRadio = new QRadioButton(MainWindow);
        encryptRadio->setObjectName(QString::fromUtf8("encryptRadio"));
        encryptRadio->setChecked(true);

        modeLayout->addWidget(encryptRadio);

        decryptRadio = new QRadioButton(MainWindow);
        decryptRadio->setObjectName(QString::fromUtf8("decryptRadio"));

        modeLayout->addWidget(decryptRadio);

        passwordEdit = new QLineEdit(MainWindow);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        modeLayout->addWidget(passwordEdit);


        verticalLayout->addLayout(modeLayout);

        actionButton = new QPushButton(MainWindow);
        actionButton->setObjectName(QString::fromUtf8("actionButton"));

        verticalLayout->addWidget(actionButton);

        cancelButton = new QPushButton(MainWindow);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        progressBar = new QProgressBar(MainWindow);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimum(0);
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);

        verticalLayout->addWidget(progressBar);


        retranslateUi(MainWindow);
        QObject::connect(actionButton, SIGNAL(clicked()), MainWindow, SLOT(on_actionButton_clicked()));
        QObject::connect(cancelButton, SIGNAL(clicked()), MainWindow, SLOT(on_cancelButton_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Crypto safe", nullptr));
        MainWindow->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"    background-color: #f4f8fb;\n"
"    border-radius: 16px;\n"
"   ", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Cryptage & D\303\251cryptage de Fichier", nullptr));
        titleLabel->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"        font-size: 22px;\n"
"        color: #2d89ef;\n"
"        font-weight: bold;\n"
"        margin-bottom: 10px;\n"
"      ", nullptr));
        filePathEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Chemin du fichier...", nullptr));
        filePathEdit->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"          font-size: 16px;\n"
"          padding: 6px 10px;\n"
"          border: 2px solid #b0c4de;\n"
"          border-radius: 8px;\n"
"          background: #fff;\n"
"        ", nullptr));
        browseButton->setText(QCoreApplication::translate("MainWindow", "Parcourir", nullptr));
        browseButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"          background-color: #2d89ef;\n"
"          color: white;\n"
"          font-weight: bold;\n"
"          font-size: 15px;\n"
"          border-radius: 8px;\n"
"          padding: 6px 18px;\n"
"        ", nullptr));
        encryptRadio->setText(QCoreApplication::translate("MainWindow", "Cryptage", nullptr));
        encryptRadio->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"          font-size: 15px;\n"
"          color: #2d89ef;\n"
"          font-weight: bold;\n"
"        ", nullptr));
        decryptRadio->setText(QCoreApplication::translate("MainWindow", "D\303\251cryptage", nullptr));
        decryptRadio->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"          font-size: 15px;\n"
"          color: #e67e22;\n"
"          font-weight: bold;\n"
"        ", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        passwordEdit->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"          font-size: 16px;\n"
"          padding: 6px 10px;\n"
"          border: 2px red;\n"
"          border-radius: 8px;\n"
"          background: #fffbe6;\n"
"        ", nullptr));
        actionButton->setText(QCoreApplication::translate("MainWindow", "Ex\303\251cuter", nullptr));
        actionButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"        background-color: #27ae60;\n"
"        color: white;\n"
"        font-weight: bold;\n"
"        font-size: 18px;\n"
"        border-radius: 10px;\n"
"        padding: 10px 0;\n"
"        margin-top: 10px;\n"
"      ", nullptr));
        cancelButton->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        cancelButton->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"        background-color: #e74c3c;\n"
"        color: white;\n"
"        font-weight: bold;\n"
"        font-size: 16px;\n"
"        border-radius: 8px;\n"
"        padding: 8px 0;\n"
"        margin-bottom: 6px;\n"
"      ", nullptr));
        progressBar->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"        QProgressBar {\n"
"          border: 2px solid #b0c4de;\n"
"          border-radius: 8px;\n"
"          text-align: center;\n"
"          font-size: 15px;\n"
"          background: #fff;\n"
"        }\n"
"        QProgressBar::chunk {\n"
"          background-color: #2d89ef;\n"
"          border-radius: 8px;\n"
"        }\n"
"      ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
