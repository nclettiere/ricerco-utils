If (-Not (Test-Path -Path './boost/boost/')) 
{
    Write-Output '';
    Write-Output '';
    Write-Output '*************************************************************';
    Write-Output '*     Extracting precompiled boost libraries and source';
    Write-Output '*     .';
    Write-Output '*     .';
    
    Expand-Archive -Path '../vendor/boost_lib.zip' -DestinationPath ../vendor;

    Write-Output '*     .';
    Write-Output '*     Done';
    Write-Output '*************************************************************';
    Write-Output '*************************************************************';
} 
Else 
{
    Write-Output '';
    Write-Output '';
    Write-Output '*************************************************************';
    Write-Output '*     Boost deps already downloaded and extracted.'; 
    Write-Output '*     If there is an error, delete the boost folder in the vendor directory and try again.'
    Write-Output '*************************************************************';
    Write-Output '*************************************************************';
    Write-Output '';
    Write-Output '';
}