-- SPDX-License-Identifier: GPL-3.0-or-later
-- Copyright (c) 2025 Julien Bernard
set_project("game")
set_version("1.0.0")

add_repositories("gf-repo https://github.com/GamedevFramework/xmake-repo")

add_requires("gamedevframework2")

if is_kind("static") then
    add_requireconfs("gamedevframework2", {system = false, configs = {shared = false, debug = is_mode("debug")}})
    add_requireconfs("gamedevframework2.**", {system = false, configs = {shared = false}})
end

add_rules("mode.debug", "mode.releasedbg", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "$(builddir)"})

includes("@builtin/xpack")

if is_mode("sanitizers") then
    set_symbols("debug")
    set_optimize("none")
    set_policy("build.sanitizer.address", true)
    set_policy("build.sanitizer.undefined", true)
end

set_policy("build.warning", true)
set_warnings("allextra")
set_languages("cxx20")
set_encodings("utf-8")

if is_plat("windows") then
  add_cxflags("/wd4251") -- Disable warning: class needs to have dll-interface to be used by clients of class blah blah blah
  add_defines("NOMINMAX", "_CRT_SECURE_NO_WARNINGS")
end

set_configdir("$(builddir)/config")
set_configvar("GAME_DATADIR", "$(projectdir)/data")
add_configfiles("code/config.h.in", {pattern = "@(.-)@"})

target("game")
    set_kind("binary")
    add_files("code/main.cc")
    add_files("code/bits/*.cc")
    add_includedirs("$(builddir)/config")
    add_packages("gamedevframework2")
    set_rundir("$(projectdir)")
    if is_plat("windows") then
        add_files("app.manifest")
        if is_mode("release") then
            add_ldflags("/subsystem:windows")
        else
            add_ldflags("/subsystem:console")
        end
    end

xpack("game")
    set_formats("nsis", "zip", "targz")
    set_title("game")
    set_author("team")
    set_description("Game 3000")
    set_homepage("https://example.com")
    set_licensefile("LICENSE")
    add_targets("game")
    set_bindir(".")
    add_installfiles("(data/*)")
    -- add_sourcefiles("(src/**)")
    -- set_iconfile("src/assets/xmake.ico")

    after_installcmd(function (package, batchcmds)
        batchcmds:mkdir(package:installdir("data"))
        batchcmds:cp("data/*", package:installdir("data"))
    end)

    after_uninstallcmd(function (package, batchcmds)
        batchcmds:rmdir(package:installdir("data"))
    end)
