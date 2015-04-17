#include "qprocesswrapper.h"

QProcessWrapper::QProcessWrapper(QObject *parent, QString exePath, QStringList arguments) :
    QObject(parent)
{
    // Create the process
    QProcess *newProcess = new QProcess(parent);

    // Connect signals for QProcess
    connect(newProcess, SIGNAL(started()), this, SLOT(processStarted()));
    connect(newProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)));
    connect(newProcess, SIGNAL(readyReadStandardError()), this, SLOT(processReadyReadSTDerr()));
    connect(newProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(proccessReadyReadSTDout()));
    connect(newProcess, SIGNAL(finished(int)), this, SLOT(processFinished(int)));
    connect(newProcess, SIGNAL(destroyed()), this, SLOT(processDestroyed()));

    // Connect our signals
    connect(this, SIGNAL(killProcess()), newProcess, SLOT(kill()));
    connect(this, SIGNAL(deleteProcess()), newProcess, SLOT(deleteLater()));

    if (arguments.at(0).isEmpty()) {
        // No arguments
        qDebug() << "[QProcessWrapper] Starting Process: " << exePath << endl;
        qDebug() << "[QProcessWrapper] No arguments" << endl;

        // Start the process
        newProcess->start(exePath);

    } else {
        qDebug() << "[QProcessWrapper] Starting Process: " << exePath << endl;
        qDebug() << "[QProcessWrapper] Arguments: " << arguments << endl;

        // Start the process with arguments
        newProcess->start(exePath, arguments);
    }
}

QProcessWrapper::~QProcessWrapper()
{

}

void QProcessWrapper::processStarted()
{
    qDebug() << "[QProcessWrapper] Process has started! \n";
}

void QProcessWrapper::processError(QProcess::ProcessError error)
{
    qDebug() << "[QProcessWrapper] Process ERROR!\n";

    switch (error) {
    case QProcess::FailedToStart: {
        break;
    }
    case QProcess::Crashed: {
        break;
    }
    case QProcess::Timedout: {
        break;
    }
    case QProcess::WriteError: {
        break;
    }
    case QProcess::ReadError: {
        break;
    }
    case QProcess::UnknownError: {
        break;
    }
    default:
        break;
    }

    // Show Dialog
}

void QProcessWrapper::processReadyReadSTDerr()
{
    qDebug() << "[QProcessWrapper] Ready to ready stderr\n";
}

void QProcessWrapper::proccessReadyReadSTDout()
{
    qDebug() << "[QProcessWrapper] Ready to ready stdout\n";
}

void QProcessWrapper::processFinished(int exitCode)
{
    qDebug() << "[QProcessWrapper] Process exited";
    qDebug() << "[QProcessWrapper] Exit Code: " << exitCode << "\n";

    // Show Dialog
}

void QProcessWrapper::processDestroyed()
{
    qDebug() << "[QProcessWrapper] Process destroyed!";

    // Show Dialog
}

void QProcessWrapper::processStateChanged(QProcess::ProcessState newState)
{
    switch (newState) {
    case QProcess::NotRunning: {
        break;
    }
    case QProcess::Starting: {
        break;
    }
    case QProcess::Running: {
        break;
    }
    default:
        break;
    }
}

void QProcessWrapper::errorMessageBox(QString error)
{
    qDebug() << "Error: " << error << "\n";
}
