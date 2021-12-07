#pragma once

#include <QtWidgets/QWidget>
#include "ui_QuickCMD.h"

class ConfigManager;

class QuickCMD : public QWidget
{
    Q_OBJECT

public:
    QuickCMD(QWidget *parent = Q_NULLPTR);
    
    void InitBtns();

private:
    Ui::QuickCMDClass ui;
    ConfigManager* m_configMgr = nullptr;
};
