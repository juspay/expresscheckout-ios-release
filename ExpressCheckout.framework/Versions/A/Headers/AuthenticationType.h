//
//  AuthenticationType.h
//  ExpressCheckout
//
//  Created by Balaganesh S on 07/11/17.
//  Copyright © 2017 Juspay Technologies Pvt Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum{
    DEFAULT_AUTHENTICATION,
    ATMPIN_AUTHENTICATION
}CardAuthenticationType;

@interface AuthenticationType : NSObject

@end
