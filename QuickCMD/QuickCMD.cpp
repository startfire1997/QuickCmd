#include "QuickCMD.h"
#include "ConfigManager.h"
#include <QGridLayout>
#include "QtCMDButton.h"

QuickCMD::QuickCMD(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setWindowTitle(" ");
    setWindowFlags(Qt::WindowCloseButtonHint);
    setFixedWidth(120);
    InitBtns();
}

void QuickCMD::InitBtns()
{
    int windowHeight = 10;
    ui.gridLayout->setMargin(5);
    ui.gridLayout->setSpacing(3);
    m_configMgr = new ConfigManager();
    m_configMgr->Initialize(QApplication::applicationDirPath().toStdString());

    std::map<std::string, std::string> configMap = m_configMgr->GetCmdConfigMap();
    for (auto it : configMap)
    {
        QtCMDButton* btn = new QtCMDButton(this);
        btn->setText(QString::fromStdString(it.first));
        btn->SetCmd(it.second);
        btn->setFixedHeight(30);
        windowHeight += 35;
        ui.gridLayout->addWidget(btn);
    }
    setFixedHeight(windowHeight);
    ui.gridLayout->update();
}
