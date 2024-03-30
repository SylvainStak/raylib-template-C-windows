Start-Process remedybg -ArgumentList "main.exe"
$currentDir = Get-Location
$mainCFullPath = Join-Path -Path $currentDir -ChildPath "main.c"
Start-Process remedybg -ArgumentList "open-file", $mainCFullPath
