/*
  probecontroller.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2013-2016 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_PROBECONTROLLER_H
#define GAMMARAY_PROBECONTROLLER_H

#include <common/probecontrollerinterface.h>

namespace GammaRay {
/** @brief Server-side part for the object property inspector.
 *  Use this to integrate a property inspector like in the QObject view into your tool.
 */
class ProbeController : public ProbeControllerInterface
{
    Q_OBJECT
    Q_INTERFACES(GammaRay::ProbeControllerInterface)
public:
    explicit ProbeController(QObject *parent = 0);

public slots:
    void selectObject(GammaRay::ObjectId id, const QString &toolId) Q_DECL_OVERRIDE;
    void requestSupportedTools(GammaRay::ObjectId id) Q_DECL_OVERRIDE;

    void detachProbe() Q_DECL_OVERRIDE;
    void quitHost() Q_DECL_OVERRIDE;
};
}

#endif // GAMMARAY_PROBECONTROLLER_H
