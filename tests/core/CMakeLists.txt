# SPDX-License-Identifier: LicenseRef-PolyForm-Noncommercial-1.0.0
# SPDX-FileCopyrightText: 2026 Callan Barrett

qt_add_executable(tst_zaparoo_client tst_zaparoo_client.cpp)

target_link_libraries(
    tst_zaparoo_client
    PRIVATE
        Zaparoo::CompileOptions
        zaparoo_core
        Qt6::Test
)

add_test(NAME zaparoo_client COMMAND tst_zaparoo_client)
set_tests_properties(zaparoo_client PROPERTIES TIMEOUT 30)
