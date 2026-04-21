// SPDX-License-Identifier: LicenseRef-PolyForm-Noncommercial-1.0.0
// SPDX-FileCopyrightText: 2026 Callan Barrett
#pragma once

#include <QString>
#include <QUrl>

namespace zaparoo
{

// Application configuration loaded from the per-user config file.
// Stub — implementation pending.
struct Config
{
    // Base URL for the Zaparoo Core WebSocket endpoint (version-pinned path).
#ifdef ZAPAROO_DEV_BUILD
    QUrl coreEndpoint{"ws://10.0.0.107:7497/api/v0.1"};
#else
    QUrl coreEndpoint{"ws://127.0.0.1:7497/api/v0.1"};
#endif
};

// Loads config from the platform-specific config file.
// Returns default values if the file does not exist or cannot be parsed.
Config loadConfig();

// Persists config to the platform-specific config file.
void saveConfig(const Config& config);

} // namespace zaparoo
