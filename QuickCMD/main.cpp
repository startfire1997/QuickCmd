#include "QuickCMD.h"
#include "CommonDefine.h"
#include <filesystem>
#include <QtWidgets/QApplication>

void InitGlog()
{
    google::InitGoogleLogging("quickcmd");
    std::filesystem::path logPath = QApplication::applicationDirPath().toStdString() + "/log";
    std::filesystem::create_directory(logPath);
    FLAGS_log_dir = logPath.string().c_str();
    LOG(INFO) << "program start at:" << QApplication::applicationDirPath().toStdString();
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    InitGlog();

    QuickCMD w;
    w.show();
    
    bool ret = a.exec();
    google::ShutdownGoogleLogging();
    return ret;
}
