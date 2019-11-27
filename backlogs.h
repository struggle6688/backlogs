#ifndef BACKLOGS_H
#define BACKLOGS_H

#include <QMainWindow>
#include <QAbstractNativeEventFilter>

#define ShowWidgetHotKey 0xC000
#define HideWidgetHotKey ShowWidgetHotKey+1
#define ShowCloverHK ShowWidgetHotKey+2
typedef struct tagProcessInfo
{
    QString sClassName;
    QString sTitleName;
}ProcessInfo, *LPProcessInfo;

namespace Ui {
class backlogs;
}

class backlogs : public QMainWindow, public QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    explicit backlogs(QWidget *parent = 0);
    virtual bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override;
    void readFromFile();
    void writeToFile();
    void doCloverVisable();
    ~backlogs();

private slots:
    void on_actionClear_triggered();

private:
    Ui::backlogs *ui;
};

#endif // BACKLOGS_H
