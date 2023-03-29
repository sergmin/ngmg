r:
cd /Потапов Артём\GIT\ngmg\Potapov

git add .
set /p comm = "Write comment: "
git commit -m "%Comm%"

git pull
git checkout main


set /p Tg = "Tag: "
set /p TgD = "Tag description: "
git tag -f -a %Tg% -m "%TgD%"

git push origin --tags
git push
pause>nul