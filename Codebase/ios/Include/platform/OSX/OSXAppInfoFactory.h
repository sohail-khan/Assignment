// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include "AppInfo.h"
#import <Foundation/Foundation.h>

@class NSString;

@interface OSXAppInfoFactory : NSObject
+ (Eegeo::AppInfo)createAppInfo:(const std::string&)apiKey;
@end