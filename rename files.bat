@echo off
setlocal EnableDelayedExpansion

cls

for %%f in (*.cpp) do (
    set filename=%%f
    set filename=!filename: -=.!
    ren "%%f" "!filename!"
    )