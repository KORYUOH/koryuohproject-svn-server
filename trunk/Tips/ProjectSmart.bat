@echo off
rem �F�X����
title ProjectShaper
rem ��������
set /p pushKey="VS2010Project���V�F�C�v�A�b�v���܂��B��낵���ł����H(y/n)"
if "%pushkey%" == "y" goto KILL
if "%pushkey%" == "Y" goto KILL
if "%pushkey%" == "yes" goto KILL
if "%pushkey%" == "YES" goto KILL

rem NO -> EXT

goto EXT

rem Delete for Folder and object
:KILL
for /r %%A in ( Debug ) do ( if exist "%%A" ( rmdir /s /q "%%A"))
for /r %%B in ( debug ) do ( if exist "%%B" ( rmdir /s /q "%%B"))
for /r %%C in ( Release ) do ( if exist "%%C" ( rmdir /s /q "%%C"))
for /r %%D in ( release ) do ( if exist "%%D" ( rmdir /s /q "%%D"))
for /r %%E in ( ipch ) do ( if exist "%%E" ( rmdir /s /q "%%E"))
for /r %%F in ( obj ) do ( if exist "%%F" ( rmdir /s /q "%%F"))
for /r %%G in ( *.suo ) do ( if exist "%%G" ( del /s /q "%%G"))
for /r %%H in ( *.user ) do ( if exist "%%H" ( del /s /q "%%H"))
for /r %%I in ( *.sdf ) do ( if exist "%%I" ( del /s /q "%%I"))
for /r %%J in ( *.bak ) do ( if exist "%%J" ( del /s /q "%%J"))
for /r %%K in ( *.vcproj ) do ( if exist "%%K" ( del /s /q "%%K"))
for /r %%M in ( _UpgradeReport_File ) do ( if exist "%%M" ( rmdir /s /q "%%M"))
for /r %%N in ( *.ncb ) do ( if exist "%%N" ( del /s /q "%%N"))
for /r %%L in ( *.opensdf ) do ( if exist "%%L" ( del /s /q "%%L"))
for /r %%O in ( Thumbs.db ) do ( if exist "%%O" ( del /s /q "%%O"))

goto EXT


:EXT