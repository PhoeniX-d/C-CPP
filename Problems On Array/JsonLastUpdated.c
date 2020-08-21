// CurlApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.

#define CURL_STATICLIB
#define BLOCKSIZE       4096
#define SUCCESS            1
#define FAILURE            0

#include <curl.h>
#include <json-glib/json-glib.h>
#include <glib-object.h>
#include <json-glib/json-parser.h>
#include <glib.h>
#include <gobject/gobject.h>
#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

// global declarations
typedef struct _memory
{
	LPSTR 	lpszResponse;
	UINT	uSize;
}MEMORY, *PMEMORY;

void UnreadMsgsParser(LPCSTR lpzBuffer, UINT uSize);
static size_t UnreadCallback(void* ptr, size_t size, size_t nmemb, void* stream);
static size_t MsgCallBack(void* data, size_t size, size_t nmemb, void* userp);
void UnreadGetdata(LPCSTR lpczURL, LPCSTR lpczToken);

// entry point
int main(void)
{
    LPCSTR lpczURL = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages?q=is%3Aunread";
    LPCSTR lpczToken = "ya29.a0AfH6SMDMKg2rU2nStdopn_E6JQO5iYgUNmsheBURlS1Z5iCx5SPuaXmPcO5CAF7vXS5VUFzD80K5A9QCcRMHLGdYLDelaXft09C53Giux8PwWz_BoKnuBN3BM5pDFPF6phLoR8ljT6v7CmmUceDlrWiOPcpw_oTMLSU";
    PerformCURL(lpczURL, lpczToken);
    return 0;
}

void UnreadGetData(LPCSTR lpczURL, LPCSTR lpczToken)
{
    CURL* curl_handle;
    CHAR lpzBody[BLOCKSIZE];

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

     /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, lpczURL);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
    curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, lpczToken);

    /* send all data to this function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, UnreadCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&lpzBody);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);
}

void UnreadMsgData(LPCSTR *lpzId, guint iArrLen)
{
    //CURL* curl_handle;
    MEMORY mChunk;
	INT i = 0;
	mChunk.uSize = 0;
	mChunk.lpszResponse = NULL;
	
	LPCSTR lpczURL = "https://www.googleapis.com/gmail/v1/users/prnv24choudhary%40gmail.com/messages/";
    LPCSTR lpczToken = "ya29.a0AfH6SMAx-fjibJ1enbynIYbzYzobHDlUdC3y1RQtWx7Mfkz6sJxaxKBK3AHLo_U6dOGLuxKTw0aEoBZfD1r2fKIOtJXTec9dHKKyzXFHNVI0YPjHf9YJMtGY2pxOWVuYHdjnQjtmnbqtbcgw3LGkOFgpfVJ79HvS45s";

    //curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    //curl_handle = curl_easy_init();

	for(i = 0; i < iArrLen; i++)
	{
		strcat(lpczURL, lpzId[i]);
		cout << lpzId[i] << endl;
		/*
		/* set URL to get
		curl_easy_setopt(curl_handle, CURLOPT_URL, lpczURL);
		curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 0L);
		curl_easy_setopt(curl_handle, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
		curl_easy_setopt(curl_handle, CURLOPT_XOAUTH2_BEARER, lpczToken);

		/* send all data to this function
		curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, MsgCallBack);
		curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void*)&mChunk);

		/* get it
		curl_easy_perform(curl_handle);

		/* cleanup curl stuff
		curl_easy_cleanup(curl_handle);
		*/
	}
    
}
/* Callback function for the data getting from response body */
static size_t UnreadCallback(void* ptr, size_t size, size_t nmemb, void* stream)
{
    UnreadMsgsParser((LPCSTR)ptr, size * nmemb);
    return size * nmemb;
}

void UnreadMsgsParser(LPCSTR lpzBuffer, UINT uSize)
{
    JsonParser* parser = json_parser_new();
    JsonNode* root;
    guint i = 0, iArrLen = 0;
    LPSTR *lpzId = NULL;

    json_parser_load_from_data(parser, lpzBuffer, uSize, NULL);
    root = json_parser_get_root(parser);
    if (JSON_NODE_HOLDS_OBJECT(root))
    {
        JsonObject* object;
        object = json_node_get_object(root);
        if (json_object_has_member(object, "messages"))
        {
            JsonArray* array = json_object_get_array_member(object, "messages");
            iArrLen = json_array_get_length(array);
            lpzId = (PCHAR*)malloc(sizeof(PCHAR) * iArrLen);
            JsonObject* jobj;
            for (i = 0; i < iArrLen; i++)
            {
                lpzId[i] = (PCHAR)malloc(sizeof(CHAR) * 16);
                jobj = json_array_get_object_element(array, i);
                lpzId[i] = (LPSTR)json_object_get_string_member(jobj, "id");
                cout << lpzId[i] << endl;
            }
        }
    }

	UnreadMsgData(lpzId, iArrLen);
    g_object_unref(parser);
}
