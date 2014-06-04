
## Easy libcurl (works in one thread)

    h = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_URL, "http://domain.com/");
    success = curl_easy_perform(h);


### set options 

* options remain set in the handle until set again to something different.
* libcurl makes its own copy of the string options.
* if you’re using libcurl as a WIN32 DLL, you __MUST__ use the CURLOPT_WRITEFUNCTION if you set CURLOPT_WRITEDATA - or you will experience crashes.

### perform

* write callback function should return number of bytes it “took care of”. libcurl will abort the operation if the return value is not the exact same amount of bytes that was passed in.
* it is preferred to re-use an existing handle.
* don’t use handle in different threads. 

## Debug

* CURLOPT_VERBOSE
* CURLOPT_HEADER
* CURLOPT_DEBUGFUNCTION

## Upload file
* size_t function(char *bufptr, size_t size, size_t nitems, void *userp);
write data to bufptr, the max size of bufptr is size * nitems
* curl_easy_setopt(easyhandle, CURLOPT_READFUNCTION, read_function);
* curl_easy_setopt(easyhandle, CURLOPT_READDATA, &filedata);
* curl_easy_setopt(easyhandle, CURLOPT_UPLOAD, 1L);
* curl_easy_setopt(easyhandle, CURLOPT_INFILESIZE_LARGE, file_size);/* in this example, file_size must be an curl_off_t variable */  

## Posting
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postthis);
    /* if we don't provide POSTFIELDSIZE, libcurl will strlen() by itself */ 
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postthis));
    res = curl_easy_perform(curl);

### Posting file with other fields
http://www.tutorialspoint.com/html/mime_media_types.htm
http://www.faqs.org/rfcs/rfc1867.html
http://www.w3schools.com/jsref/dom_obj_fileupload.asp
http://www.ietf.org/rfc/rfc2388.txt
