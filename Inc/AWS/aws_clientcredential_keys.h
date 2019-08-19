#ifndef AWS_CLIENT_CREDENTIAL_KEYS_H
#define AWS_CLIENT_CREDENTIAL_KEYS_H

#include <stdint.h>

/*
 * PEM-encoded client certificate.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyCLIENT_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDWjCCAkKgAwIBAgIVAK19xQT7ck1y5lwow7fjFDTOVSArMA0GCSqGSIb3DQEB\n"\
"CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n"\
"IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0xOTA3MTkwNTQ3\n"\
"NTJaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n"\
"dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC8WIgj6OsbGL8xAlzD\n"\
"7A7jYPnQXeeo+o5EK6fojZQTcgRih/0f6okYe/B+TTR+JOrS0l3PFRXVYPIgnvEG\n"\
"mYxr6PPDsvUEnPRDHvwC/3gKhoiZxOlNwS0rXLIO7X2mNgkM3zqR1A7wCnt9kSiH\n"\
"TlWKmzLbtSCJPcOGP4/EJGkTu2mQQUITqdkkJejVeZITF24jneU3hrRKxajJjscc\n"\
"hu4Wc6skQV1MXxI7a282ONqqeltxRC89wR6VBYDPpgR/baubXjxfmBIf6F7gulT/\n"\
"5s0e36qHs6PA0MSdSJAmkPjzFGdMoW5oirkhScGCnOXo9h56elZfhrqLqOHdaoqY\n"\
"Dn5LAgMBAAGjYDBeMB8GA1UdIwQYMBaAFC4hTNHyLnq+nwpIFQ+LT5uv6eYTMB0G\n"\
"A1UdDgQWBBTpSvNP7+Y2arBOvkH51jOhm+DYwjAMBgNVHRMBAf8EAjAAMA4GA1Ud\n"\
"DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAR20NqwfjaZBA23GLvGyaOQqc\n"\
"KwPsrDjLgJljwmLnoVUCdgJlS45pxCtny1kYCujE+xSCwlrqGR8cTsmwvMHY77j4\n"\
"eKW237JUoHTcWoTVJU+56CpnkY4c4mvX1mu5+axmIneQpyqOg+DQ3UiS4N60VN+g\n"\
"st9SeoY1Xuw7HyOepXmOqezEsGZoXk01Y11v/yoYyC8g2iM1SX5K8egjaUZ+SIz9\n"\
"BaT1R0B75aHmlMMQDSu+fHqVGTvRU3b+PsTylkExTtuUMf6H77n3F3uQ3XRd/5q+\n"\
"iidFdMCc2f0ehJYmUZ3Px2Jf3t7n83KVGBpENFD+LKVeu3h4FFujVgyFN7ejCA==\n"\
"-----END CERTIFICATE-----"

/*
 * PEM-encoded client private key.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN RSA PRIVATE KEY-----\n"\
 * "...base64 data...\n"\
 * "-----END RSA PRIVATE KEY-----"
 */
#define keyCLIENT_PRIVATE_KEY_PEM \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEowIBAAKCAQEAvFiII+jrGxi/MQJcw+wO42D50F3nqPqORCun6I2UE3IEYof9\n"\
"H+qJGHvwfk00fiTq0tJdzxUV1WDyIJ7xBpmMa+jzw7L1BJz0Qx78Av94CoaImcTp\n"\
"TcEtK1yyDu19pjYJDN86kdQO8Ap7fZEoh05Vipsy27UgiT3Dhj+PxCRpE7tpkEFC\n"\
"E6nZJCXo1XmSExduI53lN4a0SsWoyY7HHIbuFnOrJEFdTF8SO2tvNjjaqnpbcUQv\n"\
"PcEelQWAz6YEf22rm148X5gSH+he4LpU/+bNHt+qh7OjwNDEnUiQJpD48xRnTKFu\n"\
"aIq5IUnBgpzl6PYeenpWX4a6i6jh3WqKmA5+SwIDAQABAoIBAACtoO/gKtiSIj4e\n"\
"8A6UjwkqlDu32tm07UY5kgU4XUwkoPdp3fN7eLrp11fdF09M+rt/nm7ceJOoIbcU\n"\
"W3HWo7bPw/D0eAVoO0jyl527JceD7IIBP4XUKEF7t/htyoIKt8WgGCnmRZd/siol\n"\
"l6vFEHHLVUeNQ2y7GDUnjXD7YJV9mbA/3nCbs0IbjTplM/uAAfdfT7r56bbh7QOK\n"\
"ud5BPUfdVM59V53HLIv8Vu0bewJLtUxMJrTg32Z3Zhqu13jDCVNNHhGDteqFd2Cp\n"\
"Wt8xaWbrtL9hw6/XthmTjnvhbTKkJQtJ5Lnq749Cg+TSJOeS68iOwv3ln6nL09Hm\n"\
"HTMtUkECgYEA9fo4WD+Vr3dRzVZA/IrTFRpZ0ceYciRUGj+DdShEX58vMBk64EyL\n"\
"IVe7Mqsxf1J9kepvJhfyMge1Siu4Ozy66voxOsw1WEcFj668AvpbVN8ufQwQUJUr\n"\
"Ed5Ts78JraneWRA5i9TYrt5xKouorA8z3na+Gm6Wkx3aufm4FnUqX1kCgYEAxAUo\n"\
"tT47W8gnRMZYt3tCwdgmrSi5cQQfOoGl/nMO/hT5/Wgm6m2dWe++bwqWasXahBjJ\n"\
"GWMCsIXwIwazCsZ8a6c0Msnc1cyJ+Ebkyus0C2nhRCrPuZAYvl2ztfbP4xOv43X3\n"\
"DivtLu4nnAYZZ7c8cE8TgKaB/KsagSKvF538mkMCgYArGUOkGsgEbZi0rMdIOJ7R\n"\
"lMNmIV3RqhHeY4CKF5sbUg33lIQfZun91pxjPWG32GFOHtCI0StLntQiAdUO9A4g\n"\
"O+RCVCOIqzELQueIcgtsrIo9uM5nACwCvnzWAsQUXK4r1s7udEXfJfSYKs5MD4Hc\n"\
"GdwnT3csoc+ARIP/01mwSQKBgC1fjFa3uwG5yO0whGSkUYWRRRKb9KDmdVwTmprV\n"\
"g0jpDhzMOQXWra+dwRTu/HZmqfgdzJ7lvj+iIT3aVSNPYomAwKJo+4c5u04PCvK1\n"\
"kux5a71ds4uegTu/cNPT97b2XaZnLfLH1DUix2RkPQk27vSIOVl0MW6NJKtzndf3\n"\
"p/sFAoGBAJUvKKc3T+XHE5VaGfXVX9F1daiPzc0p43NvRgo8Gqr0Us2j0NISoWKW\n"\
"R8ydSDe0t974vd8Xo3XqtJffoL0b+p+W1bLbJWs1ywo69C0kbZslkbb0VnBOlSO2\n"\
"aCK4noWjELMSq9/7I7ynUudNk2hfcGHccJVGr+Bs9BFve2RPEXA+\n"\
"-----END RSA PRIVATE KEY-----"

/*
 * PEM-encoded Just-in-Time Registration (JITR) certificate (optional).
 *
 * If used, must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM  NULL

/* The constants above are set to const char * pointers defined in aws_dev_mode_key_provisioning.c,
 * and externed here for use in C files.  NOTE!  THIS IS DONE FOR CONVENIENCE
 * DURING AN EVALUATION PHASE AND IS NOT GOOD PRACTICE FOR PRODUCTION SYSTEMS
 * WHICH MUST STORE KEYS SECURELY. */
extern const char clientcredentialCLIENT_CERTIFICATE_PEM[];
extern const char* clientcredentialJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM;
extern const char clientcredentialCLIENT_PRIVATE_KEY_PEM[];
extern const uint32_t clientcredentialCLIENT_CERTIFICATE_LENGTH;
extern const uint32_t clientcredentialCLIENT_PRIVATE_KEY_LENGTH;

#endif /* AWS_CLIENT_CREDENTIAL_KEYS_H */
