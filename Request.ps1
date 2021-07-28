


param($Name)
. D:\CPP\APINationalizeio\APIRequest.ps1

if(!$Name){
    $Name = "David";
}

function CountryMap{
    $Map = @{}
    Import-CSV countries.csv -Delimiter "`t" | ForEach-Object{
        $Map.add($_.ID,$_.Name);
    }; 
    return  $Map
}

$url = "https://api.nationalize.io/?name="+$Name;
# $res |WebGetRequest -url $url | Out-File test.json

$Data = @{}
$CountryID = CountryMap;

try{
    WebGetRequest -url $url | ConvertFrom-Json | ForEach-Object{
        foreach($item in $_.country){
            $Data.Add($CountryID[$item.country_id],$item.probability);
        }
    }
    
    @{"Name"=$Name;"Data"=$Data} | ConvertTo-Json | Out-File Test2.json
}

catch{
    "Error" | ConvertTo-Json | Out-File Test2.json
}

