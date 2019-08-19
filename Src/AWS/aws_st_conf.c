#include <string.h>
#include "main.h"
#include "aws_st_conf.h"

#include "aws_iot_version.h"
#include "aws_iot_mqtt_client_interface.h"
#include "aws_iot_config.h"

#define MQTT_CONNECT_MAX_ATTEMPT_COUNT		3

static char cPTopicName_data[MAX_SHADOW_TOPIC_LENGTH_BYTES] = ""; /* Publish Topic */
static char cPTopicName[MAX_SHADOW_TOPIC_LENGTH_BYTES] = ""; /* Publish Topic */
static char cSTopicName[MAX_SHADOW_TOPIC_LENGTH_BYTES] = ""; /* Subscribe Topic */

const aws_client_credential_t AWSClientConf;

void aws_iot_conf_init(void)
{
	memcpy(AWSClientConf.device_name, USER_DEVICE_NAME, sizeof(USER_DEVICE_NAME));
	memcpy(AWSClientConf.server_name, USER_SERVER_NAME, sizeof(USER_SERVER_NAME));
	memcpy(AWSClientConf.tls_root_ca_cert, keyAWS_ROOT_CA_1_PEM, sizeof(keyAWS_ROOT_CA_1_PEM));
	memcpy(AWSClientConf.tls_device_cert, keyCLIENT_CERTIFICATE_PEM, sizeof(keyCLIENT_CERTIFICATE_PEM));
	memcpy(AWSClientConf.tls_device_key, keyCLIENT_PRIVATE_KEY_PEM, sizeof(keyCLIENT_PRIVATE_KEY_PEM));

	printf("thing name: %s\r\n", AWSClientConf.device_name);
	printf("server name: %s\r\n", AWSClientConf.server_name);

//	printf("AWS IoT SDK Version %d.%d.%d-%s\r\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TAG);

	/*	error
	printf("root ca: %s\r\n", AWSClientConf.tls_root_ca_cert);
	printf("device certificate: %s\r\n", AWSClientConf.tls_device_cert);
	printf("device key: %s\r\n", AWSClientConf.tls_device_key);
	*/
}

/**
* @brief MQTT disconnect callback hander
*
* @param pClient: pointer to the AWS client structure
* @param data:
* @return no return
*/
static void disconnectCallbackHandler(AWS_IoT_Client *pClient, void *data)
{
	printf("MQTT Disconnect\n");
	IoT_Error_t rc = FAILURE;

	if (NULL == data)
	{
		return;
	}

	AWS_IoT_Client *client = (AWS_IoT_Client *)data;

	if (aws_iot_is_autoreconnect_enabled(client))
	{
		printf("Auto Reconnect is enabled, Reconnecting attempt will start now\n");
	}
	else
	{
		printf("Auto Reconnect not enabled. Starting manual reconnect...\n");
		rc = aws_iot_mqtt_attempt_reconnect(client);

		if (NETWORK_RECONNECTED == rc)
		{
			printf("Manual Reconnect Successful\n");
		}
		else
		{
			printf("Manual Reconnect Failed - %d\n", rc);
		}
	}
}

void aws_iot_run(void const *arg)
{
	int connectCounter;

	IoT_Error_t rc = FAILURE;

	char const *deviceName;
	const char *serverAddress;
	const char *pCaCert;
	const char *pClientCert;
	const char *pClientPrivateKey;

	AWS_IoT_Client client;
	IoT_Client_Init_Params mqttInitParams = iotClientInitParamsDefault;
	IoT_Client_Connect_Params connectParams = iotClientConnectParamsDefault;

	deviceName = AWSClientConf.device_name;
	serverAddress = AWSClientConf.server_name;
	pCaCert	= AWSClientConf.tls_root_ca_cert;
	pClientCert = AWSClientConf.tls_device_cert;
	pClientPrivateKey = AWSClientConf.tls_device_key;

	snprintf(cPTopicName_data, sizeof(cPTopicName_data), AWS_DEVICE_SHADOW_PRE "%s" AWS_DEVICE_SHADOW_UPDATE_TOPIC, deviceName);
	snprintf(cPTopicName, sizeof(cPTopicName), AWS_DEVICE_SHADOW_PRE "%s" AWS_DEVICE_SHADOW_UPDATE_TOPIC, deviceName);
	snprintf(cSTopicName, sizeof(cSTopicName), AWS_DEVICE_SHADOW_PRE "%s" AWS_DEVICE_SHADOW_UPDATE_ACCEPTED_TOPIC, deviceName);

	printf("AWS IoT SDK Version %d.%d.%d-%s\r\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TAG);

	mqttInitParams.enableAutoReconnect = false; /* We enable this later below */
	mqttInitParams.pHostURL = (char *) serverAddress;
	mqttInitParams.port = AWS_IOT_MQTT_PORT;
	mqttInitParams.pRootCALocation = (char *) pCaCert;
	mqttInitParams.pDeviceCertLocation = (char *) pClientCert;
	mqttInitParams.pDevicePrivateKeyLocation = (char *) pClientPrivateKey;
	mqttInitParams.mqttCommandTimeout_ms = 20000;
	mqttInitParams.tlsHandshakeTimeout_ms = 5000;
	mqttInitParams.isSSLHostnameVerify = true;
	mqttInitParams.disconnectHandler = disconnectCallbackHandler;
	mqttInitParams.disconnectHandlerData = NULL;
	rc = aws_iot_mqtt_init(&client, &mqttInitParams);
	if (SUCCESS != rc)
	{
		printf("aws_iot_mqtt_init returned error : %d\n", rc);
		return;
	}

	connectParams.keepAliveIntervalInSec = 30;
	connectParams.isCleanSession = true;
	connectParams.MQTTVersion = MQTT_3_1_1;
	connectParams.pClientID = (char *) deviceName;
	connectParams.clientIDLen = (uint16_t) strlen(deviceName);
	connectParams.isWillMsgPresent = false;
	connectCounter = 0;
	do
	{
		connectCounter++;
		printf("MQTT connection in progress:   Attempt %d/%d ...\n", connectCounter, MQTT_CONNECT_MAX_ATTEMPT_COUNT);
		rc = aws_iot_mqtt_connect(&client, &connectParams);
	}
	while ((rc != SUCCESS) && (connectCounter < MQTT_CONNECT_MAX_ATTEMPT_COUNT));

	if (SUCCESS != rc)
	{
		printf("\nError(%d) connecting to %s:%d\n", rc, mqttInitParams.pHostURL, mqttInitParams.port);
		return;
	}
	else
	{
		printf("\nConnected to %s:%d\n", mqttInitParams.pHostURL, mqttInitParams.port);
	}

}
