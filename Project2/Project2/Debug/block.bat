@ECHO off
SET LogFile=logfile.txt
set "say=call :logit "

%say% "�������� ����"

GOTO :end
:logit
ECHO %~1 
echo %date% %time% - %~1 >>%logfile%
EXIT /B 0
:end