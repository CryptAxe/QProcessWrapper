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
#include <iostream>

class QProcessWrapper : public QObject
{
  Q_OBJECT
public:
  explicit QProcessWrapper(QObject *parent = 0);
  explicit QProcessWrapper(QString exePath, QStringList arguments = QString(""), QObject *parent = 0);

signals:
  void killProcess();
  void deleteProcess();

public slots:

private slots:
  void processStarted();
  void processError(QProcess::ProcessError error);
  void slotReadStdErr();
  void slotReadStdOut();
  void processFinished(int exitCode);
  void processDestroyed();
  void processStateChanged(QProcess::ProcessState newState);
  void errorMessageBox(QString error);

private:
  void processReadyReadSTDerr(QProcess &toRead);  // helps slotReadStdErr()
  void proccessReadyReadSTDout(QProcess &toRead); // helps slotReadStdOut()
};

#endif // QPROCESSWRAPPER_H
