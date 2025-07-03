#include "cryptomodel.h"
#include <QFile>

bool CryptoModel::encryptFile(const QString &filePath, QString &outPath, std::function<void(int)> progressCb) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QByteArray data = file.readAll();
    file.close();

    QByteArray key = "CRYPTKEY";
    int dataSize = data.size();
    if (progressCb) progressCb(0);
    for (int i = 0; i < dataSize; ++i) {
        data[i] = data[i] ^ key[i % key.size()];
        if (dataSize > 100 && i % (dataSize / 100) == 0 && progressCb)
            progressCb((i * 100) / dataSize);
    }
    if (progressCb) progressCb(100);

    outPath = filePath + ".crypt";
    QFile outFile(outPath);
    if (!outFile.open(QIODevice::WriteOnly))
        return false;
    outFile.write(data);
    outFile.close();
    return true;
}

bool CryptoModel::decryptFile(const QString &filePath, const QString &, QString &outPath, std::function<void(int)> progressCb) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QByteArray data = file.readAll();
    file.close();

    QByteArray key = "CRYPTKEY";
    int dataSize = data.size();
    if (progressCb) progressCb(0);
    for (int i = 0; i < dataSize; ++i) {
        data[i] = data[i] ^ key[i % key.size()];
        if (dataSize > 100 && i % (dataSize / 100) == 0 && progressCb)
            progressCb((i * 100) / dataSize);
    }
    if (progressCb) progressCb(100);

    outPath = filePath;
    if (outPath.endsWith(".crypt"))
        outPath.chop(6);
    outPath += ".decrypted";
    QFile outFile(outPath);
    if (!outFile.open(QIODevice::WriteOnly))
        return false;
    outFile.write(data);
    outFile.close();
    return true;
}
