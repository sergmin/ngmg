@echo off

setlocal

set /p commit_message="Enter commit message: "

git add .

git commit -m "%commit_message%"

git push origin main

echo "Creating new tag: turkin_tag2"

python add_tag.py

pause
