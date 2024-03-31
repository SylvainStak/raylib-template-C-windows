Start-Process remedybg -ArgumentList "main.exe"
Start-Sleep -Milliseconds 420
$currentDir = Get-Location
$mainCFullPath = Join-Path -Path $currentDir -ChildPath "main.c"
Start-Process remedybg -ArgumentList "open-file", $mainCFullPath
