#include "qprocesswrapper.h"

QProcessWrapper::QProcessWrapper(QObject *parent) :
  QObject(parent)
{
}

QProcessWrapper::QProcessWrapper(QString exePath, QStringList arguments, QObject *parent)
{
  std::cout << "[QProcessWrapper] attempting to start process\n";

  // Create the process
  QProcess *newProcess = new QProcess(parent);

  // Connect signals for QProcess
  connect(newProcess, SIGNAL(started()), this, SLOT(processStarted()));
  connect(newProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)));
  connect(newProcess, SIGNAL(readyReadStandardError()), this, SLOT(slotReadStdErr()));
  connect(newProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(slotReadStdOut()));
  connect(newProcess, SIGNAL(finished(int)), this, SLOT(processFinished(int)));
  connect(newProcess, SIGNAL(destroyed()), this, SLOT(processDestroyed()));
  connect(this, SIGNAL(killProcess()), newProcess, SLOT(kill()));
  connect(this, SIGNAL(deleteProcess()), newProcess, SLOT(deleteLater()));

  if (arguments.isEmpty()) {
      // No arguments
      std::cout << "[QProcessWrapper] Starting Process: " << exePath.toStdString() << std::endl;
      std::cout << "[QProcessWrapper] No arguments" << std::endl;

      // Start the process
      newProcess->start(exePath);

    } else {
      std::cout << "[QProcessWrapper] Starting Process: " << exePath.toStdString() << std::endl;
      for (int i = 0; i < arguments.size(); i++) {
          std::cout << "Argument #" << i << ": "<< arguments.at(i).toStdString() << std::endl;
        }

      // Start the process with arguments
      newProcess->start(exePath, arguments);
    }
}

void QProcessWrapper::processStarted()
{
  std::cout << "[QProcessWrapper] Process has started!\n";
}

void QProcessWrapper::processError(QProcess::ProcessError error)
{
  std::cout << "[QProcessWrapper] Process ERROR!\n";

  switch (error) {
    case QProcess::FailedToStart: {
        std::cout << "[QProcessWrapper ERROR]: FailedToStart\n";
        break;
      }
    case QProcess::Crashed: {
        std::cout << "[QProcessWrapper ERROR]: Crashed\n";
        break;
      }
    case QProcess::Timedout: {
        std::cout << "[QProcessWrapper ERROR]: Timedout\n";
        break;
      }
    case QProcess::WriteError: {
        std::cout << "[QProcessWrapper ERROR]: WriteError\n";
        break;
      }
    case QProcess::ReadError: {
        std::cout << "[QProcessWrapper ERROR]: ReadError\n";
        break;
      }
    case QProcess::UnknownError: {
        std::cout << "[QProcessWrapper ERROR]: UnknownError\n";
        break;
      }
    default:
      break;
    }
}

void QProcessWrapper::slotReadStdErr()
{
  // call helper with pointer
  std::cout << "std err ready\n";
}

void QProcessWrapper::slotReadStdOut()
{
  // call helper with pointer
  std::cout << "std out ready\n";
}

void QProcessWrapper::processReadyReadSTDerr(QProcess &toRead)
{
  QString stdErr = toRead.readAllStandardError();
  std::cout << stdErr.toStdString() << std::endl;
}

void QProcessWrapper::proccessReadyReadSTDout(QProcess &toRead)
{
  QString stdOut = toRead.readAllStandardOutput();
  std::cout << stdOut.toStdString() << std::endl;
}

void QProcessWrapper::processFinished(int exitCode)
{
  std::cout << "[QProcessWrapper] Process exited";
  std::cout << "[QProcessWrapper] Exit Code: " << exitCode << "\n";
}

void QProcessWrapper::processDestroyed()
{
  std::cout << "[QProcessWrapper] Process destroyed!";
}

void QProcessWrapper::processStateChanged(QProcess::ProcessState newState)
{
  std::cout << "[QProcessWrapper] Process stage changed!";

  switch (newState) {
    case QProcess::NotRunning: {
        std::cout << "[QProcessWrapper] Process is now NotRunning";
        break;
      }
    case QProcess::Starting: {
        std::cout << "[QProcessWrapper] Process is now Starting";
        break;
      }
    case QProcess::Running: {
        std::cout << "[QProcessWrapper] Process is now Running";
        break;
      }
    default:
      break;
    }
}

void QProcessWrapper::errorMessageBox(QString error)
{
  std::cout << "Error: " << error.toStdString() << std::endl;
}
