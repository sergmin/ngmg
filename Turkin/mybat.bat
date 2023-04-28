@echo off

:: находим все существующие теги turkin_tag*
set max_tag=0
for /f "delims=" %%f in ('dir /b turkin_tag*') do (
  :: извлекаем номер тега
  set tag=%%~nf
  set tag=!tag:turkin_tag=!
  :: проверяем, является ли тег числом
  setlocal enabledelayedexpansion
  if !tag! neq !tag:nonumber=!
  (
    :: находим максимальный номер тега
    if not defined max_tag set max_tag=!tag!
    if !tag! gtr !max_tag set max_tag=!tag!
  )
  endlocal
)

:: создаем новый тег с номером max_tag+1
if %max_tag% equ 0 (
  git tag turkin_tag1
) else (
  set /a new_tag=max_tag+1
  git tag turkin_tag%new_tag%
)

:: добавляем все изменения в индекс
git add -A

:: создаём коммит
git commit -m "Added new tag"

:: отправляем изменения на удалённый сервер в ветку main
git push origin main

:: выводим сообщение
echo "New tag added"
pause
