# Replace this with calling compile.sh?
$proc = Start-Process -NoNewWindow -PassThru -FilePath "$env:Programfiles\Git\git-bash.exe" `
	-ArgumentList "-c", "'task build; sleep 3s'"

$proc.WaitForExit()
