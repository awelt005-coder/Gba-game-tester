cmake_minimum_required(VERSION 3.18)
project(gba_game_tester LANGUAGES C)

add_executable(gba_game main.c)

if(CMAKE_SYSTEM_NAME STREQUAL AdvancedGameBoy)
    find_package(librom REQUIRED)
    find_package(libseven REQUIRED)
    find_package(agbabi REQUIRED)

    target_compile_options(gba_game PRIVATE
        -mthumb
        -fconserve-stack
        -fomit-frame-pointer
    )

    target_link_libraries(gba_game PRIVATE
        librom
        libseven
        agbabi
    )

    set_target_properties(gba_game PROPERTIES
        ROM_TITLE "GBA GAME TEST"
        ROM_ID AATJ
        ROM_MAKER AW
        ROM_VERSION 1
    )

    install_rom(gba_game)
endif()
