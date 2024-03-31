Start-Process remedybg -ArgumentList "main.exe"

# Just to make sure its actually opened before loading the source file
Start-Sleep -Milliseconds 420

$currentDir = Get-Location
$mainCFullPath = Join-Path -Path $currentDir -ChildPath "main.c"
Start-Process remedybg -ArgumentList "open-file", $mainCFullPath
