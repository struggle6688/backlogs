#include "backlogs.h"
#include "ui_backlogs.h"
#include "windows.h"
#include <fstream>
#include <iostream>

#pragma comment(lib, "User32.lib")

QList<HWND> g_GLDProjectHWNDs;

static BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
    TCHAR lpClassName[256];
    TCHAR windowTitleName[256];

    ::GetClassName(hWnd,(LPWSTR)lpClassName, 256-1); //获得窗口类名
    ::GetWindowTextW(hWnd,(LPWSTR)windowTitleName, 256-1);
    QString className = QString::fromWCharArray(lpClassName);
    QString titleName = QString::fromWCharArray(windowTitleName);

    LPProcessInfo pInfo = (LPProcessInfo)lParam;
    if (/*IsWindowVisible(hWnd) && className == pInfo->sClassName && */titleName != "")
    {
        if ((titleName.contains(pInfo->sTitleName)))
        {
            g_GLDProjectHWNDs << hWnd;
        }
    }

    return true;
}

backlogs::backlogs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::backlogs)
{
    ui->setupUi(this);
    if(RegisterHotKey((HWND)this->winId(), ShowWidgetHotKey, MOD_CONTROL|MOD_SHIFT, 'E')
            && RegisterHotKey((HWND)this->winId(), HideWidgetHotKey, MOD_CONTROL|MOD_SHIFT, 'D')
            && RegisterHotKey((HWND)this->winId(), ShowCloverHK, MOD_CONTROL|MOD_SHIFT, 'C'))
    {
        qApp->installNativeEventFilter(this);
    }
}

bool backlogs::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
    if (eventType == "windows_generic_MSG")
    {
        MSG *msg = (MSG*)message;
        if (msg->message == WM_HOTKEY)
        {
            switch (msg->wParam) {
            case ShowWidgetHotKey:
            {
                this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
                this->show();
                break;
            }
            case HideWidgetHotKey:
            {
                this->setVisible(false);
                writeToFile();
                break;
            }
            case ShowCloverHK:
            {
                doCloverVisable();
                break;
            }
            default:
                break;
            }
            return true;
        }
    }
    return false;
}

void backlogs::readFromFile()
{
    std::ifstream inStream;
    inStream.open("..\\..\\config\\backlogs.txt", std::ios_base::in);
    std::string strContent;
    std::string temp;
    while(getline(inStream, temp))
    {
        strContent += temp;
        strContent += "\n";
    }
    ui->textEdit->setText(QString::fromStdString(strContent));
    inStream.close();
}

void backlogs::writeToFile()
{
    std::ofstream outStream("..\\..\\config\\backlogs.txt", std::ios_base::out);
    outStream << ui->textEdit->toPlainText().toStdString();
    outStream.close();
}

void backlogs::doCloverVisable()
{
    g_GLDProjectHWNDs.clear();
    ProcessInfo oInfo;
    oInfo.sClassName = "Qt5QWindowIcon";  // 可以使用spy4win查看，也可以不使用该参数
    oInfo.sTitleName = QStringLiteral("Clover");

    EnumWindows(EnumWindowsProc, (LPARAM)&oInfo);
    if (g_GLDProjectHWNDs.count() > 0)
    {
        HWND mainWnd = g_GLDProjectHWNDs.at(0);
        SetForegroundWindow(mainWnd);
        SendMessage(mainWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
    }
}

backlogs::~backlogs()
{
    writeToFile();
    delete ui;
    UnregisterHotKey((HWND)this->winId(),ShowWidgetHotKey);
    UnregisterHotKey((HWND)this->winId(),HideWidgetHotKey);
    UnregisterHotKey((HWND)this->winId(),ShowCloverHK);
}

void backlogs::on_actionClear_triggered()
{
    ui->textEdit->clear();
}
