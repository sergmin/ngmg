R:
cd /Kovrigin/Git/ngmg/Kovrigin
git add .
git commit
git pull
git add .
git merge
set /P Tg="Tag: "
echo %Tg%
set /P Tgd="Tag description: "
echo %Tgd%
git tag -a -f %Tg% -m "%Tgd%"
git commit
git push origin --tags
git push
pause