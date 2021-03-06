/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd
*
* Author:      maojj <maojunjie@uniontech.com>
* Maintainer:  maojj <maojunjie@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef XWIN_KILL_PREVIEW_WIDGET_H
#define XWIN_KILL_PREVIEW_WIDGET_H

#include <QWidget>

namespace util {
namespace wm {
class WMInfo;
}
}
class XWinKillPreviewBackgroundWidget;

class XWinKillPreviewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit XWinKillPreviewWidget(QWidget *parent = nullptr);
    ~XWinKillPreviewWidget() override;

signals:
    void windowClicked(pid_t pid);
    void cursorUpdated(const QCursor &cursor);

public slots:

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void initUI();
    void initConnections();

private:
    util::wm::WMInfo *m_wminfo;
    QList<XWinKillPreviewBackgroundWidget *> m_backgroundList;
    QList<QScreen *> m_screens;

    QCursor m_killCursor;
    QCursor m_defaultCursor;
};

#endif // XWIN_KILL_PREVIEW_WIDGET_H
