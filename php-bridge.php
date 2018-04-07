<?php
echo $_GET['type'];
if (!isset($_GET['passwd']) || $_GET['passwd']!="xxx")
    die("Not authorized");

$cmd=null;
switch (intval($_GET['type']))
{
        case 1: $cmd = 'mosquitto_pub -h localhost -p 1883 -d -t "esp/test" -u xxx -P xxx -m "ON"';
                break;
        case 0: $cmd = 'mosquitto_pub -h localhost -p 1883 -d -t "esp/test" -u xxx -P xxx  -m "OFF"';
                break;

}

if (isset($cmd))
{
        exec($cmd);
}
?>
