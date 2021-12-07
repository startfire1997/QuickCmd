#pragma once

#include <QPushButton>

class QtCMDButton : public QPushButton
{
    Q_OBJECT

public:
    QtCMDButton(QWidget* parent);
    ~QtCMDButton();

public slots:
    void OnClicked();
    void SetCmd(const std::string& cmd) { m_cmd = cmd; };

private:
    std::string m_cmd = "";
};
