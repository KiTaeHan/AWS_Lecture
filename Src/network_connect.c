#include "main.h"
#include "net_connect.h"
#include "network_connect.h"

#define STATE_TRANSITION_TIMEOUT        100000

extern int32_t es_wifi_driver(net_if_handle_t * pnetif);

static void hnet_notify(void *context,
						uint32_t event_class,
						uint32_t event_id,
						void  *event_data);

net_if_driver_init_func device_driver_ptr=&es_wifi_driver;

// network interface structure (link list)
net_if_handle_t netif;
// network event callback & define parameter context
const   net_event_handler_t  net_handler ={ hnet_notify, &netif };
// wifi meta-data set
net_wifi_credentials_t wifi_cred;


static int32_t set_network_credentials(net_if_handle_t *pnetif)
{
	wifi_cred.ssid = WIFI_SSID;
	wifi_cred.psk = WIFI_PASSWORD;
	wifi_cred.security_mode = WIFI_SECURE_MODE_WPA2;

	if (net_wifi_set_credentials(pnetif, &wifi_cred) != NET_OK)
	{
		return NET_ERROR_FRAMEWORK;
	}
	return NET_OK;
}

static void hnet_notify (void *context, uint32_t event_class, uint32_t event_id, void  *event_data)
{
	net_if_handle_t *netif = context;

	if(event_class == NET_EVENT_STATE_CHANGE)
	{
		net_state_t new_state= (net_state_t) event_id;

		switch(new_state)
		{
			case NET_STATE_DEINITIALIZED:
				printf("- Network Interface de-initialized\r\n");
				break;
			case NET_STATE_INITIALIZED:
				 printf("- Network Interface initialized: \r\n");
				break;
			case NET_STATE_STARTING:
				printf("- Network Interface starting: \r\n");
				break;
			case NET_STATE_STARTED:
				printf("- Network Interface started: \r\n");
				printf("   - Device Name : %s. \r\n", netif->DeviceName );
				printf("   - Device ID : %s. \r\n", netif->DeviceID );
				printf("   - Device Version : %s. \r\n", netif->DeviceVer );
				break;
			case NET_STATE_STOPPING:
				printf("- Network Interface stopping\r\n");
				break;
			case NET_STATE_STOPPED:
				printf("- Network Interface stopped\r\n");
				break;
			case NET_STATE_CONNECTING:
				printf("- Network Interface connecting: \r\n");
				break;
			case NET_STATE_CONNECTED:
				printf("- Network Interface connected: \r\n");
				printf("   - IP address :  %s. \r\n", net_ntoa(&netif->ipaddr));
				break;
			case NET_STATE_DISCONNECTING:
				printf("- Network Interface disconnecting\r\n");
				break;
			case NET_STATE_DISCONNECTED:
				printf("- Network Interface disconnected\r\n");
				break;
			case NET_STATE_LINK_LOST:
				printf("- Network Interface Link lost\r\n");
				break;
			case NET_STATE_ERROR:
				printf("- Network Interface error\r\n");
				break;

			default:
				break;
		}
	}
}

int network_init(void)
{
	if (net_if_init(&netif, device_driver_ptr, &net_handler) != NET_OK )
	{
		return NET_ERROR_FRAMEWORK;
	}
	else
	{
		if (net_if_wait_state(&netif, NET_STATE_INITIALIZED, STATE_TRANSITION_TIMEOUT) != NET_OK )
		{
			return NET_ERROR_FRAMEWORK;
		}
	}

	set_network_credentials(&netif);

	if ( net_if_start (&netif) != NET_OK )
	{
		return NET_ERROR_FRAMEWORK;
	}

	if(net_if_connect (&netif) != NET_OK)
	{
		return NET_ERROR_FRAMEWORK;
	}
	else
	{
//		uint8_t getIP[4];
//		net_ntoar(netif.ipaddr, getIP);
//		printf("IP: %d.%d.%d.%d\r\n", getIP[0],getIP[1],getIP[2],getIP[3]);
		net_if_wait_state(&netif,NET_STATE_CONNECTED,STATE_TRANSITION_TIMEOUT);
	}


	return NET_OK;
}
