# SPDX-License-Identifier: LicenseRef-PolyForm-Noncommercial-1.0.0
# SPDX-FileCopyrightText: 2026 Callan Barrett

qt_add_library(zaparoo_core STATIC)

target_sources(
    zaparoo_core
    PRIVATE
        Config.cpp
        Config.h
        Logger.cpp
        Logger.h
        MediaTypes.h
        PlatformPaths.cpp
        PlatformPaths.h
        ZaparooClient.cpp
        ZaparooClient.h
)

target_include_directories(zaparoo_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(
    zaparoo_core
    PUBLIC
        Qt6::Core
        Qt6::WebSockets
    PRIVATE
        Zaparoo::CompileOptions
)
