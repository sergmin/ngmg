R:
cd \Ekimov\git\ngmg\Ekimov
git add .
<<<<<<< HEAD
git commit
=======
git commit -m "comment"
>>>>>>> fb86df7f2e926a787f187accea15b04d8c4c1448
git pull

git merge
git commit -m "New bat file"
<<<<<<< HEAD
git tag -a Ekimov_tag -m "Ekimov bat"
=======
git tag -a -f Ekimov_tag_v1.0 -m "Ekimov bat version 1.0"
>>>>>>> fb86df7f2e926a787f187accea15b04d8c4c1448

git push origin --tags
git push
pause