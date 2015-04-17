/*
 * QProcessWrapper
 *
 * ~CryptAxe
 */

#ifndef QPROCESSWRAPPER_H
#define QPROCESSWRAPPER_H

#include <QObject>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QDebug>

class QProcessWrapper : public QObject
{
    Q_OBJECT
public:
    explicit QProcessWrapper(QObject *parent = 0, QString exePath = "", QStringList arguments = QString(""));
    ~QProcessWrapper();
    
signals:
    void killProcess();
    void deleteProcess();
    
public slots:

private slots:
    void processStarted();
    void processError(QProcess::ProcessError error);
    void processReadyReadSTDerr();
    void proccessReadyReadSTDout();
    void processFinished(int exitCode);
    void processDestroyed();
    void processStateChanged(QProcess::ProcessState newState);
    void errorMessageBox(QString error);
};

#endif // QPROCESSWRAPPER_H
