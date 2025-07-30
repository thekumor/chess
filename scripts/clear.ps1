$Files = @{
    'scripts' = $true
    'src' = $true
    'build' = $true
    'images' = $true
    '.git' = $true
    
    '.gitignore' = $true
    'LICENSE' = $true
    'README.md' = $true
    'build.bat' = $true
    'clear.bat' = $true
}

$List = Get-ChildItem -Force

foreach ($i in $List) {
    $Name = $i.Name

    if ($Files[$Name] -ne $true){
        Remove-Item $Name -Recurse -Force -Confirm:$false
    }
}