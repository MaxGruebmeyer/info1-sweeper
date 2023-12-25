$proc = Start-Process -NoNewWindow -PassThru -FilePath "$env:Programfiles\Git\git-bash.exe" `
	-ArgumentList "-c", "'task build-shell; sleep 3s'"

$proc.WaitForExit()
