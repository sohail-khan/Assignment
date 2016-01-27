if(${IOS})
set(headers ${headers} libs/ASIHttpRequest
)
set(currsources
    libs/ASIHttpRequest/ASIAuthenticationDialog.h
    libs/ASIHttpRequest/ASIAuthenticationDialog.m
    libs/ASIHttpRequest/ASICacheDelegate.h
    libs/ASIHttpRequest/ASIDataCompressor.h
    libs/ASIHttpRequest/ASIDataCompressor.m
    libs/ASIHttpRequest/ASIDataDecompressor.h
    libs/ASIHttpRequest/ASIDataDecompressor.m
    libs/ASIHttpRequest/ASIDownloadCache.h
    libs/ASIHttpRequest/ASIDownloadCache.m
    libs/ASIHttpRequest/ASIFormDataRequest.h
    libs/ASIHttpRequest/ASIFormDataRequest.m
    libs/ASIHttpRequest/ASIHTTPRequest.h
    libs/ASIHttpRequest/ASIHTTPRequest.m
    libs/ASIHttpRequest/ASIHTTPRequestConfig.h
    libs/ASIHttpRequest/ASIHTTPRequestDelegate.h
    libs/ASIHttpRequest/ASIInputStream.h
    libs/ASIHttpRequest/ASIInputStream.m
    libs/ASIHttpRequest/ASINetworkQueue.h
    libs/ASIHttpRequest/ASINetworkQueue.m
    libs/ASIHttpRequest/ASIProgressDelegate.h
    libs/ASIHttpRequest/External/Reachability/Reachability.h
    libs/ASIHttpRequest/External/Reachability/Reachability.m
)
set(sources ${sources} ${currsources})
source_group(libs/ASIHttpRequest FILES ${currsources})
endif(${IOS})