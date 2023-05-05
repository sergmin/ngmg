cd C:\\Mariam\\MyGit\\ngmg.wiki
git pull
cd C:\\Mariam\\MyGit\\ngmg 
git pull

pandoc --pdf-engine=xelatex -V mainfont="Times New Roman" C:\\Mariam\\MyGit\\ngmg.wiki\\Спецификация.md -o C:\\Mariam\\MyGit\\ngmg\\Documents\\Спецификация.pdf
pandoc --pdf-engine=xelatex -V mainfont="Times New Roman" C:\\Mariam\\MyGit\\ngmg.wiki\\Текст-программы.md -o C:\\Mariam\\MyGit\\ngmg\\Documents\\Текст-программы.pdf
pandoc --pdf-engine=xelatex -V mainfont="Times New Roman" C:\\Mariam\\MyGit\\ngmg.wiki\\Описание-программы.md -o C:\\Mariam\\MyGit\\ngmg\\Documents\\Описание-программы.pdf
pandoc --pdf-engine=xelatex -V mainfont="Times New Roman" C:\\Mariam\\MyGit\\ngmg.wiki\\Описание-применения.md -o C:\\Mariam\\MyGit\\ngmg\\Documents\\Описание-применения.pdf
pandoc --pdf-engine=xelatex -V mainfont="Times New Roman" C:\\Mariam\\MyGit\\ngmg.wiki\\Руководство-программиста.md -o C:\\Mariam\\MyGit\\ngmg\\Documents\\Руководство-программиста.pdf

cd C:\\Mariam\\MyGit\\ngmg
git add .
git commit -m "update document"
git push