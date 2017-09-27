//
//  CardValidator.h
//  ExpressCheckout
//
//  Created by Sachin Sharma on 12/07/16.
//  Copyright © 2016 Juspay Technologies Pvt Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CardValidator : NSObject
+ (NSDictionary*)validateNumber:(NSString*)number;
@end
