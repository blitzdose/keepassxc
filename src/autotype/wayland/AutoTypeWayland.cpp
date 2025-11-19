/*
 *  Copyright (C) 2024 KeePassXC Team <team@keepassxc.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AutoTypeWayland.h"

#include "autotype/AutoTypeAction.h"
#include "core/Tools.h"

AutoTypePlatformWayland::AutoTypePlatformWayland()
{
    
}

bool AutoTypePlatformWayland::isAvailable()
{
    return true;
}

void AutoTypePlatformWayland::unload()
{
}

QString AutoTypePlatformWayland::activeWindowTitle()
{
    return {};
}

WId AutoTypePlatformWayland::activeWindow()
{
    return 0;
}

AutoTypeExecutor* AutoTypePlatformWayland::createExecutor()
{
    return new AutoTypeExecutorWayland(this);
}

bool AutoTypePlatformWayland::raiseWindow(WId window)
{
    Q_UNUSED(window)
    return false;
}

QStringList AutoTypePlatformWayland::windowTitles()
{
    return {};
}

AutoTypeExecutorWayland::AutoTypeExecutorWayland(AutoTypePlatformWayland* platform)
    : m_platform(platform)
{
}

AutoTypeAction::Result AutoTypeExecutorWayland::execBegin(const AutoTypeBegin* action)
{
    Q_UNUSED(action)
    return AutoTypeAction::Result::Ok();
}

AutoTypeAction::Result AutoTypeExecutorWayland::execType(const AutoTypeKey* action)
{
    Q_UNUSED(action)

    Tools::sleep(execDelayMs);

    return AutoTypeAction::Result::Ok();
}

AutoTypeAction::Result AutoTypeExecutorWayland::execClearField(const AutoTypeClearField* action)
{
    Q_UNUSED(action)
    execType(new AutoTypeKey(Qt::Key_Home));
    execType(new AutoTypeKey(Qt::Key_End, Qt::ShiftModifier));
    execType(new AutoTypeKey(Qt::Key_Backspace));

    return AutoTypeAction::Result::Ok();
}