// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include <string>
#include "AppInfo.h"
#import <Foundation/Foundation.h>

@class NSString;

@interface iOSAppInfoFactory : NSObject
+ (Eegeo::AppInfo)createAppInfo:(const std::string&)apiKey;
@end