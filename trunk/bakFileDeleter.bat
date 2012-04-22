@echo off
rem title
title bak file Deleter
set /p pushKey=".bakファイルを削除します。よろしいですか？(y/n)"
if "%pushKey%" == "y" goto KILL

if "%pushKey%" == "Y" goto KILL

if "%pushKey%" == "yes" goto KILL

if "%pushKey%" == "YES" goto KILL
rem NOなら終了
goto EXT

rem .bakファイル除去
:KILL
for /r %%i in ( *.bak ) do ( if exist "%%i" ( del /s /q "%%i"))
goto EXT

:EXT