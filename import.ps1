$Names=@()
$res = Import-CSV countries.csv -Delimiter "`t"
foreach ($item in $res) {
    $item.ID
}