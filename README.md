# simple-remote-controller-iot-device
Using MQTT and HTTP request to control nocemcu with servo

You need to have mosquitto, php and webserver installed or available.

Nodemcu device subs to mosquitto on server. After php-bridge.php gets http request with a password it execs mosquitto-command which pubs to connected nodemcu which reads the command and reacts accordingly.

