// SPDX-License-Identifier: LicenseRef-PolyForm-Noncommercial-1.0.0
// SPDX-FileCopyrightText: 2026 Callan Barrett

#include "Config.h"
#include "Logger.h"
#include "ZaparooClient.h"

#include <QFontDatabase>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QtQml/qqmlextensionplugin.h>

// Pull static QML plugin symbols into the final binary so the linker
// doesn't strip them as unreferenced.
Q_IMPORT_QML_PLUGIN(Zaparoo_AppPlugin)
Q_IMPORT_QML_PLUGIN(Zaparoo_UiPlugin)
Q_IMPORT_QML_PLUGIN(Zaparoo_ThemePlugin)

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("Zaparoo Launcher");
    QGuiApplication::setApplicationVersion(QStringLiteral(ZAPAROO_VERSION));
    QGuiApplication::setOrganizationName("Zaparoo");
    QGuiApplication::setOrganizationDomain("zaparoo.org");

    zaparoo::Logger::install();

    const zaparoo::Config config = zaparoo::loadConfig();
    zaparoo::ZaparooClient client;

    // Fonts are embedded inside the Zaparoo.App QML module's resource bundle.
    QFontDatabase::addApplicationFont(":/qt/qml/Zaparoo/App/resources/fonts/DejaVuSans.ttf");
    QFontDatabase::addApplicationFont(":/qt/qml/Zaparoo/App/resources/fonts/PressStart2P.ttf");

    // Basic style is mandatory: it is the only style compatible with software
    // rendering on MiSTer (no GPU, no shaders, no platform-specific effects).
    QQuickStyle::setStyle("Basic");

    QQmlApplicationEngine engine;
#ifndef ZAPAROO_DEV_BUILD
    engine.setInitialProperties({{"fullScreen", true}});
#endif
    engine.loadFromModule("Zaparoo.App", "Main");

    if (engine.rootObjects().isEmpty())
    {
        return EXIT_FAILURE;
    }

    client.connectToCore(config.coreEndpoint);

    return QGuiApplication::exec();
}
