r:
cd /Потапов Артём\GIT\ngmg\Potapov
git add .
git commit
git pull

git add .
git merge

set /p Tg = "Tag: "
echo %Tg%
set /p TgD = "Tag description: "
echo %TgD%
git tag -a -f %Tg% -m "%TgD%"

git push origin --tags
git push
pause>nul