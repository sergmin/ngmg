FOR /F "tokens=2* skip=2" %%a in ('reg.exe query "HKLM\SOFTWARE\Microsoft\MSBuild\ToolsVersions\12.0" /v MSBuildToolsPath') do set msbuild_path=%%b

echo %msbuild_path%

echo %msbuild_path%

echo %msbuild_path%

echo %msbuild_path%

"%msbuild_path%MSBuild.exe" C:\Users\TEMP.PD.002\Desktop\dummy\dummy\dummy.vcxproj

pause