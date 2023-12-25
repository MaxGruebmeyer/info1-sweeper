# Replace this with calling compile.sh?
$proc = Start-Process -NoNewWindow -PassThru -FilePath "$env:Programfiles\Git\git-bash.exe" `
	-ArgumentList "-c", "'task build-windows-git-bash; sleep 3s'"

$proc.WaitForExit()
