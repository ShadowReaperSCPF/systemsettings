/**************************************************************************
 * Copyright (C) 2009 Ben Cooksley <bcooksley@kde.org>                    *
 *                                                                        *
 * This program is free software; you can redistribute it and/or          *
 * modify it under the terms of the GNU General Public License            *
 * as published by the Free Software Foundation; either version 2         *
 * of the License, or (at your option) any later version.                 *
 *                                                                        *
 * This program is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 * GNU General Public License for more details.                           *
 *                                                                        *
 * You should have received a copy of the GNU General Public License      *
 * along with this program; if not, write to the Free Software            *
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA          *
 * 02110-1301, USA.                                                       *
***************************************************************************/
#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include "BaseMode.h"

class MenuItem;
class ModuleView;
class QModelIndex;

class ClassicMode : public BaseMode
{
    Q_OBJECT

public:
    ClassicMode(QObject * parent, const QVariantList& );
    ~ClassicMode();
    void initEvent() Q_DECL_OVERRIDE;
    void leaveModuleView() Q_DECL_OVERRIDE;
    QWidget * mainWidget() Q_DECL_OVERRIDE;
    KAboutData * aboutData() Q_DECL_OVERRIDE;
    ModuleView * moduleView() const Q_DECL_OVERRIDE;

protected:
    QList<QAbstractItemView*> views() const Q_DECL_OVERRIDE;
    bool eventFilter(QObject* watched, QEvent* event) Q_DECL_OVERRIDE;

public Q_SLOTS:
    void expandColumns();
    void searchChanged( const QString& text ) Q_DECL_OVERRIDE;
    void selectModule( const QModelIndex& selectedModule );
    void changeModule( const QModelIndex& activeModule );
    void saveState() Q_DECL_OVERRIDE;
    void giveFocus() Q_DECL_OVERRIDE;
    void addConfiguration( KConfigDialog * config ) Q_DECL_OVERRIDE;
    void loadConfiguration() Q_DECL_OVERRIDE;
    void saveConfiguration() Q_DECL_OVERRIDE;

private Q_SLOTS:
    void moduleLoaded();
    void initWidget();
    void moveUp( MenuItem * item );

private:
    class Private;
    Private *const d;
};

#endif
