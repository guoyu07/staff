setlocal
SET STAFF_HOME=%cd%\..\..\..\deploy\win_%PROCESSOR_ARCHITECTURE%\staff
set PATH=..\..\..\..\..\rise\deploy\win_%PROCESSOR_ARCHITECTURE%\lib;%STAFF_HOME%\lib;%STAFF_HOME%\bin;%PATH%
cd src
staff_codegen -u -tclient KeyGenerator.h
endlocal
