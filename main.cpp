#include "backlogs.h"
#include <QApplication>
#include <Windows.h>

bool isRun()
{
    HWND hwnd = FindWindow(NULL, L"backlogs");
    if (hwnd == NULL)
    {
        return false;
    }
    else
    {
        SendMessage(hwnd, WM_HOTKEY, ShowWidgetHotKey, 0); // Unicode���룬WPARAM�����õ�
        return true;
    }
}

int main(int argc, char *argv[])
{
    // ֻ��Ҫһ��������
    if (isRun())
    {
        return 0;
    }

    QApplication a(argc, argv);
    backlogs w;
    w.readFromFile();
    w.show();

    return a.exec();
}
