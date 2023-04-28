@echo off
setlocal enabledelayedexpansion

set prefix=turkin_tag_
set /a max_tag_number=-1

echo Searching for existing tags...

for /f "tokens=1,2 delims=_" %%i in ('git tag -l "turkin_tag_*"') do (
    if "%%j" neq "" (
        set "current_tag_number=%%j"
        set /a "current_tag_number=!current_tag_number: =!"
        if !current_tag_number! gtr !max_tag_number! set /a "max_tag_number=!current_tag_number!"
    )
)

set /a next_tag_number=max_tag_number+1
set next_tag=%prefix%!next_tag_number!

echo Creating new tag %next_tag%...

git add .
git commit -m "Auto-commit before creating new tag"
git tag %next_tag%
echo Created tag %next_tag%
git push --tags

echo Script execution complete. Press any key to exit.
pause >nul

