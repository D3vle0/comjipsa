@ECHO off
SET LogFile=logfile.txt
set "say=call :logit "

%say% "웹페이지 차단"

GOTO :end
:logit
ECHO %~1 
echo %date% %time% - %~1 >>%logfile%
EXIT /B 0
:end