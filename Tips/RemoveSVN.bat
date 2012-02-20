@echo off
rem タイトルの設定
title RemoveSVNFolder
rem 条件分岐
set /p pushKey=".svnフォルダを削除します。よろしいですか？(y/n)"
if "%pushKey%" == "y" goto KILL

if "%pushKey%" == "Y" goto KILL

if "%pushKey%" == "yes" goto KILL

if "%pushKey%" == "YES" goto KILL
rem NOなら終了
goto EXT

rem .svnフォルダ除去
:KILL
for /r %%A in ( _svn ) do ( if exist "%%A" ( rmdir /s /q "%%A"))
for /r %%i in ( .svn ) do ( if exist "%%i" ( rmdir /s /q "%%i"))
goto EXT

:EXT