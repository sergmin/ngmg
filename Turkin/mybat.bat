@echo off

:: Выводим текущее состояние тегов
echo Список существующих тегов:
git tag -l "turkin_tag_*"

:: Добавляем изменения
git add .

:: Запрашиваем сообщение для коммита
set /p commit_message=Введите сообщение для коммита:

:: Создаем новый коммит
git commit -m "%commit_message%"

:: Определяем номер нового тега
set "tag_num=0"
:check_tag
if exist .git\refs\tags\turkin_tag_%tag_num% (
    set /a "tag_num+=1"
    goto check_tag
)

:: Создаем новый тег
set "new_tag=turkin_tag_%tag_num%"
git tag %new_tag%
echo New tag: %new_tag%

:: Отправляем изменения на удаленный репозиторий
git push origin main

echo Change success.
