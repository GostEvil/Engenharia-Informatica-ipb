[CmdletBinding(SupportsShouldProcess=$true)]
param(
  # Ajusta se o teu root for outro; se vazio, o script infere automaticamente
  [string]$Root = "",

  # Se quiseres escrever conteúdo no txt (por default escreve o nome da cadeira)
  [switch]$Empty
)

if ([string]::IsNullOrWhiteSpace($Root)) {
  $scriptPath = $PSCommandPath
  if (-not $scriptPath) { $scriptPath = $MyInvocation.MyCommand.Path }

  $scriptDir =
    if ($PSScriptRoot) { $PSScriptRoot }
    elseif ($scriptPath) { Split-Path -Parent $scriptPath }
    else { (Get-Location).Path }

  $Root = (Resolve-Path (Join-Path $scriptDir "..")).Path
} else {
  $Root = (Resolve-Path $Root).Path
}

$years = @("1_Ano","2_Ano","3_Ano")

$twoSemesterFolders = foreach ($y in $years) {
  $p = Join-Path $Root $y
  if (Test-Path $p) {
    Get-ChildItem -Path $p -Directory -Recurse -ErrorAction SilentlyContinue |
      Where-Object { $_.Name -eq "2_Semestre" }
  }
}

foreach ($sem in $twoSemesterFolders) {
  # Assume que cada cadeira é uma subpasta direta de 2_Semestre (ex.: 2_Semestre\AED\...)
  $chairs = Get-ChildItem -Path $sem.FullName -Directory -ErrorAction SilentlyContinue

  foreach ($c in $chairs) {
    $txtPath = Join-Path $sem.FullName ($c.Name + ".txt")
    if (-not (Test-Path $txtPath)) {
      if ($PSCmdlet.ShouldProcess($txtPath, "Create")) {
        if ($Empty) {
          New-Item -ItemType File -Path $txtPath -Force | Out-Null
        } else {
          Set-Content -Path $txtPath -Value $c.Name -Encoding UTF8
        }
      }
    }
  }
}

Write-Host "Done."
Write-Host "Root: $Root"
