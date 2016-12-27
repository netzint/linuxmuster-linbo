#ifndef FORTSCHRITTDIALOG_H
#define FORTSCHRITTDIALOG_H

#include <QDialog>
#include <qobject.h>
#include <QProcess>
#include <QTextEdit>
#include <QTime>
#include <qbytearray.h>

#include "linboLogConsole.h"
#include "aktion.h"

namespace Ui {
class FortschrittDialog;
}

class linboLogConsole;

class FortschrittDialog : public QDialog
{
    Q_OBJECT
private:
    bool active;
    QString cmd;
    bool* details;
    QProcess *process;
    bool connected;
    linboLogConsole *logConsole, *logDetails;
    int timerId;
    int (*maximum)(const QByteArray& output);
    int (*value)(const QByteArray& output);

public:
    explicit FortschrittDialog(QWidget *parent = 0, bool new_active = true, QStringList* command = 0, linboLogConsole *new_log = 0,
                               const QString& titel  = NULL, Aktion aktion = Aktion::None,
                               bool* newDetails = NULL,
                               int (*new_maximum)(const QByteArray& output) = NULL,
                               int (*new_value)(const QByteArray& output) = NULL);
    ~FortschrittDialog();

    void setProgress(int i);
    void setShowCancelButton(bool show);
    void setProcess(QProcess *new_process);
    void keyPressEvent(QKeyEvent *);

public slots:
    void killLinboCmd();

private slots:
    void processReadyReadStandardError();
    void processReadyReadStandardOutput();
    void processFinished( int exitCode, QProcess::ExitStatus exitStatus );

    void on_details_toggled(bool checked);

    void on_cancelButton_clicked();

protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::FortschrittDialog *ui;
};

#endif // FORTSCHRITTDIALOG_H