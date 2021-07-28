function WebGetRequest{
    param($url);
    if(!$url){
        throw "URL needed"
        exit
    }

    try {
        $request = Invoke-WebRequest -URI $url -UseBasicParsing;
        return $request.Content
    }
    catch {
        throw "Failed";
        exit;
    }
}