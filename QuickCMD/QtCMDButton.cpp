#include "QtCMDButton.h"
#include <QProcess>
#include "CommonDefine.h"

QtCMDButton::QtCMDButton(QWidget* parent)
    : QPushButton(parent)
{
    connect(this, &QPushButton::pressed, this, &QtCMDButton::OnClicked);
}

QtCMDButton::~QtCMDButton()
{
}

void QtCMDButton::OnClicked()
{
    QProcess pro;
    pro.start(QString::fromStdString(m_cmd));
    pro.waitForFinished();
}
