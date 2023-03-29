R:
cd \Ekimov\git\ngmg\Ekimov
git add .
git commit -m "comment"
git pull

git merge
git commit -m "New bat file"
git tag -a -f Ekimov_tag_v1.0 -m "Ekimov bat version 1.0"

git push origin --tags
git push
pause