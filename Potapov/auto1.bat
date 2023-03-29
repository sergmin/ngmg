r:
cd /Потапов Артём\GIT\ngmg\Potapov
git add .
git commit
git pull

git add .
git merge

set /P Tg = "Tag: "
echo %Tg%
set /P TgD = "Tag description: "
echo %TgD%
git tag -a -f %Tg% -m "%TgD%"

git commit
git push origin --tags
git push
pause>nul