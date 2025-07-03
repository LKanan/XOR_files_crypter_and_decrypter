#pragma once
#include <QString>
#include <functional>

class CryptoModel {
public:
    bool encryptFile(const QString &filePath, QString &outPath, std::function<void(int)> progressCb);
    bool decryptFile(const QString &filePath, const QString &password, QString &outPath, std::function<void(int)> progressCb);
};
