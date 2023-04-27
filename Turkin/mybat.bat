@echo off

set /p commit_message="Enter commit message: "

setlocal EnableDelayedExpansion

for /f "tokens=2 delims=_" %%a in ('git tag -l "turkin_tag*" ^| findstr /r /c:"turkin_tag_[0-9]*$" ^| sort /r') do (
    set "last_tag=%%a"
    set /a tag_number=last_tag+1
    set tag_number=!tag_number:_=!
    goto :break
)

set tag_number2=turkin_tag_!tag_number!
echo Last tag: turkin_tag_!last_tag!
echo New tag number: !tag_number2!

git add .
git commit -m "%commit_message%"
git tag -a !tag_number2! -m "Description tag"
git pull origin main
git push origin main --tags

echo "Change success."
pause
