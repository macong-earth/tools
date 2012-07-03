1,

Add #define CURL_STATICLIB before curl.h to make it use static library

2,

Add ws2_32.lib as linker input.

Or you could add this line directly to your source file:
#pragma comment(lib, "ws2_32.lib") 

