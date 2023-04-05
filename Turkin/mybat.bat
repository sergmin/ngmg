@echo off

set /p commit_message="Enter message commit: "

setlocal EnableDelayedExpansion
set /a tag_number=0
for /f "delims=" %%a in ('git tag ^| findstr /r /c:"turkin_tag_[0-9]*$" ^| sort') do (
    set "last_tag=%%a"
	set /p "%last_tag%"
    set /a tag_number=!last_tag:~-1!+1
    set /p "%tag_number%"
	goto :break
)
:break
set /p "%tag_number%"
git add .
git commit -m "%commit_message%"
if !last_tag! == "" (
    git tag -a turkin_tag_0 -m "Description tag"
) else (
    git tag -a turkin_tag_%tag_number% -m "Description tag"
)
git pull origin main
git push origin main --tags

echo "Change success."
pause