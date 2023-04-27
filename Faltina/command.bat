R:
cd \Faltina\github\ngmg\Faltina
git add .
git commit -m "Commit"
git pull

git add .
git merge

set /P Tag="Tag:"
echo %Tag%
set /P Comment="CommentTag: "
echo %Comment%
git tag -a -f %Tag% -m "%Comment%"

git commit -m "Commit"
git push origin --tags
git push
pause