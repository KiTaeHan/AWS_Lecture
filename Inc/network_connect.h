#ifndef __NETWORK_CONNECT_H__
#define __NETWORK_CONNECT_H__

#ifdef __cplusplus
 extern "C" {
#endif

#define WIFI_SSID			"CodeZoo_2.4GHz"
#define WIFI_PASSWORD		"gamepark"

typedef enum
{
	WIFI_SECURE_MODE_OPEN,
	WIFI_SECURE_MODE_WEP,
	WIFI_SECURE_MODE_WPA,
	WIFI_SECURE_MODE_WPA2,
}net_wifi_security_mode_t;


int network_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __NETWORK_CONNECT_H__ */
