R:
cd \Ekimov\git\ngmg\Ekimov
git add .
git commit -m "%comment%"
git pull

git merge
git commit -m "New bat file"
git tag -a Ekimov_tag -m "Ekimov bat"

git push origin --tags
git push
pause