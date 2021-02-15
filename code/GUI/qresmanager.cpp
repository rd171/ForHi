#include "qresmanager.h"

QResManager::QResManager(QWidget *parent) :
    QWidget(parent)
{
    m_pTitle        = new QLabel(this);
    m_pViewBtn      = new QPushButton(tr("View"), this);
    connect(m_pViewBtn, SIGNAL(clicked()), this, SIGNAL(ClickViewBtn()));
    m_WorkspaceLayout.addWidget(m_pTitle);
    m_WorkspaceLayout.addWidget(m_pViewBtn);
    m_WorkspaceLayout.setAlignment(m_pTitle,Qt::AlignTop);
    m_WorkspaceLayout.setAlignment(m_pViewBtn,Qt::AlignTop);
    m_pTitle->setMinimumHeight(30);
    m_pTitle->setMaximumHeight(30);
    m_pViewBtn->setMinimumHeight(50);
    m_pViewBtn->setMaximumHeight(50);
    m_pTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_pViewBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    setLayout(&m_WorkspaceLayout);
}

void QResManager::SetTitle(QString str)
{
    m_pTitle->setText(str);
}
